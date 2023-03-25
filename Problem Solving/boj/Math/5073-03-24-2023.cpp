#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int len[3] = {};
  for(int i = 0; i < 3; i++)
    cin >> len[i];
  while(len[0] != 0) {
    sort(len, len + 3);
    if(len[2] >= len[0] + len[1]) {
      cout << "Invalid\n";
    } else if(len[0] == len[1] && len[1] == len[2]) {
      cout << "Equilateral\n";
    } else if(len[0] == len[1] || len[1] == len[2] || len[2] == len[0]) {
      cout << "Isosceles\n";
    } else {
      cout << "Scalene\n";
    }
    for(int i = 0; i < 3; i++)
      cin >> len[i];
  }
}