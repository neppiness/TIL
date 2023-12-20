#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> check;
string keys[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    keys[i] = s;
  }

  for (int i = 0; i < n - 1; i++) {
    string s; cin >> s;
    check[s]++;
  }

  for (int i = 0; i < n; i++) {
    if (!check[keys[i]]) {
      cout << keys[i];
      return 0;
    }
    check[keys[i]]--;
  }
}
