#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int ctoi(char c) { return c - 'A'; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for(auto c : s)
    cnt[ctoi(c)]++;

  int odd_cnt = 0;
  char odd_al;
  for(char c = 'A'; c <= 'Z'; c++) {
    if(cnt[ctoi(c)] % 2 == 0) continue;
    odd_cnt++; odd_al = c;
  }

  if(odd_cnt > 1) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }

  if(odd_cnt) cnt[ctoi(odd_al)]--;

  for(char c = 'A'; c <= 'Z'; c++) {
    int x = cnt[ctoi(c)] / 2;
    while(cnt[ctoi(c)] != x) {
      cout << c;
      cnt[ctoi(c)]--;
    }
  }

  if(odd_cnt) cout << odd_al;

  for(char c = 'Z'; c >= 'A'; c--) {
    while(cnt[ctoi(c)] != 0) {
      cout << c;
      cnt[ctoi(c)]--;
    }
  }
}