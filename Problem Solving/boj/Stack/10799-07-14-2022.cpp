#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str;
    cin >> str;

    int result = 0;
    int numPipes = 0;

    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            numPipes++;
        }
        else if(str[i] == ')'){
            numPipes--;
            if((i != 0) && str[i-1] == '(') {
                result += numPipes;
            }
            else result++;
        }
    }
    cout << result;
}