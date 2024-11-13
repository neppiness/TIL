#include <bits/stdc++.h>
using namespace std;

const string ANS[] = {"No", "Yes"};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  cout << ANS[100 * n >= m];
}
