#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[100'002];
ll ans[100'002];
stack<int> st;

ll solve() {
  for(int i = 0; i < n; i++)
    cin >> a[i];
  fill(ans, ans + n + 1, 0);  

  for(int i = 0; i < n; i++) {
    if(!st.empty() && st.top() > a[i]) {
      while(!st.empty()) {
        ans[i - st.size()] = st.size() * a[i - st.size()];
        st.pop();
      }
    }
    st.push(a[i]);
  }

  int i = n;
  while(!st.empty()) {
    ans[i - st.size()] = (ll)st.size() * (ll)a[i - st.size()];
    st.pop();
  }

  for(int i = 0; i < n; i++) cout << ans[i] << ' ';
  ll mx1 = ans[max_element(ans, ans + n) - ans];
  ll mx2 = a[max_element(a, a + n) - a];
  return max(mx1, mx2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n) {
    cout << solve() << '\n';
    cin >> n;
  }
}