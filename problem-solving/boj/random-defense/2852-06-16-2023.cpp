#include <bits/stdc++.h>
using namespace std;

int n, sc[3], ans[3];
vector<int> t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int prv = 0;
  for (int i = 0; i < n; i++) {
    int no; string ms;
    cin >> no >> ms;

    int pos = ms.find(':');
    int m = stoi(ms.substr(0, pos));
    int s = stoi(ms.substr(pos + 1));
    int cur = m * 60 + s;

    if (sc[1] > sc[2]) ans[1] += cur - prv;
    if (sc[1] < sc[2]) ans[2] += cur - prv;
    prv = cur;
    sc[no]++;
  }

  if (sc[1] > sc[2]) ans[1] += 2880 - prv;
  if (sc[1] < sc[2]) ans[2] += 2880 - prv;
  for (int i = 1; i <= 2; i++) {
    string m = to_string(ans[i] / 60);
    string s = to_string(ans[i] % 60);
    if (ans[i] / 60 < 10) m = '0' + m;
    if (ans[i] % 60 < 10) s = '0' + s;
    cout << m<< ":" << s;
    if (i == 1) cout << '\n';
  }
}