#include <bits/stdc++.h>
using namespace std;

const int MX = 10 + 2;
const int MOD = 5;

int di[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dj[] = {0, 1, 0, -1, 1, -1, 1, -1};

int n, m, yrs;
int nu[MX][MX], dnu[MX][MX];

vector<int> tr_age[MX][MX]; // tr_age[x][y] = age
vector<bool> is_alive[MX][MX];

void setup() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      sort(tr_age[i][j].begin(), tr_age[i][j].end());
      is_alive[i][j].resize(tr_age[i][j].size());
      fill(is_alive[i][j].begin(), is_alive[i][j].end(), 0);
    }
}

void spring() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < (int)tr_age[i][j].size(); k++) {
        int &age = tr_age[i][j][k];
        if(age > nu[i][j]) break;
        nu[i][j] -= age;
        is_alive[i][j][k] = 1;
        age++;
      }
}

void summer() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      int sz = tr_age[i][j].size();
      for(int k = sz - 1; k >= 0; k--) {
        if(is_alive[i][j][k]) break;
        nu[i][j] += tr_age[i][j][k] / 2;
        tr_age[i][j].pop_back();
        is_alive[i][j].pop_back();
      }
    }
}

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

void fall() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(auto age : tr_age[i][j]) {
        if(age % 5 != 0) continue;
        for(int dir = 0; dir < 8; dir++) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          if(oob(ni, nj)) continue;
          tr_age[ni][nj].push_back(1);
          is_alive[ni][nj].push_back(1);
        }
      }
}

void winter() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      nu[i][j] += dnu[i][j];
}

void one_yr_cycle() {
  setup();
  spring();
  summer();
  fall();
  winter();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> yrs;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> dnu[i][j];
      nu[i][j] = 5;
    }
  while(m--) {
    int x, y, age;
    cin >> x >> y >> age;
    tr_age[x - 1][y - 1].push_back(age);
  }

  while(yrs--) one_yr_cycle();

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(bool alive : is_alive[i][j])
        if(alive) ans++;
  cout << ans;
}