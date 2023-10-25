#include <bits/stdc++.h>
using namespace std;

int n, h, t;
priority_queue<int> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> h >> t;
  while (n--) {
    int x; cin >> x;
    pq.push(x);
  }
 
  int i = 0;
  for (; i < t; i++) {
    if (pq.top() < h || pq.top() == 1) break;
    int cur = pq.top(); pq.pop();
    cur /= 2;
    pq.push(cur);
  }
  if (pq.top() < h) {
    cout << "YES" << '\n';
    cout << i;
  } else {
    cout << "NO" << '\n';
    cout << pq.top();
  }
}
