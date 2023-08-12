#include <bits/stdc++.h>
using namespace std;

string no; int k;
int cache[12][1'000'002];

int solve(int lv, int x) {
  int &ret = cache[lv][x];
  if (ret != -1) return ret;
  if (lv == k) return ret = x;

  string xtos = to_string(x);
  for (int i = 0; i < no.length(); i++) {
    for (int j = i + 1; j < no.length(); j++) {
      string tmp = xtos;
      if (i == 0 && tmp[j] == '0') continue;
      swap(tmp[i], tmp[j]);
      ret = max(ret, solve(lv + 1, stoi(tmp)));
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(cache, -1, sizeof(cache));

  cin >> no >> k;
  cout << solve(0, stoi(no));
}