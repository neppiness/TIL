#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> pr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  pr["SONGDO"] = "HIGHSCHOOL";
  pr["CODE"] = "MASTER";
  pr["2023"] = "0611";
  pr["ALGORITHM"] = "CONTEST";

  string s; cin >> s;
  cout << pr[s];
}
