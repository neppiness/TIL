#include <bits/stdc++.h>
using namespace std;

int card[1'002];
int memo[10'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> card[i];

  for(int x = 1; x <= n; x++)
    for(int i = 1; i <= x; i++)
      memo[x] = max(card[i] + memo[x - i], memo[x]);
  
  cout << memo[n];
}
