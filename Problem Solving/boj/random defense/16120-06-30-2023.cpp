#include <bits/stdc++.h>
using namespace std;

bool solve() {
  stack<char> st;
  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (st.size() < 2) return 0;
      if (i + 1 == s.size()) return 0;
      if (s[i + 1] == 'A') return 0;
      st.pop(); st.pop();
      i++;
    }
    st.push(s[i]);
  }
  return (st.size() == 1 && st.top() == 'P');
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (solve()) cout << "PPAP";
  else cout << "NP";
}