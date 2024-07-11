#include <bits/stdc++.h>
using namespace std;

int a[202][3];
unordered_map<int, int> cnt[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int x; cin >> x;
      a[i][j] = x;
      cnt[j][x]++;
    }
  }

  for (int i = 0; i < n; i++) {
    int tot = 0;
    for (int j = 0; j < 3; j++) {
      int x = a[i][j];
      if (cnt[j][x] == 1) tot += x; 
    }
    cout << tot << '\n';
  }
}
