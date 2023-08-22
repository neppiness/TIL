#include <bits/stdc++.h>
using namespace std;

string digit[10][5];

void initDigit() {
  digit[0][0] = " - ";
  digit[0][1] = "| |";
  digit[0][2] = "   ";
  digit[0][3] = "| |";
  digit[0][4] = " - ";

  digit[1][0] = "   ";
  digit[1][1] = "  |";
  digit[1][2] = "   ";
  digit[1][3] = "  |";
  digit[1][4] = "   ";

  digit[2][0] = " - ";
  digit[2][1] = "  |";
  digit[2][2] = " - ";
  digit[2][3] = "|  ";
  digit[2][4] = " - ";

  digit[3][0] = " - ";
  digit[3][1] = "  |";
  digit[3][2] = " - ";
  digit[3][3] = "  |";
  digit[3][4] = " - ";

  digit[4][0] = "   ";
  digit[4][1] = "| |";
  digit[4][2] = " - ";
  digit[4][3] = "  |";
  digit[4][4] = "   ";

  digit[5][0] = " - ";
  digit[5][1] = "|  ";
  digit[5][2] = " - ";
  digit[5][3] = "  |";
  digit[5][4] = " - ";

  digit[6][0] = " - ";
  digit[6][1] = "|  ";
  digit[6][2] = " - ";
  digit[6][3] = "| |";
  digit[6][4] = " - ";

  digit[7][0] = " - ";
  digit[7][1] = "  |";
  digit[7][2] = "   ";
  digit[7][3] = "  |";
  digit[7][4] = "   ";

  digit[8][0] = " - ";
  digit[8][1] = "| |";
  digit[8][2] = " - ";
  digit[8][3] = "| |";
  digit[8][4] = " - ";

  digit[9][0] = " - ";
  digit[9][1] = "| |";
  digit[9][2] = " - ";
  digit[9][3] = "  |";
  digit[9][4] = " - ";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  initDigit();
  int s; string no;
  cin >> s >> no;

  // 1개 행 출력 로직
  for (int i = 0; i < no.size(); i++) {
    if (i) cout << ' ';
    int d = no[i] - '0';
    cout << digit[d][0][0];
    for (int j = 0; j < s; j++)
      cout << digit[d][0][1];
    cout << digit[d][0][2];
    if (i == no.size() - 1) cout << '\n';
  }

  // s개 행 출력 로직
  for (int k = 0; k < s; k++) {
    for (int i = 0; i < no.size(); i++) {
      if (i) cout << ' ';
      int d = no[i] - '0';
      cout << digit[d][1][0];
      for (int j = 0; j < s; j++)
        cout << digit[d][1][1];
      cout << digit[d][1][2];
      if (i == no.size() - 1) cout << '\n';
    }
  } 

  // 1개 행 출력 로직
  for (int i = 0; i < no.size(); i++) {
    if (i) cout << ' ';
    int d = no[i] - '0';
    cout << digit[d][2][0];
    for (int j = 0; j < s; j++)
      cout << digit[d][2][1];
    cout << digit[d][2][2];
    if (i == no.size() - 1) cout << '\n';
  }

  // s개 행 출력 로직
  for (int k = 0; k < s; k++) {
    for (int i = 0; i < no.size(); i++) {
      if (i) cout << ' ';
      int d = no[i] - '0';
      cout << digit[d][3][0];
      for (int j = 0; j < s; j++)
        cout << digit[d][3][1];
      cout << digit[d][3][2];
      if (i == no.size() - 1) cout << '\n';
    }
  } 
  
  // 1개 행 출력 로직
  for (int i = 0; i < no.size(); i++) {
    if (i) cout << ' ';
    int d = no[i] - '0';
    cout << digit[d][4][0];
    for (int j = 0; j < s; j++)
      cout << digit[d][4][1];
    cout << digit[d][4][2];
  }
}
