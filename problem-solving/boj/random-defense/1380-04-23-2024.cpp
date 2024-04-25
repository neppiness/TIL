#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> record;
string name[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();

  int cnt = 1;
  while (n != 0) {
    record.clear();
    for (int i = 1; i <= n; i++) {
      string s;
      getline(cin, s);
      name[i] = s;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
      int x; char c;
      cin >> x >> c;
      record[name[x]]++;
    }
    string ans;
    for (int j = 1; j <= n; j++) {
      string nm = name[j];
      if (record[nm] != 2) ans = nm;
    }
    cout << cnt << ' ' << ans << '\n';
    cnt++;
    cin >> n;
    cin.ignore();
  }
}
