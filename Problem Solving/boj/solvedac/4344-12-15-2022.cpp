#include <bits/stdc++.h>
using namespace std;

int sc[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  int t; cin >> t;
  while(t--) {
    int sum = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> sc[i];
      sum += sc[i];
    }
    int cnt = 0;
    double av = (double)sum / n;
    for(int i = 0; i < n; i++)
      if(av < sc[i]) cnt++;
    cnt *= 100;
    cout << ((double)cnt) / n << "%\n";
  }
}