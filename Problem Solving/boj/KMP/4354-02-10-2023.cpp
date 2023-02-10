#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;
int f[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; getline(cin, s);
  while(s[0] != '.') {
    int j = 0, cnt = 0;
    for(int i = 1; i < (int)s.size(); i++) {
      while(j > 0 && s[i] != s[j]) j = f[j - 1];
      if(s[i] == s[j]) f[i] = ++j;
    }
    string ss = s.substr(0, s.size() - f[s.size() - 1]);
    j = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      while(j > 0 && s[i] != ss[j]) j = f[j - 1];
      if(s[i] == ss[j]) j++;
      if(j == (int)ss.size()) {
        cnt++;
        j = f[j - 1];
      }
    }    
    cout << cnt << '\n';
    getline(cin, s);
  }
}