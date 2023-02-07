#include <bits/stdc++.h>
using namespace std;

stack<char> st;

void stpr() { while(!st.empty()) { cout << st.top(); st.pop(); } }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; getline(cin, s);

  bool br = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '<') {
      br = 1;
      stpr();
    }
    if(br) {
      if(s[i] == '>') br = 0;
      cout << s[i]; continue;
    }
    if(s[i] == ' ') {
      stpr(); cout << s[i];
      continue;
    }
    st.push(s[i]);
  }
  stpr();
}