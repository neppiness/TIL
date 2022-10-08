#include <bits/stdc++.h>
using namespace std;

vector<int> v[5];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  v[0].push_back(666);

  int x;
  int p10 = 1000;
  for(int i = 1; i <= 4; i++) {
    for(int no : v[i - 1]) {
      x = no*10;
      for(int j = 0; j < 10; j++)
        v[i].push_back(x + j);
    }
    for(int k = 0; k <= i - 1; k++) {
      for(int no2 : v[k]) {
        x = no2;
        for(int j = 1; j < 10; j++)
          v[i].push_back(x + j*p10);
      }
    }
    p10 *= 10;
  }
  for(int i = 0; i <= 4; i++)
    sort(v[i].begin(), v[i].end());

  int n; cin >> n;

  int prv = 0, cnt = 0;
  for(int i = 0; i <= 4; i++)
    for(int no : v[i]) {
      if(prv != no) cnt++;
      if(cnt == n) {
        cout << no;
        return 0;
      }
      prv = no;
    }
}