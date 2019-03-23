#include <iostream>
#include <algorithm>

using namespace std;

int dist_n;
int budget[10010];
long long tot_budget;

long long answer = 0;

bool is_valid(long long mid){
    bool validity = true;
    long long temp = tot_budget;
    for(int i=0;i<dist_n;i++){
        if(budget[i]>mid){
            temp -= mid;
        }else{
            temp -= budget[i];
        }
        if(temp<0){
            validity = false;
            break;
        }
    }
    return validity;
}

long long search(long long left, long long right){
    if(left<=right){
        long long mid = (left+right)/2;
        if(is_valid(mid)){
            answer = mid;
            search(mid+1,right);
        }else{
            search(left,mid-1);
        }
    }
    
    return answer;
}

int main(){
    int tot = 0;
    int max = 0;

    scanf("%d",&dist_n);
    for(int i=0;i<dist_n;i++){
        scanf("%d",&budget[i]);
        tot += budget[i];
        if(max < budget[i]){
            max = budget[i];
        }
    }
    scanf("%lld",&tot_budget);

    if(tot<=tot_budget){
        printf("%d",max);
        return 0;
    }else{
        long long result = search(tot_budget/dist_n,tot_budget);
        printf("%lld",result);
    }
    return 0;
}