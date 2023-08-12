#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string inputStr;
    getline(cin, inputStr);

    while(inputStr != ".") {
        
        stack<char> paren;

        bool isYes = true;
        for (auto c : inputStr) {
            if ((c == '(') || (c == '[')) paren.push(c);
            else if ((c == ')') || (c == ']')) {
                if(!paren.empty()) {
                    if(paren.top() == '(' && c == ')') paren.pop();
                    else if(paren.top() == '[' && c == ']') paren.pop();
                    else isYes = false;
                } else isYes = false;
            }
        }
        if(isYes && paren.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';

        getline(cin, inputStr);
    }
}