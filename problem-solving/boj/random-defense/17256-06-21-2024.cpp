#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int ax, ay, az;
  cin >> ax >> ay >> az;
  int cx, cy, cz;
  cin >> cx >> cy >> cz;

  cout << cx - az << ' ';
  cout << cy / ay << ' ';
  cout << cz - ax;
}
