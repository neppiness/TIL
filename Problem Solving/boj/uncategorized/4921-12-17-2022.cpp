#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool solve(string &s) {
  cnt++;
  stack<char> st;
  if(s[0] != '1') return false;
  st.push(s[0]);

  int lidx = s.length() - 1;
  for(int i = 1; i < lidx; i++) {
    char &c = s[i];
    char p = st.top();
    if(c == '1' || c == '2') return false;
    if(c == '3')
      if(p != '4' && p != '6') return false;
    if(c == '4' || c == '5')
      if(p != '1' && p != '3') return false;
    if(c == '6' || c == '7')
      if(p != '8') return false;
    if(c == '8')
      if(p != '7' && p != '5') return false;
    st.push(c);
  }

  if(s[lidx] != '2') return false;
  if(st.top() != '4' && st.top() != '6') return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  while(s[0] != '0') {
    bool isValid = solve(s);

    string vorn;
    if(isValid) vorn = "VALID";
    else vorn = "NOT";

    cout << cnt << ". " << vorn << '\n';
    cin >> s;
  }
}