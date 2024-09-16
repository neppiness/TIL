#include <bits/stdc++.h>
using namespace std;

set<int> note;
int a[52], b[52], c[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    note.clear();
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int m; cin >> m;
    for (int i = 0; i < m; i++)
      cin >> b[i];

    int p; cin >> p;
    for (int i = 0; i < p; i++)
      cin >> c[i];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < p; k++) {
          bool is_five_or_eight = 1;
          int tot = a[i] + b[j] + c[k];
          string s = to_string(tot);
          for (char &c : s) {
            if (c == '5' || c == '8')
              continue;
            is_five_or_eight = 0;
          }
          if (is_five_or_eight) note.insert(tot);
        }
      }
    }
    cout << note.size() << '\n';
  }
}
