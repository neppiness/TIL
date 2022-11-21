#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  string s;
  int a;
  while(t--) {
    cin >> a >> s;

    int mx = 0;
    for(char c : s)
      mx = max(mx, (int)c - 'a' + 1);
    cout << mx << '\n';
  }
}