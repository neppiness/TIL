#include <bits/stdc++.h>
using namespace std;

int n, a[52], sorted_a[52], s;
bool is_moved_a[52], is_set_sa[52];

int find(int x) {
  for (int i = 0; i < n; i++)
    if (a[i] == x) return i;
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = sorted_a[i] = x;
  }
  cin >> s;
  sort(sorted_a, sorted_a + n, greater<int>());

  int tar = 0;
  while (s) {
    bool is_set = 0;
    for (int i = 0; i < n; i++) {
      while (is_set_sa[i]) continue;
      is_set = 1;
      int dist = 0;
      int idx = find(sorted_a[i]);
      for (int j = 0; j <= idx; j++) {
        if (is_moved_a[j]) continue;
        dist++;
      }
      if (s - dist < 0) continue;
      s -= dist;
      is_set_sa[i] = 1;
      is_moved_a[idx] = 1;
      break;
    }
    if (!is_set) break;
  }
  for (int i = 0; i < n; i++) {
    if (is_moved_a[i]) cout << sorted_a[i] << ' ';
    else cout << a[i] << ' ';
  }
}