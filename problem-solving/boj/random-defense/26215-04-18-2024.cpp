#include <bits/stdc++.h>
using namespace std;

int ans = 0;
priority_queue<int> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    pq.push(x);
  }
  
  while (++ans <= 1440) {
    int a = pq.top(); pq.pop();
    a--;
    if (!pq.empty()) {
      int b = pq.top(); pq.pop();
      b--;
      if (b != 0) pq.push(b);
    }
    if (a != 0) pq.push(a);
    if (pq.empty()) {
      cout << ans;
      return 0;
    }
  }
  // ans이 1440을 넘은 경우 -1을 출력
  cout << -1;
}
