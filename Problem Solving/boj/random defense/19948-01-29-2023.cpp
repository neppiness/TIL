#include <bits/stdc++.h>
using namespace std;

int scnt, ccnt[26];
vector<char> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  getline(cin, str);

  cin >> scnt;
  for(int i = 0; i < 26; i++)
    cin >> ccnt[i];

  ans.push_back(str[0]);
  int idx = tolower(str[0]) - 'a';
  ccnt[idx] -= 2;
  if(ccnt[idx] < 0) { cout << -1; return 0; }

  for(int i = 1; i < str.length(); i++) {
    if(str[i - 1] == str[i]) continue;
    if(str[i] == ' ') {
      scnt--;
      if(scnt < 0) { cout << -1; return 0; }
    } else {
      int idx = tolower(str[i]) - 'a';
      if(str[i - 1] == ' ') {
        ans.push_back(str[i]);
        ccnt[idx]--;
      }
      ccnt[idx]--;
      if(ccnt[idx] < 0) { cout << -1; return 0; }
    }
  }
  for(char a : ans) cout << (char)toupper(a);
}