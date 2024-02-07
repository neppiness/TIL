#include <bits/stdc++.h>
using namespace std;

int n, s;
bool sorted[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<int> a(n), sorted_a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sorted_a[i] = a[i];
  }
  cin >> s;

  sort(sorted_a.rbegin(), sorted_a.rend());

  int idx_to_sort = 0;
  bool all_sorted = 1;
  while(s > 0) {
    all_sorted = 1;
    for(int i = 0; i < n; i++) {
      if(sorted[i]) continue;
      int tar = sorted_a[i];
      auto taridx = find(a.begin(), a.end(), tar) - a.begin();
      int swap_cnt = taridx - idx_to_sort;
      if(swap_cnt > s) continue;
      s -= swap_cnt;
      rotate(a.begin() + idx_to_sort, a.begin() + taridx, a.begin() + taridx + 1);
      sorted[i] = 1;
      all_sorted = 0;
      idx_to_sort++;
    }
    if(all_sorted) break;
  }

  for(int i = 0; i < n; i++)
    cout << a[i] << ' ';
}