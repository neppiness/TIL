#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cache[66][10];

// n자리 수를 선택할 때, (10^idx)자리수가 no이면 이후에 얻을 수 있는 단조증가 수의 개수
ll calc(int idx, int no) {
  ll &ret = cache[idx][no];
  if (ret != -1) return ret;
  if (idx == 0) return ret = 1;

  ret = 0;
  for (int i = no; i < 10; i++)
    ret += calc(idx - 1, i);
  return ret;
}

ll solve(int n) {
  ll ans = 0;
  for (int i = 0; i < 10; i++)
    ans += calc(n - 1, i);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    ll ans = solve(n);
    cout << ans << '\n';
  }
}