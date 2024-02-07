#include <bits/stdc++.h>
using namespace std;

int a[100'002];
int sz = 0;

bool cmp(int i, int j) {
  return abs(a[i]) > abs(a[j]) || (abs(a[i]) == abs(a[j]) && a[i] > a[j]);
} 

void arrange(int x) {
  if (x > sz) return;
  int lt = x*2;
  int rt = x*2 + 1;
  if (lt > sz) return;
  if (rt > sz) {
    if (cmp(x, lt)) {
      swap(a[x], a[lt]);
    }
    return;
  }
  // lt, rt에 대한 비교가 모두 필요한 경우
  if (!cmp(x, lt) && !cmp(x, rt)) {
    return;
  }
  if (cmp(lt, rt)) {
    swap(a[x], a[rt]);
    arrange(rt);
  } else {
    swap(a[x], a[lt]);
    arrange(lt);
  }
}

void pop() {
  if (!sz) {
    cout << 0 << '\n';
    return;
  }
  cout << a[1] << '\n';
  swap(a[1], a[sz--]);
  arrange(1);
}

void reverse_arrange(int x) {
  int p = x / 2;
  if (!p) return;
  if (cmp(p, x)) {
    swap(a[p], a[x]);
    reverse_arrange(p);
  }
}

void insert(int x) {
  a[++sz] = x;
  reverse_arrange(sz);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    if (!x) pop();
    else insert(x);
  }
}
