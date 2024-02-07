#include <bits/stdc++.h>
using namespace std;

int n;
int dp[102];
int nxt[102]; // 다음 인덱스를 기록

// b = {밑면 넓이, 무게, 높이, 번호}
vector<tuple<int, int, int, int>> b;
queue<int> q;

int solve(int idx) {
  int &ret = dp[idx];
  if (ret != -1) return ret;
  
  auto [a, w, h, no] = b[idx]; 
  ret = h;
  for (int i = idx + 1; i < n; i++) {
    auto [na, nw, nh, nno] = b[i];
    if (w > nw) continue;
    if (ret >= h + solve(i)) continue;
    ret = h + solve(i); 
    nxt[idx] = i;
  }
  return ret;
}

void tr(int cur) {
  // b의 인덱스를 기억하고 있기 때문에, 꺼내서 확인해야 함.
  // 큐나 스택에 넣고 나와서 마지막에 크기 출력 및 값 출력을 하는 게 나아보임.
  auto [a, w, h, no] = b[cur]; 
  q.push(no);
  if (nxt[cur] != -1) tr(nxt[cur]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(nxt, -1, sizeof(nxt));
  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, h, w; cin >> a >> h >> w;
    b.push_back({a, w, h, i}); 
  }
  sort(b.begin(), b.end());  
  
  int ans = 0;
  int st = -1;
  // 풀이 로직
  for (int i = 0; i < n; i++) {
    if (ans >= solve(i)) continue;
    ans = solve(i);
    st = i;
  } 
  // 복원 로직
  tr(st);
  cout << q.size() << '\n';
  while (!q.empty()) {
    cout << q.front() << '\n';
    q.pop();
  }
}
