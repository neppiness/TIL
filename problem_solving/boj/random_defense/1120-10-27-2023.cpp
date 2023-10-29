#include <bits/stdc++.h>
using namespace std;

string a, b;

int solve(int j) {
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    cnt += (a[i] != b[i + j]);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;

  int ans = 100;
  for (int j = 0; j <= b.size() - a.size(); j++)
    ans = min(solve(j), ans);
  cout << ans;
}
