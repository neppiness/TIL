#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[100'002];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    int st, en;
    cin >> st >> en;
    a[i] = {st, en};
  }

  sort(a, a + n);
  
  pq.push(0);
  for (int i = 0; i < n; i++) {
    auto [st, en] = a[i];
    if (pq.top() <= st) pq.pop();
    pq.push(en);
  }
  cout << pq.size();
}
