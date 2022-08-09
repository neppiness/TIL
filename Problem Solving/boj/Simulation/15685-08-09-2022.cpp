#include <iostream>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;

int N;

int x[22], y[22], d[22], g[22];

bool board[101][101];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int cx, cy;

vector<pair<int,int>> V;

int ret(){
    int ans = 0;
    for(int row = 0; row < 100; row++)
        for(int col = 0; col < 100; col++)
            if(board[row][col] && board[row+1][col] && board[row][col+1] && board[row+1][col+1]) ans++;
    return ans;
}

vector<pair<int,int>> rotateV(vector<pair<int,int>>& v) {
    vector<pair<int,int>> rV;
    for(auto it = v.rbegin(); it < v.rend(); it++) {
        rV.push_back({(*it).Y,-(*it).X});
    }
    return rV;
}

void dc(int cx, int cy, int dir, int gen) {
    V.push_back({cx, cy});
    V.push_back({cx + dx[dir], cy + dy[dir]});
    for(int G = 0; G < gen; G++) {
        auto rotatedV = rotateV(V);
        
        auto it = rotatedV.begin();
        int diffX = V.back().X - (*it).X, diffY = V.back().Y - (*it).Y;
        it++;

        for(; it < rotatedV.end(); it++) {
            V.push_back({(*it).X + diffX, (*it).Y + diffY});
        }
    }

    while(!V.empty()) {
        auto cur = V.back(); V.pop_back();
        board[cur.X][cur.Y] = 1;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N;
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> d[i] >> g[i];

    for(int row = 0; row < 101; row++) fill(board[row], board[row] + 101, false);
    for(int i = 0; i < N; i++) {
        cx = x[i], cy = y[i];
        dc(cy, cx, d[i], g[i]);
    }

    cout << ret() << '\n';
}