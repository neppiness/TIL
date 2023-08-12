#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n;

  while(n--) {
    cin >> x;
    if(x == 0) {
      if(pq.empty()) cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else pq.push(x);
  }
}