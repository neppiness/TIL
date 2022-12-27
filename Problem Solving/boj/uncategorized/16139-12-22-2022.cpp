#include <bits/stdc++.h>
using namespace std;

int acnt[26][200'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; int n; 
  cin >> s >> n;

  for(int i = 0; i < s.length(); i++) {
    for(int j = 0; j < 26; j++)
      acnt[j][i + 1] = acnt[j][i] + (j == s[i] - 'a');
  }

  while(n--) {
    char a; int lb, rb; // left_boundary, right_boundary
    cin >> a >> lb >> rb;
    int idx = a - 'a';
    cout << acnt[idx][rb + 1] - acnt[idx][lb] << '\n';
  }
}