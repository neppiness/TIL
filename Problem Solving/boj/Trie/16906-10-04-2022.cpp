#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][2];
bool chk[MX];

vector<int> len;
string w[1002];
unordered_map<int, queue<int>> seq;

int ctoi(char c){
  return c - '0';
}

string insert(int len){
  string s = "";
  int cur = ROOT;
  char a;
  while(s.size() != len){
    for(a = '0'; a <= '1'; a++) {
      int& next = nxt[cur][ctoi(a)];
      if(chk[next]) continue;
      if(next == -1) next = unused++;
      cur = next;
      s += a;
      break;
    }
    if(a == '2') return "";
  }
  chk[cur] = 1;
  return s;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 2, -1);

  int n, l;
  string s;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> l;
    len.push_back(l);
    seq[l].push(i);
  }
  sort(len.begin(), len.end());

  for(int l : len){
    s = insert(l);
    if(s == "") {
      cout << -1;
      return 0;
    } else{
      w[seq[l].front()] = s;
      seq[l].pop();
    }
  }

  cout << "1\n";
  for(int i = 0; i < n; i++)
    cout << w[i] << '\n';
}