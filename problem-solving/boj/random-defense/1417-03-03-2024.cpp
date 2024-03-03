#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int b[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a; cin >> a;
  for (int i = 1; i < n; i++) {
    int x; cin >> x;
    pq.push(x);
  }

  int cnt = 0;
  while (!pq.empty() && pq.top() >= a) {
    int cur = pq.top(); pq.pop();
    a++; cur--;
    cnt++;
    pq.push(cur);
  }
  cout << cnt;
}
