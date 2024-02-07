#include <bits/stdc++.h>
using namespace std;

int idx[5];
string s[5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++)
    cin >> s[i];
  
  bool all_printed;
  do {
    all_printed = 1;
    for(int i = 0; i < 5; i++) {
      if(idx[i] == s[i].size()) continue;
      cout << s[i][idx[i]];
      idx[i]++;
      all_printed = 0;
    }
  } while(!all_printed);
}