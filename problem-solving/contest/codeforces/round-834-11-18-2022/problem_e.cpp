#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'002;

int t;
int power[MX];

int solve() {
  int n, h; cin >> n >> h;
  int blue = 1, green = 2;

  fill(power, power + h, 0);

  for(int i = 0; i < h; i++)
    cin >> power[i];
  
  
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--)
    cout << solve() << '\n';
}