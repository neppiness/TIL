#include <bits/stdc++.h>
using namespace std;

int n, m1;

int nos(int x, int d) {
  long long div = d;
  int ret = 0;
  int cnt = x / div;
  while(cnt != 0) {
    ret += cnt;
    div *= d;
    cnt = x / div;
  }
  return ret;
}

int subs(int d) {
  return nos(n, d) - nos(m1, d) - nos(n - m1, d);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m1;

  int fives = subs(5);
  int twos = subs(2);
  cout << min(fives, twos);
}