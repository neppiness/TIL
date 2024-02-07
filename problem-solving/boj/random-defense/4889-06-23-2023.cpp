#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int seq = 1;
  cin >> s;
  while (s[0] != '-') {
    stack<char> st;
    int ans = 0;
    for (char c : s) {
      if (c == '}') {
        if (st.empty()) {
          ans++; st.push('{');
        } else st.pop();
      } else { // c == '{'
        st.push(c);
      }
    }
    ans += st.size() / 2;
    cout << seq++ << ". " << ans << '\n';
    cin >> s;
  }
}