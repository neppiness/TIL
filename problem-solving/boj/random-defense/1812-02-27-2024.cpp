#include <bits/stdc++.h>
using namespace std;

int s[1002];
int a[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i];

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += s[i];
  }

  sum /= 2; // 1항부터 N까지 합
  a[1] = sum;

  for (int i = 2; i <= n; i += 2)
    a[1] -= s[i];
  for (int i = 2; i <= n; i++)
    a[i] = s[i - 1] - a[i - 1];

  for (int i = 1; i <= n; i++)
    cout << a[i] << '\n';
}
