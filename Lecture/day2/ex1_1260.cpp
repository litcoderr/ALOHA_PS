#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, start;
vector<int> v[1010];
queue<int> q;
int visit[1010];

void bfs(int current){
    q.push(current);
    visit[current] = 1;

    while(!q.empty()){
        current = q.front();
        for(int i=0;i<v[current].size();i++){
            if(visit[v[current][i]]!=1){
                q.push(v[current][i]);
                visit[v[current][i]] = 1;
            }
        }
        printf("%d ",q.front());
        q.pop();
    }
}

void dfs(int current){
    printf("%d ",current);
    visit[current] = 1;
    for(int i=0;i<v[current].size();i++){
        if(visit[v[current][i]]!=1){
            dfs(v[current][i]);
        }
    }
}

int main(){
    scanf("%d %d %d", &N,&M,&start);

    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0;i<=N;i++){
       sort(v[i].begin(),v[i].end()); 
    }
    dfs(start); //do dfs

    printf("\n");

    // initialize visit
    for(int i=0;i<1010;i++){
        visit[i] = 0;
    }

    bfs(start); //do bfs
    return 0;
}