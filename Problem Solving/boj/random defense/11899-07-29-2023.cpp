#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  stack<char> st;

  for (char c : s) {
    if (c == '(') {
      st.push(c);
    } else { // c == ')'
      if (!st.empty() && st.top() == '(') st.pop();
      else st.push(c);
    }
  }
  cout << st.size();
}