#include <iostream>
using namespace std;

int N, M;
int A[10002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> A[i];

  int en = 0;
  int tot = A[0], ans = 0;
  for(int st = 0; st < N; st++) {
    while(tot < M && ++en < N) tot += A[en];
    if(tot == M) ans++;
    tot -= A[st];
  }
  cout << ans;
}