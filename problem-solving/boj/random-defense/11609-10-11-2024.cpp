#include <bits/stdc++.h>
using namespace std;

pair<string, string> p[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string fn, ln; cin >> fn >> ln;
    p[i] = {ln, fn};
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    auto [ln, fn] = p[i];
    cout << fn << ' ' << ln << '\n';
  }
}
