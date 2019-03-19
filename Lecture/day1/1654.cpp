#include <stdio.h>
#include <climits>

int have, need;
long long len[1000010];
long long answer = 0;

long long PS(long long left, long long right){
    long long mid = (left+right) / 2;
    long long temp = 0;
    if (left<=right){
        for(int i=0;i<have;i++){
            temp += len[i] / mid;
        }
        if(temp==need){
            answer = mid;
            return PS(mid+1,INT_MAX);
        }
        if(temp<need){
            return PS(left,mid-1);
        }else if(temp>need){
            return PS(mid+1,right);
        }
    }

    return 0;
}

int main(){
    scanf("%d",&have);
    scanf("%d",&need);

    for(int i=0;i<have;i++){
        scanf("%lld",&len[i]);
    }

    long long isdone = PS(1,INT_MAX);
    printf("%lld",answer);

    return 0;
}