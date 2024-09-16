#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> sc; // 곱, 합, 등번호

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    sc.push_back({b * c * d, b + c + d, a});
  }
  sort(sc.begin(), sc.end());
  for (int i = 0; i < 3; i++) {
    int no;
    tie(ignore, ignore, no) = sc[i];
    cout << no << ' ';
  }
}
