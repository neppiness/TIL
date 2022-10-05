#include <bits/stdc++.h>
using namespace std;

int no[102];
int sum[1000002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> no[i];

  int cur = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++) {
        if(i == j || j == k || k == i) continue;
        sum[cur++] = no[i] + no[j] + no[k];
      }

  sort(sum, sum + cur);
  int idx = lower_bound(sum, sum + cur, m) - sum;
  if(idx == cur) idx--;
  if(sum[idx] > m) idx--;
  cout << sum[idx];
}