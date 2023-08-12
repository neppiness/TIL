#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  bool iszero = 0;
  int sum = 0;
  for(char c : s) {
    if(c == '0') iszero = 1;
    sum += c - '0';
  }

  vector<char> ch;
  if(iszero && (sum % 3 == 0)) {
    for(char c : s)
      ch.push_back(c);
    sort(ch.rbegin(), ch.rend());
    for(char c : ch)
      cout << c;
  } else cout << -1;
}
