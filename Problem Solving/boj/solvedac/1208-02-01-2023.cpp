#include <bits/stdc++.h>
using namespace std;

const int MX = 40;

int n, s, ans;
int a[MX + 2], ps[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 1; i <= n; i++)
    ps[i] += a[i - 1] + ps[i - 1];
  
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < i; j++)
      if(ps[i] - ps[j] == s) ans++;

  cout << ans;
}