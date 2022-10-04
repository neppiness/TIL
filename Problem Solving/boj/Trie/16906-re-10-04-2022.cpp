#include <bits/stdc++.h>
using namespace std;

const int MX = 1000*2 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][2];
bool chk[MX];

int n;
int len[1002];
vector<string> w[1002];
unordered_map<int, queue<int>> seq;

int ctoi(char a){
  return a - '0';
}

string solve(int i){
  int cur = ROOT;
  string s = "";
  char c;

  while(s.size() != len[i] - 1){
    for(c = '0'; c != '2'; c++){
      int& next = nxt[cur][ctoi(c)];
      if(next == -1) next = unused++;
      if(chk[next]) continue;
      cur = next;
      s += c;
      cout << s << '\n';
      break;
    }
    if(c == '2') return "";
  }
  for(c = '0'; c != '2'; c++){
    int& next = nxt[cur][ctoi(c)];
    if(next != -1) continue;
    next = unused++;
    s += c;
    cur = next;
    break;
  }
  if(c == '2') return "";
  chk[cur] = 1;
  return s;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 2, -1);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> len[i];
    seq[len[i]].push(i);
  }
  sort(len, len + n);
  string s;
  for(int i = 0; i < n; i++){
    s = solve(i);
    if(s == "") {cout << -1; return 0;}
  }
}
/*
unordered_map<int, queue<int>> seq;는
해당 len 값이 i번째 len이라고 메모하는 용도
동일한 len 값이 나올 수 있기 때문에 queue로 처리
*/