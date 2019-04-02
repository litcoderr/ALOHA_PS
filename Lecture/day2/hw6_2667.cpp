#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int MAP[30][30][2];
int d[900]; // danji num
int MAX = 0; // max danji
int S; // Size of map
queue<int > q; // queue for conflicting danji
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> result;

int main(){
    scanf("%d", &S);
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            scanf("%1d",&MAP[i][j][0]);
        }
    }

    // count danji
    for(int i=0;i<S;i++){
        for(int j=0;j<S;j++){
            if(MAP[i][j][0]==1){ // valid point
                bool iso = true;
                for(int k=0;k<4;k++){
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(tx>=0&&tx<=S-1&&ty>=0&&ty<=S-1){ // valid points to look at
                        if(MAP[tx][ty][1]!=0){ // has danji
                            q.push(MAP[tx][ty][1]);
                            iso = false;
                        }
                    }
                }
                if(iso){ // isolated
                    MAX++; // add one to max danji
                    MAP[i][j][1] = MAX;
                    d[MAX] = 1;
                }else{
                    int n = 0; // number of conflict danji num
                    int tot = 0; // total number
                    int min_i = 987654321; // smallest danji num
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        if(min_i>cur){
                            min_i = cur;
                        }
                        tot += d[cur];
                        d[cur] = 0;
                        n++;
                    }
                    tot += 1; // include myself
                    d[min_i] = tot; // update number of house in danji
                    MAP[i][j][1] = min_i;
                }
            }
        }
    }
    for(int i=0;i<MAX+1;i++){
        if(d[i]!=0){
            result.push_back(d[i]);
        }
    }
    sort(result.begin(),result.end());
    int d_num = result.size();
    printf("%d\n",d_num);
    for(int i=0;i<result.size();i++){
        printf("%d\n",result[i]);
    }
    return 0;
}