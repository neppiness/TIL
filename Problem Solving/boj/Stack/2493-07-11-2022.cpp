#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    stack<int> hStk;
    stack<int> iStk;

    const int MX = 500001;
    int height[MX] = {0};

    int numTowers;

    cin >> numTowers;

    // initialization
    height[0] = 100000001;
    for (int i = 1; i <= numTowers; i++) {
        cin >> height[i];
    }

    int i = numTowers;

    hStk.push(height[i]);
    iStk.push(i);

    // Logic
    while(i--) {
        if(!hStk.empty()) {
            while(!hStk.empty()) {
                if(hStk.top() < height[i]) {
                    height[iStk.top()] = i;
                    hStk.pop();
                    iStk.pop();
                } else break;
            }
        }
        hStk.push(height[i]);
        iStk.push(i);
    }

    for (int i = 1; i <= numTowers; i++) {
        cout << height[i] << ' ';
    }
}