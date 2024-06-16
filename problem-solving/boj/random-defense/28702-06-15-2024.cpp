#include <bits/stdc++.h>
using namespace std;

int no[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 3; i++) {
    string s; cin >> s;
    if (s == "Fizz") continue;
    if (s == "Buzz") continue;
    if (s == "FizzBuzz") continue;
    no[i] = stoi(s);
  }
  int i = 0;
  for (; i < 3; i++) {
    if (!no[i]) continue;
    break;
  }
  int ans = no[i] + (3 - i);
  if (ans % 3 == 0 && ans % 5 == 0) {
    cout << "FizzBuzz";
  } else if (ans % 3 == 0) {
    cout << "Fizz";
  } else if (ans % 5 == 0) {
    cout << "Buzz";
  } else {
    cout << ans;
  }
}
