#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> m >> n;
  tuple<int, int, char> input[1002];
  for (int i = 0; i < n; i++) {
    int a, b; char c;
    cin >> a >> b >> c;
    input[i] = {b, a, c};
  }
  sort(input, input + n);
  for (int i = 0; i < n; i++) {
    auto [a, b, c] = input[i];
    cout << c;
  }
}
