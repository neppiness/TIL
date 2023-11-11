#include <bits/stdc++.h>
using namespace std;

int n, a[1'000'002];

void merge_sort(int st, int en) {
  if (st == en) return;
  
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid + 1, en);

  int b[mid - st + 1];
  int c[en - mid];

  for (int i = 0; i <= mid - st; i++)
    b[i] = a[st + i];
  for (int i = 0; i < en - mid; i++)
    c[i] = a[mid + i + 1];

  int bidx = 0;
  int cidx = 0;
  int aidx = st;
  while (bidx <= mid - st && cidx < en - mid) {
    if (b[bidx] < c[cidx]) {
      a[aidx++] = b[bidx++];
    } else {
      a[aidx++] = c[cidx++];
    }
  }
  while (bidx <= mid - st) a[aidx++] = b[bidx++];
  while (cidx < en - mid) a[aidx++] = c[cidx++];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  merge_sort(0, n - 1);

  for (int i = 0; i < n; i++)
    cout << a[i] << '\n';
}
