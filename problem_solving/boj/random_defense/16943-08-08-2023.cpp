#include <bits/stdc++.h>
using namespace std;

vector<char> A;
string a; int b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  for (char c : a) A.push_back(c);
  sort(A.begin(), A.end());

  int digits = A.size();
  int min_val = 1;
  while (--digits) min_val *= 10;

  int ans = -1;
  do {
    string strA = string(A.begin(), A.end());
    int noA = stoi(strA);
    if (noA < min_val) continue;
    if (noA < b) ans = max(ans, noA);
  } while (next_permutation(A.begin(), A.end()));
  cout << ans;
}