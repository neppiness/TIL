#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  stack<bool> st;

  while (n) {
    st.push(n % 2);
    n /= 2;
  }

  long long ans = 0;
  while (!st.empty()) {
    ans *= 3;
    bool chk = st.top(); st.pop();
    if (chk) ans++;
  }
  cout << ans;
}
