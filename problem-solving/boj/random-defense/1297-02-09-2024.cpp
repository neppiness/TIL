#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int D, h, w;
  cin >> D >> h >> w;
  double d = sqrt(h * h + w * w);
  int H = (h * D) / d;
  int W = (w * D) / d;
  cout << H << ' ' << W;
}
