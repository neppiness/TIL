#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int no[80002];
int sum;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  stack<int> st1;
  stack<pair<int, int>> st2;
  int x;
  while(n--) {
    cin >> x;
    st1.push(x);
  }

  int cur, nxt;
  int no;
  long long ans = 0;
  st2.push({INF, 0});
  while(!st1.empty()) {
    int cnt = 0;
    tie(cur, no) = st2.top();
    nxt = st1.top(); st1.pop();
    if(nxt > cur) {
      while(nxt > cur) {
        st2.pop();
        cnt++;
        cnt += no;
        tie(cur, no) = st2.top();
      }
      st2.push({nxt, cnt});
      ans += cnt;
      cnt = 0;
    } else {
      st2.push({nxt, cnt});
    }
  }
  cout << ans;
}