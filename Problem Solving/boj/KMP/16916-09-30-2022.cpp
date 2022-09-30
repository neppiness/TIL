#include <bits/stdc++.h>
using namespace std;

string s, p;

bool solve(){
  vector<int> f(p.size());

  for(int i = 1; i < p.size(); i++) {
    int j = f[i-1];
    while(j > 0 && p[i] != p[j]) j = f[j-1];
    if(p[i] == p[j]) f[i] = ++j;
  }

  int j = 0;
  for(int i = 0; i < s.size(); i++){
    while(j > 0 && s[i] != p[j]) j = f[j-1];
    if(s[i] == p[j]) ++j;
    if(j == p.size()) return 1;
  }
  return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> p;
  cout << solve();
}