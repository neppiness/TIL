#include <bits/stdc++.h>
using namespace std;

const string PPAP = "PPAP";

string s;

int Solve(int st) {
  if (st + 4 >= s.size()) return -1;
  string ss = s.substr(st, 4);
  if (ss == PPAP) return st + 4;

  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  if (Solve(0)) cout << "PPAP";
  else cout << "NP";
}