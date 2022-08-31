#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int S[1000002];
int MX = 0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> S[i];

  int en = 0;
  int cnt = 0;
  for(int st = 0; st < N; st++) {
    while(en < N && cnt + (S[en] % 2) <= K)
      cnt += S[en++] % 2;
    MX = max(en-st-cnt, MX);
    cnt -= S[st] % 2;
  }
  cout << MX;
}