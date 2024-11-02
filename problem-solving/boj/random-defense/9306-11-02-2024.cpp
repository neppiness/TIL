#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    string s1, s2; cin >> s1 >> s2;
    cout << "Case " << i << ": " << s2 << ", " << s1 << '\n';
  }
}
