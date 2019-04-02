#include <iostream>
#include <vector>

using namespace std;

int N, M;
int graph[1010][1010];
int visit[1010];
int merged[1010];
int idx = 0;
int c = 0;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        int temp_x, temp_y;
        scanf("%d %d", &temp_x, &temp_y);
        graph[temp_x-1][temp_y-1] = 1;
        graph[temp_y-1][temp_x-1] = 1;
    }
    merged[1] = 1;
    for(int i=0;i<N;i++){
        bool isolated = true;
        int temp[1010][2];

        int n = 0;
        for(int j=0;j<N;j++){
            if(graph[i][j]==1){
                if(visit[j]!=0){ //
                    isolated = false;
                    temp[n][0] = j;
                    temp[n][1] = visit[j];
                    n++;
                }
            }            
        }
        if(isolated){
            idx ++; // if isolated +1 answer
            c++;
            visit[i] = idx;
        }else{ // not isolated? merge
            int merge_val = temp[0][1];
            for(int j=0;j<n;j++){
                if(j==0){
                    visit[i] = merge_val; // enter merge val
                }else{ //edit rest of nodes
                    visit[temp[j][0]] = merge_val;
                    if(merged[temp[j][1]]!=1){
                        merged[temp[j][1]] = 1;
                        c--;
                    }
                }
            }
        }
    }
    printf("%d", c);
    return 0;
}