#include <bits/stdc++.h>
using namespace std;

int a[1'000'002];
int mx = 1'111'111;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  int en = 0;
  int cnt = 0;
  for (int st = 0; st < n; st++) {
    while (cnt != k && en < n)
      if (a[en++] == 1) cnt++;
    if (cnt == k) mx = min(mx, en - st);
    if (a[st] == 1) cnt--;
  }
  if (mx == 1'111'111) mx = -1;
  cout << mx;
}