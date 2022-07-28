#include <iostream>
#include <vector>

using namespace std;

int N, M;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    int input;
    vector<int> intV;

    for(int i = 0; i < N; i++) {cin >> input; intV.insert(input, i);}


}