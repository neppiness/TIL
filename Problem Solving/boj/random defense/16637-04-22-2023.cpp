#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, sz;
ll ans = -0x7f7f7f7f7f7f;

string s;
vector<bool> comb;

ll calc(int st, int en) {
  ll res = 0, tmp = s[st] - '0';

  for(int i = st + 1; i <= en; i += 2) {
    if(s[i] == '+') {
      res += tmp;
      tmp = s[i + 1] - '0';
    } else if(s[i] == '-') {
      res += tmp;
      tmp = -(s[i + 1] - '0');
    } else {
      tmp *= s[i + 1] - '0';
    }
  }
  res += tmp;
  return res;
}

void solve(int no_of_par) {
  for(int i = 0; i < no_of_par*2; i++)
    comb[i] = 1;
  
  do {
    for(int i = 0; i < sz; i++) {
      int st, en;
      if(comb[i]) {
        st = i;
        if(i + 1 < sz && comb[i + 1]) i++;
        en = i;
      }
      calc(st, en);
    }
  } while(
      prev_permutation(comb.begin(), comb.end())
  );
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  sz = n/2 + 1;
  comb.resize(sz);

  for(int i = 0; i <= sz/2; i++)
    solve(i);

  cout << ans;
}