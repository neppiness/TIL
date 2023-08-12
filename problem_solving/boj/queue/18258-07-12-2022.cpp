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
            int answer;
            if (q.empty() == 1) {
                answer = -1;
            } else {
                answer = q.front();
                q.pop();
            }
            cout << answer << '\n';
        }
        else if(com == "size") {
            cout << q.size() << '\n';
        }
        else if(com == "empty") {
            cout << q.empty() << '\n';
        }
        else if(com == "front") {
            int answer;
            if (q.empty()) answer = -1;
            else answer = q.front();
            cout << answer << '\n';
        }
        else if(com == "back") {
            int answer;
            if (q.empty()) answer = -1;
            else answer = q.back();
            cout << answer << '\n';
        }
    }
}