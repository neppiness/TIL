#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;

int f[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  while(s[0] != '.') {
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
      while(j > 0 && s[i] != s[j]) j = f[j - 1];
      if(s[i] == s[j]) f[i] = ++j;
    }



    cin >> s;
  }
}