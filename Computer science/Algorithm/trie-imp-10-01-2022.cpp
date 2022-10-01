#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 10000*500 + 5;

bool chk[MX];
int nxt[MX][26];

int unused = 2;

int ctoi(char c){
  return c - 'A';
}

void insert(string& s){
  int idx = ROOT;
  for(int i = 0; i < s.size(); i++){
    if(nxt[idx][s[i]] == -1)
      nxt[idx][s[i]] = unused++;
    idx = nxt[idx][s[i]];
  }
  chk[idx] = 1;
}

int find(string& s){
  int idx = ROOT, cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(nxt[idx][s[i]] == -1) break;
    idx = nxt[idx][s[i]];
    cnt++;
  }
  if(cnt != s.size()) return -1;
  if(chk[idx]) return idx;
}

bool fetch(string& s){
  return (find(s) != -1);
}

void remove(string& s){
  if(!fetch(s)) return;

}

void test() {
  string a = "APPLE";
  cout << fetch(a) << '\n';
  remove(a);
  cout << fetch(a) << '\n';
  a = "APPLY";
  cout << fetch(a) << '\n';
  a = "APPL";
  cout << fetch(a) << '\n';
}

int main(void){
  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  int t; string s;
  cin >> t;
  while(t--) {
    cin >> s;
    insert(s);
  }
  test();
}

/*
Test case:
8
APPLE
APPLY
BLACK
BAN
BANANA
TAG
TAIL
TALL
*/