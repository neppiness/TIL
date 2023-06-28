#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[100'002], p[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = a[i];
    p[i] += p[i - 1];
  }

  // 벌의 출발지가 양 끝인 경우(1, n)
  // 벌통 위치 i를 2에서부터 n - 1까지 옮기면서 값을 구함
  for (int i = 2; i < n; i++) {
    int tot = (a[i] - a[1]) + (p[n - 1]);
    ans = max(ans, tot);
  }

  // 벌통의 위치가 1인 경우, 벌의 출발지 하나는 n이며
  // 다른 출발지 하나를 고르면서 값을 계산해야 함.
  for (int i = 2; i < n; i++) {
    int tot = (p[n - 1] - a[i]) + p[i - 1];
    ans = max(ans, tot);
  }

  // 벌통의 위치가 n인 경우, 벌의 출발지 하나는 1이며
  // 다른 출발지 하나를 고르면서 값을 계산해야 함.
  for (int i = 2; i < n; i++) {
    int tot = (p[n] - p[1] - a[i]) + (p[n] - p[i + 1]);
    ans = max(ans, tot);
  }
  cout << ans;
}