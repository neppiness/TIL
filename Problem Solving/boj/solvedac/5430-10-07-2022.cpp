#include <bits/stdc++.h>
using namespace std;

int no, x, t;
string p, nlist;
deque<int> dq;

string solve() {
  bool isreversed = 0;
  x = 0;
  
  cin >> p >> no >> nlist;
  for(char c : nlist) {
    if(c == ',' || c == ']') {
      if(!x) continue;
      dq.push_back(x);
      x = 0;
      continue;
    } else if(c >= '0' && c <= '9') {
      x *= 10;
      x += c - '0';
    }
  }
  for(char c : p) {
    if(c == 'R') isreversed = !isreversed;
    else if(c == 'D') {
      if(dq.empty()) return "error\n";
      else if(isreversed) dq.pop_back();
      else dq.pop_front();
    }
  }
  string ans = "[";
  if(!isreversed) {
    while(!dq.empty()) {
      ans = ans + to_string(dq.front());
      dq.pop_front();
      if(!dq.empty()) ans += ",";
    }
  } else {
    while(!dq.empty()) {
      ans = ans + to_string(dq.back());
      dq.pop_back();
      if(!dq.empty()) ans += ",";
    }
  }
  ans += "]\n";
  if (ans == "[]\n") ans = "error\n";
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) cout << solve();
}