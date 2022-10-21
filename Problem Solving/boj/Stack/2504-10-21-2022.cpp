#include <bits/stdc++.h>
using namespace std;

int idx = 0;
bool isvalid = 1;

string s;
stack <char> st;

int brak(int lev) {
  int res = 1;
  if(s[idx] == '(' || s[idx] == '[') {
    st.push(s[idx]);
    int ft = ((s[idx] == '(') ? 2 : 3);
    res += ft*brak(lev + 1);
  } else if(s[idx] == ')') {
    if(!st.empty() && st.top() == '(') {
      st.pop();
      return res;
    } else isvalid = 0;
  } else {
    if(!st.empty() && st.top() == '[') {
      st.pop();
      return res;
    } else isvalid = 0;
  }
  idx++;
  if(idx == s.length()) return res;
}

int solve() {
  int res = 0;
  while(idx < s.length()) {
    if(s[idx] == '(' || s[idx] == '[') {
      st.push(s[idx]);
      int ft = ((s[idx] == '(') ? 2 : 3);
      res += ft*brak(0);
    }
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int ans = solve();

  if(!isvalid) ans = 0;
  cout << ans;
}