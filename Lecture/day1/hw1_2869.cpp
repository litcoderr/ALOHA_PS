#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000 + 1;

int up,down,length;
long long answer = INF;

long long search(int low, int high){
    long long days = (high+low)/2;
    if(low<=high){
        int pos_length = days*(up-down) + up; // last day is excluded
        if(length <= pos_length){
            answer = min(answer,days+1); //+1 because last day has to be included
            search(low,days-1);
        }else{
            search(days+1,high);
        }
    }
    return answer;
}

int main(){
    scanf("%d %d %d",&up,&down,&length);
    long long result = search(0,length/(up-down)+1);
    printf("%lld",result);
    return 0;
}