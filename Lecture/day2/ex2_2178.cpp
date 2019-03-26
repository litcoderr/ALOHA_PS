#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int MAP[110][110];
int visit[110][110];

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int a, int b){
    // get valid points to search
    int valid[4];
    for(int i=0;i<4;i++){
        valid[i] = 0;
    }
    for(int i=0;i<4;i++){
        int temp = MAP[a+dir[i][0]][b+dir[i][1]];
        if(temp != 0 && temp != -1){
            valid[i] = 1;
        }
    }

    for(int i=0;i<4;i++){
        if(valid[i]==1){ // valid points
            int current = visit[a][b] + 1;
            if(current < visit[a+dir[i][0]][b+dir[i][1]]){ // if smaller update
                visit[a+dir[i][0]][b+dir[i][1]] = current;
                dfs(a+dir[i][0],b+dir[i][1]);
            }
        }
    }
    for(int i=0;i<4;i++){
        valid[i] = 0;
    }
}

int main(){
    for(int i=0;i<110;i++){ // initialize MAP to -1
        for(int j=0;j<110;j++){
            MAP[i][j] = -1;
        }
    }
    scanf("%d %d",&N, &M);
    for(int i=1;i<N+1;i++){
        for(int j=1;j<M+1;j++){
            scanf("%1d",&MAP[i][j]);
        }
    }

    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            visit[i][j] = 987654321;
        }
    }
    visit[1][1] = 1;
    dfs(1,1);
    printf("%d", visit[N][M]);
    return 0;
}