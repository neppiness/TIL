#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p[10'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  p[1] = 1;
  for (int i = 2; i <= 10'000; i++)
    p[i] = p[i - 1] + p[i - 2];
  cout << p[10'000];
}