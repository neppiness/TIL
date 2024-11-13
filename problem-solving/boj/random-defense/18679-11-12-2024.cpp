#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> tr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    string t; cin >> t >> t;
    tr[s] = t;
  }
  int t; cin >> t;
  while (t--) {
    cin >> n;
    while (n--) {
      string s; cin >> s;
      cout << tr[s] << ' ';
    }
    cout << '\n';
  }
}
