#include <bits/stdc++.h>
using namespace std;

enum Type { MN, MX };

const int INF = 0x3f3f3f3f;

int mn[3], mx[3], b[3];
int dj[] = {-1, 0, 1};

bool oob(int j) { return (j >= 3 || j < 0); }

void solve(Type CODE) {
  int temp[3];
  if(CODE == MN) fill(temp, temp + 3, INF);
  else fill(temp, temp + 3, 0);

  for(int cj = 0; cj < 3; cj++) {
    for(int dir = 0; dir < 3; dir++) {
      int nj = cj + dj[dir];
      if(oob(nj)) continue; 
      if(CODE == MN) temp[nj] = min(mn[cj] + b[nj], temp[nj]);
      else temp[nj] = max(mx[cj] + b[nj], temp[nj]);
    }
  }
  for(int i = 0; i < 3; i++) {
    if(CODE == MN) mn[i] = temp[i];
    else mx[i] = temp[i];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for(int j = 0; j < 3; j++) {
    int x; cin >> x;
    mn[j] = mx[j] = x;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < 3; j++)
      cin >> b[j];
    solve(MX);
    solve(MN);
  }

  int ansmx = 0, ansmn = INF;
  for(int i = 0; i < 3; i++) {
    ansmx = max(ansmx, mx[i]);
    ansmn = min(ansmn, mn[i]);
  }
  cout << ansmx << ' ' << ansmn;
}