#include <bits/stdc++.h>
using namespace std;

pair<int, int> lec[100'002];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int no, st, en;
    cin >> no >> st >> en;
    lec[i] = {st, en};
  }
  sort(lec, lec + n);
  pq.push(-1);

  for (int i = 0; i < n; i++) {
    auto [st, en] = lec[i];
    if (pq.top() <= st) pq.pop();
    pq.push(en);
  }
  cout << pq.size();
}
