#include <bits/stdc++.h>
using namespace std;

const int MX = 10 + 2;

int n, m, k;
int nu[MX][MX];
vector<int> tr_age[MX][MX]; // tr_age[x][y] = age
vector<bool> is_dead[MX][MX];

void one_yr_cycle() {
  spring();
  summer();
  fall();
  winter();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> nu[i][j];
  while(m--) {
    int x, y, age;
    cin >> x >> y >> age;
    tr_age[x][y].push_back(age);
  }

  while(k--) one_yr_cycle();

  int ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(bool dead : is_dead[i][j])
        if(!dead) ans++;
}