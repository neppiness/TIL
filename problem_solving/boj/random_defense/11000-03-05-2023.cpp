#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;
priority_queue<int, vector<int>, greater<int>> pq;

int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    int st, en; cin >> st >> en;
    a[i] = {st, en};
  }
  sort(a.begin(), a.end());

  ans = 1;
  pq.push(a[0].second);

  for(int i = 1; i < n; i++) {
    int chk = pq.top();
    auto [st, en] = a[i];
    if(chk > st) { // 가장 빨리 끝나는 강의실도 현재 확인 중인 강의 시작 시각 이후에 끝남
      pq.push(en);
      ans++;
    } else { // 가장 빨리 끝나는 강의실에 현재 확인 중인 강의를 시작할 수 있음.
      pq.pop();
      pq.push(en);
    }
  }
  cout << ans;
}