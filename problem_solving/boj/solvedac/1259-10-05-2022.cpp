#include <bits/stdc++.h>
using namespace std;

string s;

string solve() {
  int i = 0;
  int j = s.size() - 1;
  while(j > i) {
    if(s[i] != s[j]) return "no";
    j--; i++;
  }
  return "yes";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    cin >> s;
    if(s == "0") break;
    cout << solve() << '\n';
  }
}