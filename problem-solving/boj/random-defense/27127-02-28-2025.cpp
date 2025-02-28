#include <bits/stdc++.h>
using namespace std;

int comb[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int cnt = 0;
  do {
    int a = 0, b = 0;
    for (int i = 0; i < 5; i++) {
      a *= 10;
      b *= 10;
      a += comb[i];
      b += comb[i + 5];
    }
    cnt += (a / b == 9 && a % b == 0);
    if (cnt != n) continue;
    
    for (int i = 0; i < 5; i++) cout << comb[i];
    cout << ' ';
    for (int i = 5; i < 10; i++) cout << comb[i];
    return 0;
  } while (next_permutation(comb, comb + 10));
}
