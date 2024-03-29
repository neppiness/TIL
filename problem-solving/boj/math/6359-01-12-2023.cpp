#include <bits/stdc++.h>
using namespace std;

int ans[102]; 
bool isopen[102];

void open(int n) {
  for(int i = 1; i * n <= 100; i++)
    isopen[i * n] = !isopen[i * n];

  for(int i = 1; i <= n; i++)
    if(isopen[i]) ans[n]++;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // for n = 1
  fill(isopen, isopen + 101, 1);

  for(int i = 2; i <= 100; i++)
    open(i);
  
  int t; cin >> t;
  while(t--) {
    int x; cin >> x;
    cout << ans[x] << '\n';
  }
}
/*
n번째 라운드에 대해 오픈을 수행한 뒤
1번방부터 n번방까지 확인하며 ans[n]배열에 기록합니다.

이 과정을 1부터 100까지 수행한 뒤
테스트케이스 입력값에 해당하는 정답을 출력합니다.
*/