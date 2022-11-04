// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> answer;
    
    int st, en, pick;
    for(auto com : commands) {
        temp = array;
        
        st = com[0] - 1;
        en = com[1];
        pick = com[2] - 1;
        
        auto it = temp.begin();
        sort(it + st, it + en);
        answer.push_back(temp[st + pick]);
    }
    return answer;
}