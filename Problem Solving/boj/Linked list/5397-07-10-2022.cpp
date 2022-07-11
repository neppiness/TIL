#include <iostream>
#include <list>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int noCases;
    cin >> noCases;

    list<char> strList;
    list<char>::iterator it;

    int i = 0;
    while(i < noCases) {
        string str;
        cin >> str;

        it = strList.begin();
        for (auto c : str) {
            if (c == '<') {
                if(it != strList.begin()) it--;
            } else if (c == '>') {
                if(it != strList.end()) it++;
            } else if (c == '-') {
                if(it != strList.begin()) {
                    it--;
                    it = strList.erase(it);
                }
            } else {
                strList.insert(it, c);
            }
        }

        it = strList.begin();
        for (auto it : strList) {
            cout << it;
        }
        cout << '\n';

        i++;   
        strList.clear();
    }
}