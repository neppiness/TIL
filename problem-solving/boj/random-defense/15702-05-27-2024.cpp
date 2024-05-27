#include <bits/stdc++.h>
using namespace std;

int sc[102];
vector<pair<int, int>> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> sc[i];
  
  int mx = 0;
  while (m--) {
    int x; cin >> x;
    int tot = 0;
    for (int i = 0; i < n; i++) {
      char ans; cin >> ans;
      if (ans == 'X') continue;
      tot += sc[i];
    }
    mx = max(mx, tot);
    st.push_back({x, tot});
  }
  sort(st.begin(), st.end());
  for (auto [no, tot] : st) {
    if (tot != mx) continue;
    cout << no << ' ' << tot;
    return 0;
  }
}
