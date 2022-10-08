#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, m, bl;
int board[502][502];
int b[502][502];
vector<pair<int, int>> ans; //  time, lev

pair<int, int> solve(int lev) {
  int B = bl, t = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i][j] = board[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      if(b[i][j] < lev) {
        while(b[i][j] != lev) {
          b[i][j]++;
          B--;
          t++;
        }
      } else {
        while(b[i][j] != lev) {
          b[i][j]--;
          B++;
          t = t + 2;
        }
      }
    }

  if (B < 0) t = INF;
  return {t, lev};
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> bl;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];

  for(int i = 0; i <= 256; i++)
    ans.push_back(solve(i));

  sort(ans.begin(), ans.end());

  int t, lev;
  tie(t, lev) = *(ans.begin());
  for(auto a : ans) {
    if(a.first > t) break;
    else if(a.second > lev) lev = a.second;
  }
  cout << t << ' ' << lev;
}