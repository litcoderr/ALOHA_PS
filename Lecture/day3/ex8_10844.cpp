#include <iostream>
using namespace std;

int N;
long long DIV = 1000000000;
long long arr[110][10]; // array [number place][0~9] -> possibilities

long long Search(int n, int cur){  // number of places and current number
    long long result = 0;
    if(n<=0){
        if(cur==0) result = 0; // 0 can not be the start
        else result = 1; // else number of possibilities is 1
    }else{
        if(arr[n][cur]==0){// if not know --> calculate
            if(cur==0) arr[n][cur] = Search(n-1,1)%DIV;
            else if(cur==9) arr[n][cur] = Search(n-1,8)%DIV;
            else{
                arr[n][cur] += Search(n-1,cur+1)%DIV;
                arr[n][cur] += Search(n-1,cur-1)%DIV;
                arr[n][cur] %= DIV;
            }
        }
        result = arr[n][cur];
    }
    return result;
}

int main(){
    scanf("%d",&N);
    long long result = 0;
    for(int i=0;i<10;i++){
        result += Search(N-1,i);
    }
    printf("%lld",result%DIV);
    return 0;
}