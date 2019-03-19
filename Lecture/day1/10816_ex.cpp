#include <stdio.h>
#include <algorithm>
using namespace std;

int A[500010];
int B[500010];

int N = 0;
int M = 0;

int upper(int left, int right, int num){
    int mid = (left+right)/2;
    int val = A[mid];
    int answer = -1;

    if (left<=right){
        if(num<val){
            return upper(left,mid-1,num);
        }else if(num>val){
            return upper(mid+1,right,num);
        }else{
            answer = mid;
            return upper(mid+1,N-1,num);
        }
    }
    return answer;
}

int lower(int left, int right, int num){
    int mid = (left+right)/2;
    int val = A[mid];
    int answer = right;

    if (left<=right){
        if(num<val){
            return lower(left,mid-1,num);
        }else if(num>val){
            return lower(mid+1,right,num);
        }else{
            answer = mid;
            return lower(0,mid-1,num);
        }
    }
    return answer;
}

int main(){
    scanf("%d",&N);

    int i = 0;
    for (i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&M);

    i = 0;
    for(i=0;i<M;i++){
        scanf("%d",&B[i]);
    }

    sort(A,A+N);
    int num = 0;
    for(int i =0;i<M;i++){
        int upper_bound = lower(0,N-1,B[i]);
        printf("%d",upper_bound);
        if(upper_bound != -1){
            int lower_bound = lower(0,upper_bound,num);
            num = upper_bound - lower_bound + 1;
        }
        //printf("%d ",num);
        num = 0;
    }

    return 0;
}
