#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool yoot[12];
    for (int i = 0; i < 12; ++i) {
        cin >> yoot[i];
    }

    int sum[3] = {0};

    for (int i = 0; i < 4; ++i) {
        sum[0] += yoot[i];
        sum[1] += yoot[i+4];
        sum[2] += yoot[i+8];
    }

    for (int i = 0; i < 3; ++i) {
        if (sum[i] == 4) cout << 'E';
        else if (sum[i] == 3) cout << 'A';
        else if (sum[i] == 2) cout << 'B';
        else if (sum[i] == 1) cout << 'C';
        else if (sum[i] == 0) cout << 'D';
        cout << '\n';
    }

}

/*
// Authored by : wogha95
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/38cf0450b8c8458e859c486e3ea80323
#include <bits/stdc++.h>
using namespace std;

int result, input;
string res = "DCBAE";

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int r = 0; r < 3; r++) {
    result = 0;
    for(int c = 0; c < 4; c++) {
      cin >> input;
      result += input;
    }
    cout << res[result] << '\n';
  }
}
*/