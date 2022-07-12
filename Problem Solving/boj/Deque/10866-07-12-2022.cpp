#include <iostream>
using namespace std;

const int MX = 10000;
int DQ[MX*2+1];
int head = MX, tail = MX;

void push_front(int x) {DQ[--head] = x;}
void push_back(int x) {DQ[tail++] = x;}
int empty() {return ((head==tail) ? 1 : 0);}
int pop_front() {return (empty() ? -1 : DQ[head++]);}
int pop_back() {return (empty() ? -1 : DQ[--tail]);}
int front() {return (empty() ? -1 : DQ[head]);}
int back() {return (empty() ? -1 : DQ[tail-1]);}
int size() {return (tail - head);}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    string str;

    while(N--) {
        cin >> str;
        if(str=="push_front") {
            int x; cin >> x;
            push_front(x);
        } else if (str == "push_back") {
            int x; cin >> x;
            push_back(x);
        } else if (str == "pop_front") {
            cout << pop_front() << '\n';
        } else if (str == "pop_back") {
            cout << pop_back() << '\n';
        } else if (str == "size") {
            cout << size() << '\n';
        } else if (str == "empty") {
            cout << empty() << '\n';
        } else if (str == "front") {
            cout << front() << '\n';
        } else {
            cout << back() << '\n';
        }
    }
}