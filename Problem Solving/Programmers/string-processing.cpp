#include <bits/stdc++.h>
using namespace std;

int main() {
  string inputString = "jack: 11, 4, 5, 10, 15";

  // Vector of string to save tokens
  vector<string> tokens;

  // stringstream class ss
  stringstream ss1(inputString);

  string medium1, medium2, medium3;

  while(getline(ss1, medium1, ' ')) {
    stringstream ss2(medium1);
    while(getline(ss2, medium2, ':')) {
      stringstream ss3(medium2);
      while(getline(ss3, medium3, ','))
        tokens.push_back(medium3);
    }
  }

  // Printing the token vector
  for(int i = 0; i < tokens.size(); i++)
    cout << tokens[i] << '\n';
}