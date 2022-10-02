#include <bits/stdc++.h>
using namespace std;

int main(void){
  int no, max = 0, idx = 0;
  for(int i = 1; i <= 9; i++) {
    cin >> no;
    if(max < no) {
      max = no;
      idx = i;
    }
  }
  cout << max << '\n' << idx;
}