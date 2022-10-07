#include <bits/stdc++.h>
using namespace std;

int no, x, t;
string p, nlist;
deque<int> dq;

void solve() {
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
      if(dq.empty()) {
        cout << "error\n";
        return;
      }
      else if(isreversed) dq.pop_back();
      else dq.pop_front();
    }
  }
  cout << "[";
  if(!isreversed) {
    while(!dq.empty()) {
      cout << dq.front();
      dq.pop_front();
      if(!dq.empty()) cout << ",";
    }
  } else {
    while(!dq.empty()) {
      cout << dq.back();
      dq.pop_back();
      if(!dq.empty()) cout << ",";
    }
  }
  cout << "]\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--) solve();
}