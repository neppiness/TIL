#include <bits/stdc++.h>
using namespace std;

int t;
int num[10];

int ctoi(char c) { return (int)(c - '0'); }

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  int cnt, dnum;
  int len; string str;
  int i, j;
  while(t--) {
    i = 0, j = 0;
    cnt = 0, dnum = 0;
    fill(num, num + 10, 0);
    cin >> len >> str;
    while(i < len) {
      if(j != len && num[ctoi(str[j])] != dnum) {
        if(!num[ctoi(str[j])]) dnum++;
        num[ctoi(str[j])]++;
        j++;
        cnt += (j - i + 1);
        continue;
      }
      num[ctoi(str[i])]--;
      if(num[ctoi(str[i])] == 0) dnum--;
      i++;
      cnt += (j - i + 1);
    }
    cout << cnt << '\n';
  }
}