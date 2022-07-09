#include <list>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    list<int> L;

    int noOfCommands = 0;
    cin >> noOfCommands;

    for (int i = 0; i < str.length(); i++) {
        L.push_back(str[i]);
    }

    list<int>::iterator it = L.end();

    while(noOfCommands > 0) {
        char com;
        cin >> com;
        if (com == 'L') {
            if (it != L.begin()) {
                --it;
            };
        } else if (com == 'D') {
            if (it != L.end()) {
                ++it;
            }
        } else if (com == 'B') {
            if(it != L.begin()) {
                --it;
                it = L.erase(it);
            }
        } else {
            char a;
            cin >> a;
            it = L.insert(it, a);
            ++it;
        }
        noOfCommands--;
    }

    for(list<int>::iterator it1 = L.begin(); it1 != L.end(); it1++) {
        cout << (char)*it1;
    }
}