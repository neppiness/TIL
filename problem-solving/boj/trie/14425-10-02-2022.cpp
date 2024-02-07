#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 500 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];
bool chk[MX];
int n, m;

int ctoi(char c){
  return c - 'a';
}

void insert(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
  chk[cur] = 1;
}

bool find(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      return 0;
    cur = nxt[cur][ctoi(c)];
  }
  return chk[cur];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 27, -1);
  
  cin >> n >> m;
  string s;

  while(n--){
    cin >> s;
    insert(s);
  }
  int ans = 0;
  while(m--){
    cin >> s;
    ans += find(s);
  }
  cout << ans;
}