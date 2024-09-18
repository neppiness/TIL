#include <bits/stdc++.h>
using namespace std;

const string PR[] = { "V", "딸기" };
bool ans[4];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    n--; n %= 28; n++;

    if (n > 15) n = 30 - n;
    for (int x = 0; x < 4; x++) {
      int no = 1 << (3 - x);
      ans[x] = n / no;
      n %= no;
    }

    for (int i = 0; i < 4; i++)
      cout << PR[ans[i]];
    cout << '\n';
  }
}
