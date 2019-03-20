#include <stdio.h>
#include <algorithm>
using namespace std;

int A[500010];
int B[500010];

int N = 0;
int M = 0;

int BS(int left, int right, int num){
    int mid = (left+right)/2;
    int val = A[mid];
    if (left<=right){
        if(num<val){
            return BS(left,mid-1,num);
        }else if(num>val){
            return BS(mid+1,right,num);
        }else{
            return 1;
        }
    }
    return 0;    
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
    
    for(int i =0;i<M;i++){
        printf("%d ",BS(0,N-1,B[i]));
    }

    return 0;
}