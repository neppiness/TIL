#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int a[MX + 2], n;

void setup() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[x] = y;
  }
}

void solve() {
  stack<int> st;
  st.push(a[1]);
  for(int i = 2; i <= n; i++) {
    if(st.top() < a[i]) continue;
    st.push(a[i]);
  }
  cout << st.size() << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    setup();
    solve();
  }
}