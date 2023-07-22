#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(2);
  cout << fixed;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    int pos = s.find('.');
    int ln = stoi(s.substr(0, pos));
    int rn = stoi(s.substr(pos + 1));
    a[i] = ln * 1000 + rn * 100;
  }
  sort(a, a + n);

  for (int i = 0; i < k; i++)
    a[i] = a[k];
  for (int i = n - k; i < n; i++)
    a[i] = a[n - k - 1];

  int tot = 0;
  for (int i = k; i < n - k; i++)
    tot += a[i];
  tot /= n - 2*k;
  if (tot % 10 >= 5) tot += 10;
  tot -= tot % 10;
  cout << tot / (double)1000 << '\n';
  
  tot = 0;
  for (int i = 0; i < n; i++)
    tot += a[i];
  tot /= n;
  if (tot % 10 >= 5) tot += 10;
  tot -= tot % 10;
  cout << tot / (double)1000 << '\n';
}