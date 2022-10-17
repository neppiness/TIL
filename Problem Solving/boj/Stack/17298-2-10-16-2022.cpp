#include <bits/stdc++.h>
using namespace std;

int a[1'000'002];
int ans[1'000'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  fill(ans, ans + n, -1);
  stack<int> st;
  for(int i = n - 1; i >= 0; i--) {
    while(!st.empty()) {
      if(a[i] >= st.top()) st.pop();
      else {
        ans[i] = st.top();
        st.push(a[i]);
        break;
      }
    }
    if(st.empty()) st.push(a[i]);
  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << ' ';
}