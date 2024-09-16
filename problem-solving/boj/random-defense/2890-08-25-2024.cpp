#include <bits/stdc++.h>
using namespace std;

int dist[10];
set<int> d_set;

char found_no(string &s) {
  for (char c = '1'; c <= '9'; c++) {
    if (s.find(c) == -1) continue;
    return c;
  }
  return '0';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (n--) {
    string s; cin >> s;
    char fn = found_no(s);
    if (fn == '0') continue;

    int pos = s.find(fn);
    int pos_f = s.find('F');
    dist[fn - '0'] = pos_f - pos;
    d_set.insert(pos_f - pos);
  }

  int d_list[d_set.size()];
  int seq = 0;
  for (int x : d_set)
    d_list[seq++] = x;

  for (int i = 1; i <= 9; i++) {
    int dist_c = dist[i];
    int idx = lower_bound(d_list, d_list + d_set.size(), dist_c) - d_list;
    cout << idx + 1 << '\n';
  }
}
