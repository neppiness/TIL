#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int f[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str; cin >> str;
  for(int i = 1; i < str.length(); i++) {
    int j = f[i - 1];
    while(str[i] != str[j] && j != 0) j = f[j - 1];
    f[i] = j + (str[i] == str[j]);
  }
  for(int i = 0; i < str.length(); i++)
    cout << f[i] << ' ';
}