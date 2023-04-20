#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> ans(10, 0);

vector<int> solve(int st, int en, bool cntzero) {
  vector<int> a(10, 0), b(10, 1), tmp;

  ll unit = 10;
  if(en < unit) {
    for(; st <= en; st++) a[st]++;
    return a;
  }

  while(unit * 10 < en) unit *= 10;

  for(int no = 0; no < 10; no++) {
    ll lt = no * unit;
    if(en < lt) break;
    ll rt = min((no + 1) * unit - 1, (ll)en);

    if(cntzero || no != 0)
      a[no] += b[no] * (rt - lt + 1);
    tmp = solve(0, rt - lt, cntzero);
    for(int i = 0; i < 10; i++) 
      a[i] += tmp[i];
    cntzero = 1;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ans = solve(0, n, 0);
  ans[0]--;

  for(int i = 0; i < 10; i++)
    cout << ans[i] << ' ';
}