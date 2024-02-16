#include <bits/stdc++.h>
using namespace std;

int pen[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  int req = m * k;
  for (int i = 0; i < n; i++)
    cin >> pen[i];
  sort(pen, pen + n, greater<int>());

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += pen[i];
    if (sum < req) continue;
    cout << i + 1;
    return 0;
  }
  cout << "STRESS";
}
