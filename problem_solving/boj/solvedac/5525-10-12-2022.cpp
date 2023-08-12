#include <bits/stdc++.h>
using namespace std;

const int MX = 2'000'002;

string s;
char p[MX];
int f[MX];

int n, m;
int plen;

void failure() {
  int j;
  for(int i = 1; i < plen; i++) {
    j = f[i - 1];
    while(j > 0 && p[i] != p[j]) j = f[j - 1];
    if(p[i] == p[j]) f[i] = ++j;
  }
}

int solve() {
  int cnt = 0;
  int j = 0;
  for(int i = 0; i < m; i++) {
    while(j > 0 && s[i] != p[j]) j = f[j - 1];
    if(s[i] == p[j]) j++;
    if(j == plen) cnt++;
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> s;

  plen = 2*n + 1;
  p[2*n] = 'I';
  for(int i = 0; i < n; i++) {
    p[2*i] = 'I';
    p[2*i + 1] = 'O';
  }

  failure();
  cout << solve();
}