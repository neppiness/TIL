#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MX = 1'000'000;

int cache[MX + 2], cur[MX + 2]; // last element and index of it, indexed by IS len.
int prv[MX + 2]; // previous index of ith element
int a[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(cache + 1, cache + MX + 2, INF);
  cache[0] = -INF;
  a[0] = -INF;

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    int islen = lower_bound(cache, cache + n + 1, a[i]) - cache;
    if(cache[islen] == a[i]) continue;
    cache[islen] = a[i];
    cur[islen] = i;
    prv[i] = cur[islen - 1];
  }
  int ans = lower_bound(cache, cache + n + 1, INF) - cache - 1;
  cout << ans << '\n';

  int c = cur[ans]; 
  stack<int> st;
  while(a[c] != -INF) {
    st.push(a[c]);
    c = prv[c];
  }
  while(!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
}