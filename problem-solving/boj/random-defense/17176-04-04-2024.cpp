#include <bits/stdc++.h>
using namespace std;

int note[55];

int getIndex(char c) {
  if (c >= 'a' && c <= 'z') return c - 'a' + 27;
  if (c >= 'A' && c <= 'Z') return c - 'A' + 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    note[x]++;
  }

  cin.ignore();

  string s;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    int x = getIndex(s[i]);
    note[x]--;
    if (note[x] < 0) {
      cout << "n";
      return 0;
    }
  }
  cout << "y";
}
