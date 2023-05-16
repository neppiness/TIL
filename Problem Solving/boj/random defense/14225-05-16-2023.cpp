#include <bits/stdc++.h>
using namespace std;

int n, x[22];
set<int> s;

void solve(int lv, int st, int sum) {
  if (lv == 0) { s.insert(sum); return; }
  for (int i = st; i < n; i++)
    solve(lv - 1, i + 1, sum + x[i]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  
  for (int len = 1; len <= n; len++)
    solve(len, 0, 0);
  
  int no = 1;
  while(1) {
    auto it = s.find(no);
    if(it != s.end()) {
      no++; continue;
    }
    cout << no;
    return 0;
  }
}