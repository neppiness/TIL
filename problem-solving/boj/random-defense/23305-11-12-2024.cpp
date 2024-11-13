#include <bits/stdc++.h>
using namespace std;

int note[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    note[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    note[x]--;
  }

  int ans = 0;
  for (int i = 1; i <= 1'000'000; i++) {
    ans += abs(note[i]);
  }
  cout << ans / 2;
}
