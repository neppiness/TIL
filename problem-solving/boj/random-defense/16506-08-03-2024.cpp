#include <bits/stdc++.h>
using namespace std;

string op[] = {
  "ADD", "ADDC",
  "SUB", "SUBC",
  "MOV", "MOVC",
  "AND", "ANDC",
  "OR", "ORC",
  "NOT",
  "MULT", "MULTC",
  "LSFTL", "LSFTLC",
  "LSFTR", "LSFTRC",
  "ASFTR", "ASFTRC",
  "RL", "RLC",
  "RR", "RRC"
};

string code[] = {
  "00000", "00001",
  "00010", "00011",
  "00100", "00101",
  "00110", "00111",
  "01000", "01001",
  "01010",
  "01100", "01101",
  "01110", "01111",
  "10000", "10001",
  "10010", "10011",
  "10100", "10101",
  "10110", "10111"
};

unordered_map<string, string> opmap;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 23; i++)
    opmap[op[i]] = code[i];
   
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    cout << opmap[s] << "0";
    if (s == "NOT" || s == "MOV" || s == "MOVC") {
      cout << "000";
    } else {
    }
  }
  
}
