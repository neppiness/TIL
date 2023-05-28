#include <bits/stdc++.h>
using namespace std;

const int mod = 1'000'000'007;
int cache[102][10][5];

int solve(int lv, int no, int inc) {
  if (lv == 0) { return 1; }
  int &ret = cache[lv][no][inc];
  if (ret != -1) return ret;
  
  ret = 0;
  if (no != 0 && inc != 0) {
    if (inc < 2) ret += solve(lv - 1, no - 1, inc - 1);
    else ret += solve(lv - 1, no - 1, 1);
    if (ret > mod) ret -= mod;
  }
  if (no != 9 && inc != 4) {
    if (inc > 2) ret += solve(lv - 1, no + 1, inc + 1);
    else ret += solve(lv - 1, no + 1, 3);
    if (ret > mod) ret -= mod;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  memset(cache, -1, sizeof(cache));

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += solve(n - 1, i, 2);
    if (sum > mod) sum -= mod;
  }
  cout << sum;
}