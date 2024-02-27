#include <bits/stdc++.h>
using namespace std;

int x[1'000'002];

void merge_sort(int st, int en) {
  if (st == en) return;
  int mid = (st + en) / 2;

  merge_sort(st, mid);
  merge_sort(mid + 1, en);

  int a[mid - st + 1];
  int b[en - mid];

  for (int i = st; i <= mid; i++)
    a[i - st] = x[i];

  for (int i = mid + 1; i <= en; i++)
    b[i - (mid + 1)] = x[i];

  int index = st;
  int index_a = 0;
  int index_b = 0;

  while (index_a < mid - st + 1 && index_b < en - mid) {
    if (a[index_a] < b[index_b]) x[index++] = a[index_a++];
    else x[index++] = b[index_b++];
  }

  while (index_a < mid - st + 1)
    x[index++] = a[index_a++];
  
  while (index_b < en - mid)
    x[index++] = b[index_b++];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];

  merge_sort(0, n - 1);

  for (int i = 0; i < n; i++)
    cout << x[i] << '\n';
}
