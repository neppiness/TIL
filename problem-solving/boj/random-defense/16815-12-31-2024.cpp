#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (char c : s) {
    if (c == '*') {
      cout << st.size();
      return 0;
    }
    if (c == '(') {
      st.push(c);
    } else {
      st.pop();
    }
  }
}
