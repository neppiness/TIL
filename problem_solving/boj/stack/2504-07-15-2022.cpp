#include <iostream>
#include <string>
#include <stack>

#define Invalid {isInvalid = true; break;}

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str;
    stack<char> paren;
    stack<int> vals, depths;

    cin >> str;

    int L = str.length();
    bool isInvalid = false;

    int d = 0, result = 0, temp = 0;

    for(int i = 0; i < L; i++) {
        if(str[i] == '(' || str[i] == '[') {paren.push(str[i]); depths.push(++d);}
        else if(paren.empty()) Invalid
        else if(str[i] == ')') {
            --d;
            vals.push(2);
            if(paren.top() == '(') paren.pop();
            else Invalid
        }
        else if(str[i] == ']') {
            --d;
            vals.push(3);
            if(paren.top() == '[') paren.pop();
            else Invalid
        }
    }

    int temp = 0;
    if(!paren.empty() || isInvalid) cout << 0;
    else {
        while(!vals.empty()) {
            temp = depths.top();
            depths.pop();
            if (temp != depths.top());
        }

        cout << '\n';

        while(!vals.empty()) {
            cout << vals.top() << ' ';
            vals.pop();
        }

        cout << '\n';

        while(!depths.empty()) {
            cout << depths.top() << ' ';
            depths.pop();
        }
    }
}