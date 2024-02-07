#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = -1;
vector<string> str;
char num_set[10];
ll cnt[10];
bool not_zero[12];

int ctoi(char c) {
  return c - 'A';
}

ll calc() {
  ll ret = 0;
  for (int i = 0; i < 10; i++) 
    ret += cnt[i] * num_set[i];
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    str.push_back(s);
  }

  for (int i = 0; i < 10; i++) 
    num_set[i] = i;

  for (auto s : str) {
    ll mul10 = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      cnt[ctoi(s[i])] += mul10;
      mul10 *= 10;
    }
    not_zero[ctoi(s[0])] = 1;
  }

  do {
    auto zero_idx = min_element(num_set, num_set + 10) - num_set;
    if (not_zero[zero_idx]) continue;
    ll tot = calc();
    ans = max(ans, tot);
  } while (next_permutation(num_set, num_set + 10));
  cout << ans;
}
