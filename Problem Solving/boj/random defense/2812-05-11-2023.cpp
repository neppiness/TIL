#include <bits/stdc++.h>
using namespace std;

string no;
int n, k;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> no;
  
  int pos = 0, nxt_pos = 0;
  while (k) {
    char c;
    for (c = '9'; c >= '0'; c--) {
      nxt_pos = no.find(c, pos);
      if (nxt_pos == -1) continue;
      if (nxt_pos - pos > k) continue;
      break;
    }
    cout << c;
    k -= nxt_pos - pos;
    pos = nxt_pos + 1;
    if (pos >= no.size() - k) break;
  }
  for (; pos < no.size() - k; pos++)
    cout << no[pos];
}