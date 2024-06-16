#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  stack<int> st;
  for (char c : s) {
    st.push(c == '1');
  }

  stack<int> pr;
  int k = 0;
  int cnt = 0;
  while (!st.empty()) {
    k *= 2;
    k += st.top(); st.pop();
    cnt++;
    if (cnt == 3) {
      pr.push(k);
      cnt = 0;
      k = 0;
    }
  }
  if (k != 0) {
    pr.push(k);
  }
  while (!pr.empty()) {
    cout << pr.top(); pr.pop();
  }
}

