#include <bits/stdc++.h>
using namespace std;

int t;
string S = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  string str;
  while(t--) {
    cin >> str;
    if(S.find(str) != string::npos) cout << "YES\n";
    else cout << "NO\n";
  }
}