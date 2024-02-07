#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;

int f[MX]; // f[i]: Ai의 출현 빈도
int a[MX]; // a[i]: 수열의 i번째 성분 값
int ans[MX]; // ans[i]: Ai의 오등큰수

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  
  memset(ans, -1, sizeof(ans));
  stack<int> st;
  for(int i = n - 1; i >= 0; i--) {
    while(!st.empty()) {
      if(f[st.top()] > f[a[i]]) break;
      st.pop();
    }
    if(!st.empty()) ans[i] = st.top();
    st.push(a[i]);
  }
  for(int i = 0; i < n; i++)
    cout << ans[i] << ' ';
}