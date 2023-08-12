#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int ans_A, ans_B;
int tot = INF;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int g, l; cin >> g >> l;
  int ab = l / g;

  for(int a = 1; a * a <= ab; a++) {
    if(ab % a) continue;
    int b = ab / a;
    if(gcd(a, b) != 1) continue;

    int A = g*a, B = g*b;
    if(A + B > tot) continue;
    tot = A + B;
    ans_A = A, ans_B = B;
  }
  cout << ans_A << ' ' << ans_B;
}