#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  int a = stoi(s1);
  int b = stoi(s2);
  int c = stoi(s3);

  cout << a + b - c << '\n';
  cout << stoi(s1 + s2) - c;
}
