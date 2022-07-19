#include <iostream>
#include <queue>
#include <tuple>
#include <string>

#define X first
#define Y second

int N, M;

using namespace std;

bool vis[1000][1000];
int dist[1000][1000];
int wall[1000][1000];

bool oob(int nx, int ny){
    return (nx >= M || nx < 0 || ny >= N || ny < 0);
}

void bfs(){
    queue<tuple<int,int,bool>> Q;
    Q.push({2,3,true});

    int nx, ny;
    bool brokeBlock;

    tie(nx, ny, brokeBlock) = Q.front();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    string str;

    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            wall[i][j] = str[j] - '0';
            vis[i][j] = false;
        }
    }

}