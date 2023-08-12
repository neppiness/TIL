#include <iostream>
using namespace std;

int N;
int A[100002];
bool inUse[100002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;

  for(int i = 0; i < N; i++) cin >> A[i];

  inUse[A[0]] = 1;
  int en = 0;
  long long ans = 0;
  for(int st = 0; st < N; st++) {
    while(en < N-1 && !inUse[A[en+1]]) inUse[A[++en]] = 1;
    ans += en - st + 1;
    inUse[A[st]] = 0;
  }
  cout << ans;
}