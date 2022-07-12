#include <iostream>
#include <string>

using namespace std;

int head = 0, tail = 0;
const int MX = 11111;
int q[MX] = {0};

void push(int x) {
    q[tail++] = x;
}

int size() {
    return tail - head;
}

int empty() {
    int answer = (head == tail) ? 1 : 0;
    return answer;
}

int pop() {
    int answer = empty() ? -1 : q[head++];
    return answer;
}

int front() {
    int answer = empty() ? -1 : q[head];
    return answer;
}

int back() {
    int answer = empty() ? -1 : q[tail-1];
    return answer;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N;

    cin >> N;

    string command;

    for(int i = 0; i < N; i++) {
        cin >> command;

        if(command == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if(command == "pop") cout << pop() << '\n';
        else if(command == "size") cout << size() << '\n';
        else if(command == "empty") cout << empty() << '\n';
        else if(command == "front") cout << front() << '\n';
        else if(command == "back") cout << back() << '\n';
    }

}