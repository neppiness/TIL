#include <iostream>
using namespace std;

int N, d, k, c;
int sushi[30002];
int count[3002];
int ANS = 0;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> N >> d >> k >> c;
  for(int i = 0; i < N; i++) cin >> sushi[i];

  int len = 0, ans = 0;
  int en = 0;
  for(int st = 0; st < N; st++) {
    while(len < k) {
      int cur = sushi[en];
      if(!count[cur]) ans++;
      count[cur]++;
      len++;

      en = (en + 1)%N;
    }
    if(!count[c]) {
        ans++;
        ANS = max(ANS, ans);
        ans--;
    } else ANS = max(ANS, ans);
      
    int out = sushi[st];
    count[out]--;
    len--;
    if(!count[out]) ans--;
  }
  cout << ANS;
}