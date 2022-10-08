#include <bits/stdc++.h>
using namespace std;

int a[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int x;
  while(n--) {
    cin >> x;
    a[x]++;
  }
  for(int i = 1; i < 10002; i++)
    for(int j = 0; j < a[i]; j++)
      cout << i << '\n';
}