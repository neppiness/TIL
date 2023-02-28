#include <bits/stdc++.h>
using namespace std;

double gr[] = {4.0, 3.0, 2.0, 1.0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(6);
  cout << fixed;

  string s;
  double sum = 0, cr;

  int crcnt = 0;
  while(cin >> s >> cr >> s) {
    double g = 0;
    if(s[0] == 'P') continue;
    g = gr[s[0] - 'A'];
    if(s[1] == '+') g += 0.5;
    sum += g * cr;
    crcnt += cr;
  }
  cout << sum / crcnt;
}