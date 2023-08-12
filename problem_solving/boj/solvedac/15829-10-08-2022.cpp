#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int r = 31, M = 1234567891;

ll solve() {
  ll ans = 0;
  for(int i = (int)s.size() - 1; i >= 0; i--) {
    ans *= r;
    ans += s[i] - 'a' + 1;
    ans %= M;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n >> s;
  cout << solve();
}