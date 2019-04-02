#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// does not change
int N = 0;

// changes every task
int S = 0; // size of chess board
int board[310][310]; // chess board
int t[2][2]; // current and target
int INF = 0;

queue<int> s_q;
queue<int> start_q;
queue<int> end_q;
queue<pair<int, pair<int,int> > > q;

vector<int> v;

int d[][2] = {{-2,1},{-1,2},{1,2},{2,1}}; // up side directions

void board_init(){
    for(int i=0;i<310;i++){
        for(int j=0;j<310;j++){
            board[i][j] = INF;
        }
    }
    board[t[0][0]][t[0][1]] = 1;
}

bool check(int x, int y){
    bool result = true;
    if(x<0||x>=S||y<0||y>=S){ // check if x and y is in boundary
        result = false;
    }
    return result;
}

int bfs(){ // if find done
    int answer = 0;
    while(!q.empty()){
        pair<int, pair<int, int> > current = q.front();
        q.pop();
        if(current.second.first == t[1][0]&&current.second.second==t[1][1]){
            answer = current.first;
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        for(int i=0;i<4;i++){
            int rev = 1;
            for(int j=0;j<2;j++){
                int temp_x = current.second.first + rev*d[i][0];
                int temp_y = current.second.second + rev*d[i][1];
                if(check(temp_x,temp_y)){ // valid to go
                    if(board[temp_x][temp_y]==0){ // valid to travel
                        board[temp_x][temp_y] = 1;
                        q.push(make_pair(current.first+1,make_pair(temp_x,temp_y)));
                    }
                }
                rev *= -1;
            }
        }
    }
    return answer;
}

int task(){
    // get input
    scanf("%d",&S);
    for(int i=0;i<2;i++){
        scanf("%d %d",&t[i][0], &t[i][1]);
    }

    // initialize chess board
    board_init();
    // do dfs
    q.push(make_pair(0,make_pair(t[0][0],t[0][1])));
    int result = bfs();
    // find result
    return result;
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int result = task();
        v.push_back(result);
    }

    for(int i=0;i<v.size();i++){
        printf("%d\n",v[i]);
    }
    return 0;
}