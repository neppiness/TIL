#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = -1, cnt;
vector<int> A;
vector<int> tmp(500'002);

void merge(int p, int q, int r) {
  int i = p, j = q + 1, t = 1;

  while(i <= q && j <= r) {
    if(A[i] <= A[j]) tmp[t++] = A[i++];
    else tmp[t++] = A[j++];
  }
  while(i <= q) tmp[t++] = A[i++];
  while(j <= r) tmp[t++] = A[j++];

  i = p; t = 1;
  while(i <= r) {
    A[i++] = tmp[t++];
    cnt++; if(cnt == k) ans = tmp[t - 1];
  }
}

void merge_sort(int p, int r) {
  if(p < r) {
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  while(n--) {
    int x; cin >> x;
    A.push_back(x);
  }
  merge_sort(0, A.size() - 1);
  cout << ans;
}