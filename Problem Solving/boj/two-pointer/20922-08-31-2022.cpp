#include <iostream>
using namespace std;

int N, K;
int a[200002];
int count[100002];
int LEN;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> a[i];

  int en = -1;
  int len = 0;
  for(int st = 0; st < N; st++) {
    while(en < N - 1 && count[a[en + 1]] < K) {
      en++;
      count[a[en]]++;
      len++;
    }
    LEN = max(LEN, len);

    count[a[st]]--;
    len--;
  }
  cout << LEN;
}