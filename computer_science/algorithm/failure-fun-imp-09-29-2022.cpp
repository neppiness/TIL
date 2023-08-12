#include <bits/stdc++.h>
using namespace std;

int f[11];
string s;

void fail_fun(int x, int y){
  if(y < 0) return;
  if(s[x] == s[f[y]]) f[x] = f[y] + 1;
  else fail_fun(x, f[y] - 1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  s = "ABABCABABA";
  f[0] = 0;
  for(int i = 1; i < s.size(); i++) fail_fun(i, i - 1);
  for(int i = 0; i < s.size(); i++) cout << f[i] << ' ';
}