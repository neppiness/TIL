#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int n, k, mxans;
vector<bool> comb(21);
vector<char> als, words[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    bool is_used[26] = {};
    string s; cin >> s;
    int sz = s.size();
    for(int j = 4; j < s.size() - 4; j++) {
      int idx = s[j] - 'a';
      if(is_used[idx]) continue;
      is_used[idx] = 1;
      words[i].push_back(s[j]);
    }
  }
  if(k < 5) { cout << 0; return 0; }
  k -= 5;

  for(int i = 21 - k; i < 21; i++)
    comb[i] = 1;

  // alphabet setting: except a n t i c
  for(char al = 'b'; al <= 'z'; al++) {
    if(al == 'c' || al == 'n' || al == 't' || al == 'i') continue;
    als.push_back(al);
  }

  do {
    int ans = 0;
    bool is_picked[26] = {};
    for(int i = 0; i < 21; i++) {
      if(!comb[i]) continue;
      is_picked[als[i] - 'a'] = 1;
    }
    for(int i = 0; i < n; i++) {
      bool is_valid = 1;
      for(char c : words[i]) {
        if(c == 'a' || c == 'c' || c == 'n' || c == 't' || c == 'i') continue;
        if(!is_picked[c - 'a']) { is_valid = 0; break; }
      }
      if(is_valid) ans++;
    }
    mxans = max(mxans, ans);
  } while(next_permutation(comb.begin(), comb.end()));
  cout << mxans;
}