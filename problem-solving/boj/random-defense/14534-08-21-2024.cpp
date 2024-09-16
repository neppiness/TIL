#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    string s; cin >> s;
    int p[s.size()] = {};
    for (int j = 0; j < s.size(); j++)
      p[j] = j;
    cout << "Case # " << i << ":\n";
    do {
      for (int j = 0; j < s.size(); j++)
        cout << s[p[j]];
      cout << '\n';
    } while(next_permutation(p, p + s.size()));
  }
}
