#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;

int n, mx, mxst;
int b[1002], dp[1002];
int prv[1002];

void solve(int st) {
  for(int i = st + 1; i < n; i++)
    if(b[i] > b[st] && dp[i] < dp[st] + 1) {
      dp[i] = dp[st] + 1;
      prv[i] = st;
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> b[i];
  
  fill(prv, prv + MX, -1);
  fill(dp, dp + MX, 1);

  for(int i = 0; i < n; i++)
    solve(i);

  int midx = max_element(dp, dp + n) - dp;
  cout << dp[midx] << '\n';

  int idx = midx;
  stack<int> st;
  while(idx != -1) {
    st.push(b[idx]);
    idx = prv[idx];
  }

  while(!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
}
