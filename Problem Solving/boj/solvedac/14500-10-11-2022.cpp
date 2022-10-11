#include <bits/stdc++.h>
using namespace std;

bool vis[502][502];
int b[502][502];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool tetx[4][5];
bool tety[4][5];

int mx, sum;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      sum = 0;
      solve(i, j, 1);
      vis[i][j] = 1;
    }

  cout << mx;
}