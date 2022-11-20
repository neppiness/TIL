#include <bits/stdc++.h>
using namespace std;

int t;
bool isUsed[72];

void chk(int n, int s) {
  for(int i = 1; i <= n; i++)
    if(!isUsed[i]) s -= i;

  if(s == 0) cout << "YES\n";
  else cout << "NO\n";
}

void solve() {
  int m, s;
  int minus = 0;
  fill(isUsed, isUsed + 72, 0);

  cin >> m >> s;

  int x;
  while(m--) {
    cin >> x;
    isUsed[x] = 1;
    minus += x;
  }

  int n = 1;
  int sumToN;
  do {
    sumToN = n*(n + 1)/2;
    if(sumToN - minus == s) {
      chk(n, s);
      return;
    }
    n++;
  } while(s > sumToN - minus);
  cout << "NO\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) solve();
}