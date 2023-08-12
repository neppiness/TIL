#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x, sum = 0, m = 0;
  double avg;
  for(int i = 0; i < n; i++) {
    cin >> x;
    m = max(x, m);
    sum += x;
  }
  avg = (double)sum / (double)n * 100 / (double)m;
  cout.precision(3);
  cout << fixed;
  cout << avg;
}