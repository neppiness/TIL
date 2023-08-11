#include <bits/stdc++.h>
using namespace std;

int d, bs[3], as[3];
set<tuple<int, int, int, int, int, int>> ans;

void setA(int order) {
  if (order == 3) {
    if (as[0] != 0 || as[1] != 0 || as[2] != 0)
      ans.insert({ as[0], bs[0], as[1], bs[1], as[2], bs[2] });
    return;
  }
  for (int a = 0; a <= bs[order]; a++) {
    as[order] = a;
    setA(order + 1);
  }  
}

void setB(int prev_b, int order, int remaining) {
  if (order == 2) {
    if (prev_b <= remaining) {
      bs[2] = remaining;
      setA(0);
    }
    return;
  }
  for (int b = prev_b; b < remaining; b++) {
    bs[order] = b;
    setB(b, order + 1, remaining - b);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> d;
  for (int i = 0; i < d; i++)
    setB(0, 0, i);

  for (auto [a1, b1, a2, b2, a3, b3] : ans) {
    cout << '(' << a1 << ", " << b1 << ") ";
    cout << '(' << a2 << ", " << b2 << ") ";
    cout << '(' << a3 << ", " << b3 << ") ";
    cout << '\n';
  }
  cout << "The number of sets for d = " << d << ": " << ans.size() << '\n';
}
