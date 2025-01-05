#include <bits/stdc++.h>
using namespace std;

const string DRIIP = "driip";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s.size() < 5) {
    cout << "not cute";
    return 0;
  }
  bool is_cute = 1;
  for (int i = 0; i < 5; i++)
    if (s[s.size() - 5 + i] != DRIIP[i])
      is_cute = 0;

  if (is_cute) {
    cout << "cute";
  } else {
    cout << "not cute";
  }
}
