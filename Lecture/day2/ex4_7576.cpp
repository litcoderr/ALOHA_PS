#include <iostream>

using namespace std;

int N, M;
int max_step = 0;
int min_time=-1; // default value
int c=0; // number zeros to be searched

int MAP[1010][1010][2]; //0: map 1: value

int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y, int step){
    if(step==c){ // reached max
        if(min_time==-1){ // first time of max step visit
            min_time = MAP[x][y][1];
        }else{ // not first time of visit
            if(MAP[x][y][1]<min_time){
                min_time = MAP[x][y][1];
            }
        }
    }

    int cur_step = step;
    for(int i=0;i<4;i++){ // search adjacent points
        // check only valid points
        int temp_x = x+d[i][0]; int temp_y = y+d[i][1];
        if(MAP[temp_x][temp_y][0]!=-1){ // if valid
            int expected = MAP[x][y][1] + 1;
            if(expected < MAP[temp_x][temp_y][1]){ // if expected is lower than original update
                MAP[temp_x][temp_y][1] = expected;
            }
        }
    }
}

int main(){
    //initialize MAP 
    int s_x=0, s_y=0; // starting point   
    for(int i=0;i<1010;i++){
        for(int j=0;j<1010;j++){
            MAP[i][j][0] = -1;
            MAP[i][j][1] = 987654321;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",&MAP[i+1][j+1]);
            if(MAP[i+1][j+1][0]==1&&s_x==0){
                s_x = i+1;
                s_y = j+1;
            }
            if(MAP[i+1][j+1][0]==0){
                c++;
            }
        }
    }
    MAP[s_x][s_y][1] = 0;

    // start dfs
    dfs(s_x,s_y,0);

    return 0;
}