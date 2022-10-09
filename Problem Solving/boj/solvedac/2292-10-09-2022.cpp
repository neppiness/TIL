#include <bits/stdc++.h>
using namespace std;

const int MX = 18260;
int n;

bool solve(int x) {
  return n > 1 + 3*x*(x-1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int st = 0, en = MX, mid;
  while(st < en) {
    mid = (st + en)/2 + 1;
    if(!solve(mid)) en = mid - 1;
    else st = mid;
  }
  cout << st + 1;
}