#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 10000*500 + 5;

int unused = ROOT + 1;
bool chk[MX];
int nxt[MX][26];

int ctoi(char c){
  return c - 'A';
}

void insert(string& s){
  // cout << s << '\n';
  int idx = ROOT;
  for(int i = 0; i < s.size(); i++){
    // cout << s[i] << ' ';
    if(nxt[idx][ctoi(s[i])] == -1)
      nxt[idx][ctoi(s[i])] = unused++;
    idx = nxt[idx][ctoi(s[i])];
    // cout << idx << '\n';
  }
  chk[idx] = 1;
}

int find(string& s){
  int cur = ROOT, i = 0;
  for(; i < s.size(); i++){
    if(nxt[cur][ctoi(s[i])] == -1) break;
    cur = nxt[cur][ctoi(s[i])];
  }
  if(i != s.size()) return -1;
  if(chk[cur]) return cur;
  else return -1;
}

bool fetch(string& s){
  return (find(s) != -1);
}

void erase(string& s){
  int idx = find(s);
  if(idx == -1) return;
  chk[idx] = 0;
}

void test(){
  string insert1 = "apple";
  insert(insert1);
  string insert2 = "apply";
  insert(insert2);
  string insert3 = "black";
  insert(insert3);
  string insert4 = "ban";
  insert(insert4);
  string insert5 = "banana";
  insert(insert5);

  string find1 = "ban";
  cout << fetch(find1) << '\n'; // 1
  string find2 = "base";
  cout << fetch(find2) << '\n'; // 0
  string find3 = "app";
  cout << fetch(find3) << '\n'; // 0
  
  string erase1 = "banana";
  erase(erase1);
  string erase2 = "talk";
  erase(erase2);
  string erase3 = "apply";
  erase(erase3);
  
  string find4 = "ban";
  cout << fetch(find4) << '\n'; // 1
  string find5 = "apply";
  cout << fetch(find5) << '\n'; // 0  
}

int main(void){
  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i]+26, -1);
  test();
}