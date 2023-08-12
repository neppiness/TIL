#include <bits/stdc++.h>
using namespace std;

int n;

void print(int lv) {
  for(int i = 1; i <= n - lv; i++)
    cout << ' ';
  for(int i = 1; i < 2*lv; i++)
    cout << '*';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i < n; i++)
    print(i);
  for(int i = n; i >= 0; i--)
    print(i);
}