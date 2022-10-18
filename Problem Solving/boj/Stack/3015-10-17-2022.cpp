#include <bits/stdc++.h>
using namespace std;

int a[500'002], idx[500'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  fill(idx, idx + n, -1);

  stack<int> st;
  for(int i = n - 1; i >= 0; i--) {
    while(!st.empty()) {
      if(a[st.top()] >= a[i]) {
        idx[i] = st.top();
        break;
      }
      else st.pop();
    }
    st.push(i);
  }

  int ans = 0;
  int cur, nxt;
  for(int i = 0; i < n - 1; i++) {
    cur = i + 1;
    ans++;
    nxt = idx[cur];
    while(nxt != -1) {
      if(a[i] < a[cur] && a[i] < a[nxt]) break;
      ans++;
      swap(nxt, cur);
      nxt = idx[cur];
    }
  }
  cout << ans;
}
