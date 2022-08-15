#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> stV;

bool comp(string a, string b) {
    if(a.length() < b.length()) return true;
    else if(a.length() == b.length()) return a < b;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    while(N--) {
        string str; cin >> str;
        stV.push_back(str);
    }

    sort(stV.begin(), stV.end(), comp);

    cout << (*stV.begin()) << '\n';
    for(auto it = stV.begin() + 1; it < stV.end(); it++) {
        if((*(it-1)) != (*it)) cout << *it << '\n';
    }
}