#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100'000;

int n;
int a[MX + 2], x[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i] >> x[i];
  
  ll tot = 0, pop = 0;
  for (int i = 0; i < n; i++) {
    tot += (ll)a[i] * x[i];
    pop += x[i];
  }
  
  int cand1 = tot / pop;
  int cand2 = cand1++;

  ll wv = 0;
  for (int i = 0; i < n; i++)
    wv += abs((ll)(a[i] - cand2) * x[i]);

  ll tmp = 0;
  for (int i = 0; i < n; i++)
    tmp += abs((ll)(a[i] - cand1) * x[i]);

  if (wv < tmp) cout << cand2;
  else cout << cand1;
}