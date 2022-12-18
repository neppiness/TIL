#include <bits/stdc++.h>
using namespace std;

int rcnt = 1, dcnt;
int f[42];

int rc_fib(int n) {
  if(n == 1 || n == 2) return 1;
  else {
    rcnt++;
    return (rc_fib(n - 1) + rc_fib(n - 2));
  }
}

int dp_fib(int n) {
  for(int i = 3; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
    dcnt++;
  }
  return f[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  
  fill(f, f + 42, -1);
  f[0] = 0;
  f[1] = 1;
  f[2] = 1;

  rc_fib(n);
  dp_fib(n);
  cout << rcnt << ' ' << dcnt;
}