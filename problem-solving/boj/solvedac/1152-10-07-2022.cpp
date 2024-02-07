#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int cnt = 0;
  getline(cin, s);
  bool onchar = 0;
  for(char c : s) {
    if(c != ' ' && !onchar) {
      cnt++;
      onchar = 1;
    }
    if(c == ' ') onchar = 0;
  }
  cout << cnt;
}