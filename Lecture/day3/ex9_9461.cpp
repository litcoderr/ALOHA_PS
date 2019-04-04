#include <iostream>
using namespace std;

long long arr[110];
int T;

long long P(int n){ // length of nth triangle
    long long result = 0;
    if(n<3) result = 1;
    else if(n>2&&n<5) result = 2;
    else{ // in range of calculating
        if(arr[n]==0){// do not know
            arr[n] = P(n-1) + P(n-5);
        }
        result = arr[n];
    }
    return result;
}

int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int temp = 0;
        scanf("%d", &temp);
        long long result = P(temp-1);
        printf("%lld\n", result);
    }    
    return 0;
}