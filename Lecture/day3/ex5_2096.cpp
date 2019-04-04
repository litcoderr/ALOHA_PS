#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[100010][3]; // cost of each space
int s[3]; // previous smallest (update every row)
int l[3]; // previous largest (update every row)

void search(int n){ // update least for every row
    if(n==0){ // initialize
        for(int i=0;i<3;i++){
            s[i] = cost[n][i];
            l[i] = cost[n][i];
        }
    }else{ // update based on previous
        int temp[3][2]; // min, max
        //determin previous min
        if(s[0]<s[1]){
            temp[0][0] = s[0];
        }else{
            temp[0][0] = s[1];
        }
        if(temp[0][0]<s[2]){ // global min is not last
            temp[1][0] = temp[0][0];
            if(s[2]<s[1]) temp[2][0] = s[2];
            else temp[2][0] = s[1];
        }else{ // global min is last
            temp[1][0] = s[2];
            temp[2][0] = s[2];
        }
        //determin previous max
       if(l[0]>l[1]){
            temp[0][1] = l[0];
        }else{
            temp[0][1] = l[1];
        }
        if(temp[0][1]>l[2]){ // global max is not last
            temp[1][1] = temp[0][1];
            if(l[2]>l[1]) temp[2][1] = l[2];
            else temp[2][1] = l[1];
        }else{ // global max is last
            temp[1][1] = l[2];
            temp[2][1] = l[2];
        }

        for(int i=0;i<3;i++){
            s[i] = cost[n][i]+temp[i][0];
            l[i] = cost[n][i]+temp[i][1];
        }
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        search(i); // search for i th row's smallest
    }
    int* S;
    int* L;
    S = min_element(s,s+3);
    L = max_element(l,l+3);
    printf("%d %d",*L, *S);
    return 0;
}