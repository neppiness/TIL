#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  k++;

  while (k) {
    st.push(k % 2);
    k /= 2;
  }

  st.pop();
  while(!st.empty()) {
    int cur = st.top(); st.pop();
    if (cur == 0) cout << 4;
    else cout << 7;
  }
}

