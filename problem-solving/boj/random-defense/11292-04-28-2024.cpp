#include <bits/stdc++.h>
using namespace std;

pair<string, double> a[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n != 0) {
    double mx = 0;
    for (int i = 0; i < n; i++) {
      string name; double score;
      cin >> name >> score;
      a[i] = {name, score};
      mx = max(mx, score);
    }
    for (int i = 0; i < n; i++) {
      auto [name, score] = a[i];
      if (mx == score) cout << name << ' ';
    }
    cout << '\n';
    cin >> n;
  }
}
