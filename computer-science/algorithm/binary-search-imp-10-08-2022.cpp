#include <bits/stdc++.h>
using namespace std;

int a[] = {2, 4, 6, 13, 16, 19, 22, 23, 30, 32};

int bs(int x) {
  int st = 0, en = 9;
  while(st < en) {
    int mid = (st + en)/2;
    if(a[mid] > x) en = mid - 1;
    else st = mid;
  }
  return st;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int f; cin >> f;
  cout << bs(f);
}