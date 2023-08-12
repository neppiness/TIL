#include <bits/stdc++.h>
using namespace std;

vector<string> name;
unordered_map<string, vector<int>> rec;

vector<string> solution(vector<string> record) {
    for(string str : record) {
        string tmpName;
        int tmp = 0;
        for(int i = 0; i <= str.size(); i++) {
            if('0' <= str[i] && str[i] <= '9') continue;
            if(str[i] == ':') {
                tmpName = str.substr(0, i);
                name.push_back(tmpName);
                tmp = i;
            } else if(str[i] == ',' || str[i] == '\0'){
                string s = str.substr(tmp + 1, i - tmp - 1);
                int number = stoi(s);
                rec[tmpName].push_back(number);
                tmp = i;
            }
        }
    }
    return name;
}