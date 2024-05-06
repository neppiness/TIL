#include <bits/stdc++.h>
using namespace std;

const string MONTH[] = {
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
};

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(15);
  cout << fixed;

  string s; cin >> s;
  int mon = 0;
  while (1) {
    if (s == MONTH[mon]) break;
    mon++;
  }

  cin >> s;
  string ss = s.substr(0, s.size() - 1);
  int d = stoi(ss);

  cin >> s;
  int y = stoi(s);
  if (y % 400 == 0) days[1] = 29;
  if (y % 4 == 0 && y % 100 != 0) days[1] = 29;

  cin >> s;
  int h = stoi(s.substr(0, 2));
  int m = stoi(s.substr(3));

  int den = 0;
  for (int i = 0; i < 12; i++)
    den += days[i];
  den *= 24 * 60;

  int num = 0;
  for (int i = 0; i < mon; i++)
    num += days[i];
  num += d - 1;
  num *= 24 * 60;
  num += h * 60 + m;
  cout << (double) num * 100 / den;
}
