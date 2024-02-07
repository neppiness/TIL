#include <bits/stdc++.h>
using namespace std;

string lck, key, subkey;
int keysz, lcksz;

vector<int> ffn(string &s) {
  vector<int> f(s.size());
  int j = 0; 
  for(int i = 1; i < s.size(); i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;
  keysz = key.size();
  lcksz = lck.size();

  int ans = 0;

  for(int len = keysz; len >= 1; len--) {
    subkey = key.substr(keysz - len, len);
    vector<int> subkey_ffn = ffn(subkey);

    int j = 0;
    for(int i = 0; i < lcksz; i++) {
      while(j > 0 && lck[i] != subkey[j]) j = subkey_ffn[j - 1];
      if(lck[i] == subkey[j]) j++;
      ans = max(j, ans);
      if(j == len) break;
    }
  }
  cout << ans;
}