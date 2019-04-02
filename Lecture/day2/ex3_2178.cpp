#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int MAP[1010][1010];
queue<pair<int, int> > q;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void bfs(){
    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int temp_x = current.first + dir[i][0];
            int temp_y = current.second + dir[i][1];
            int temp = MAP[temp_x][temp_y];
            if(temp==0){ // valid to search (not have been searched yet) 
                MAP[temp_x][temp_y] = MAP[current.first][current.second] + 1;
                q.push(make_pair(temp_x,temp_y));
            }
        }
    }
}

int main(){
    for(int i=0;i<1010;i++){ // initialize MAP to -1
        for(int j=0;j<1010;j++){
            MAP[i][j] = -1;
        }
    }
    scanf("%d %d",&N, &M);
    for(int i=1;i<M+1;i++){
        for(int j=1;j<N+1;j++){
            scanf("%d",&MAP[i][j]);
            if(MAP[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }

    bfs();
    int result = -1;
    bool wrong = false;
    for(int i=1;i<M+1;i++){
        for(int j=1;j<N+1;j++){
            int current = MAP[i][j];
            if(current == 0){
                wrong = true;
            }
            if(current > result){
                result = current;
            }
        }
    }
    if(!wrong){
        result -= 1;
    }else{
        result = -1;
    }
    printf("%d", result);
    return 0;
}