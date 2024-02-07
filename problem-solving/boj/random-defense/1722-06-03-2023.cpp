#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_used[22];
int n, code, a[22];
ll seq, f;

ll fact(int x) {
  if (x == 0 || x == 1) return 1;
  return x * fact(x - 1);
}

void SeqPrint() {
  cin >> seq;
  f = fact(n);
  int x = n;
  while (x) {
    f /= x;
    for (int i = 1; i <= n; i++) {
      if (is_used[i]) continue;
      if (seq - f > 0) { seq -= f; continue; }
      is_used[i] = 1;
      cout << i << ' ';
      break;
    }
    x--;
  }
}

void SeqNoPrint() {
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    f = fact(n - i);
    for (int j = 1; j < a[i]; j++) {
      if (is_used[j]) continue;
      seq += f;
    }
    is_used[a[i]] = 1;
  }
  cout << seq + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> code;
  if (code == 1) SeqPrint();
  else SeqNoPrint();
}