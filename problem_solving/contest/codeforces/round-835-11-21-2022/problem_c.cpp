#include <bits/stdc++.h>
using namespace std;

int raw[200'002];
int sorted[200'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    fill(raw, raw + n, 0);
    fill(sorted, sorted + n, 0);

    for(int i = 0; i < n; i++) {
      cin >> raw[i];
      sorted[i] = raw[i];
    }
    sort(sorted, sorted + n);

    for(int i = 0; i < n; i++) {
      if(sorted[n - 1] == raw[i]) cout << raw[i] - sorted[n - 2] << ' ';
      else cout << raw[i] - sorted[n - 1] << ' ';
    }
    cout << '\n';
  }
}