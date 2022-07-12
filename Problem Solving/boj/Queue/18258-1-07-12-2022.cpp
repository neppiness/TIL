#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    string com;

    while(N--) {
        cin >> com;

        if(com == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if(com == "pop") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
            if(!q.empty()) q.pop();
        }
        else if(com == "size") {
            cout << q.size() << '\n';
        }
        else if(com == "empty") {
            cout << q.empty() << '\n';
        }
        else if(com == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        }
        else if(com == "back") {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }
}