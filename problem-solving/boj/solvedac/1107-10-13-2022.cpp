#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MX = 1'000'001;
const int ST = 100;

bool no[10];
int c[MX], d[MX];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  fill(no, no + 10, 1);

  int x;
  while(m--) {
    cin >> x;
    no[x] = 0;
  }

  fill(c, c + MX, INF);
  for(int i = 0; i < MX; i++)
    d[i] = (int)abs(n - ST);

  int p10 = 10, p = 1;
  int tmp, cnt;
  bool isvalid;
  for(int i = 0; i < MX; i++) {
    while(i / p10) {p10 *= 10; p++;}
    cnt = 0;
    tmp = i;
    isvalid = 1;
    for(int j = 0; j < p; j++) {
      if(!no[tmp%10]) {isvalid = 0; break;}
      cnt++;
      tmp /= 10;
    }
    if(isvalid) c[i] = cnt + (int)abs(i - n);
  }
  
  int minc = min_element(c, c + MX) - c;
  int mind = min_element(d, d + MX) - d;
  cout << min(c[minc], d[mind]);
}