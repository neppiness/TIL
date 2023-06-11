#include <bits/stdc++.h>
using namespace std;

int len[1'000'002];
int ans = -1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> len[i];
  
  sort(len, len + n);

  int x = 2;
  for (; x < n; x++) {
    if (len[x] >= len[x - 1] + len[x - 2]) continue;
    ans = len[x] + len[x - 1] + len[x - 2];
  }
  cout << ans;
}