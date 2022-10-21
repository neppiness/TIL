#include <bits/stdc++.h>
using namespace std;

int idx = 0;
bool isvalid = 1;

string s;
stack <char> st;

int brk() {
  int res = 0;
  while(isvalid && idx < s.length()) {
    if(s[idx] == '(' || s[idx] == '[') {
      st.push(s[idx]);
      int ft = ((s[idx] == '(') ? 2 : 3);
      idx++;
      res += ft*brk();
    } else if(s[idx] == ')') {
      idx++;
      if(!st.empty() && st.top() == '(') {
        st.pop();
        if(!res) res = 1;
      } else isvalid = 0;
      return res;
    } else {
      idx++;
      if(!st.empty() && st.top() == '[') {
        st.pop();
        if(!res) res = 1;
      } else isvalid = 0;
      return res;
    }
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int ans = brk();
  if(!isvalid || !st.empty()) ans = 0;
  cout << ans;
}