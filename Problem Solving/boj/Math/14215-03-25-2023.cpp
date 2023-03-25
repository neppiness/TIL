#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a[3] = {};
  for(int i = 0; i < 3; i++)
    cin >> a[i];
  sort(a, a + 3);

  if(a[2] >= a[1] + a[0])
    a[2] = a[0] + a[1] - 1;
  
  cout << a[0] + a[1] + a[2];
}