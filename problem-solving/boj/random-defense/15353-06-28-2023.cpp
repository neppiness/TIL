#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int aidx = a.size() - 1;
  int bidx = b.size() - 1;

  if (bidx > aidx) { swap(a, b); swap(aidx, bidx); }

  string ans = "";
  int val = 0;
  while (bidx >= 0) {
    val += a[aidx--] - '0';
    val += b[bidx--] - '0';
    ans = (char)(val % 10 + '0') + ans;
    val /= 10;
  }

  while (aidx >= 0) {
    val += a[aidx--] - '0';
    ans = (char)(val % 10 + '0') + ans;
    val /= 10;
  }

  if (val % 10) ans = (char)(val % 10 + '0') + ans;
  cout << ans;
}