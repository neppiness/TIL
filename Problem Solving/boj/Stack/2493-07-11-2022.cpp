#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    stack<int> temp;

    const int MX = 500001;
    int height[MX] = {0};

    int numTowers;

    cin >> numTowers;

    for (int i = 1; i <= numTowers; i++) {
        cin >> height[i];
    }

    int j = numTowers;

    do {
        temp.push(j-1);
        
        if(height[j] < height[j - 1]) {
            int val = temp.top();
            int k = j;
            while(!temp.empty()) {
                height[k++] = val;
                temp.pop();
            }
        } else height[j - 1] = height[j];
    } while(--j);

    while(!temp.empty()) {
        height[++j] = 0;
        temp.pop();
    }

    for (int i = 1; i <= numTowers; i++) {
        cout << height[i] << ' ';
    }
}