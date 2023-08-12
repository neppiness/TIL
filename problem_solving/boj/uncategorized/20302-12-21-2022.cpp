#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100'002;
const int PMX = 9'600;

int cnt[MX], pcnt[PMX];

vector<int> prs; // prs.size() == 9592 at last
int ispr[MX];
int pridx = 1; // at last: 9593

void init() {
  prs.push_back(0);
  fill(ispr + 2, ispr + MX, 1);
  for(int no = 2; no < MX; no++) {
    if(!ispr[no]) continue;
    prs.push_back(no);
    ispr[no] = pridx++;
    for(ll j = no; j * (ll)no < MX; j++)
      ispr[j * no] = 0;
  }
}

void divideandcountprime(int tmp) {
  int pidx = 1;
  int d = cnt[tmp];
  while(tmp != 1) {
    if(ispr[tmp]) {
      pcnt[ispr[tmp]] += d;
      return;
    }
    if(tmp % prs[pidx] == 0) {
      tmp /= prs[pidx];
      pcnt[pidx] += d;
      continue;
    }
    pidx++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  
  int n, x; cin >> n >> x;
  cnt[abs(x)]++;

  while(--n) {
    char op; int x;
    cin >> op >> x;
    if(op == '*') cnt[abs(x)]++;
    else cnt[abs(x)]--;
  }

  if(cnt[0] > 0) {
    cout << "mint chocolate";
    return 0;
  }

  for(int i = 2; i < MX; i++) {
    if(cnt[i] == 0) continue;
    divideandcountprime(i);
  }

  // print answer
  for(int i = 1; i < PMX; i++) {
    if(pcnt[i] >= 0) continue;
    cout << "toothpaste";
    return 0;
  }
  cout << "mint chocolate";
}