#include <bits/stdc++.h>
using namespace std;

string a;

string solve(stack<char>& s) {
  for(auto c : a){
    if(c == '(') s.push(c);
    else {
      if(s.empty()) return "NO";
      else s.pop();
    }
  }
  if(s.empty()) return "YES";
  else return "NO";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  stack<char> s;

  while(t--) { 
    cin >> a;
    cout << solve(s) << '\n';
    while(!s.empty()) s.pop();
  }
}