#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> alpha[26];

int main() {
    string a, b;
    cin >> a >> b;

    for(int i = 0; i < a.length(); i++) alpha[a[i] - 'A'].push_back(i);

    for(int i = 0; i < b.length(); i++) {
        int len = 0;
        for(int j = i + 1; j < b.length(); j++) {
            for(auto element : alpha[b[i] - 'A']) {
                element;
            }
        }
    }
}