#include <bits/stdc++.h>
using namespace std;

const string PR[] = {"Bad coin denominations!", "Good coin denominations!"};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    bool is_good = 1;
    cout << "Denominations: ";
    int cur, nxt; cin >> cur;
    cout << cur << ' ';
    for (int i = 1; i < n; i++) {
      cin >> nxt;
      cout << nxt << ' ';
      if (2 * cur > nxt) is_good = 0;
      swap(cur, nxt);
    }
    cout << "\n" << PR[is_good] << "\n\n";
  }
}
