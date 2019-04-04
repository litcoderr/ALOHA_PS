#include <iostream>

using namespace std;
int N;
int d= 10007;
int block[1010];

int search(int n){ // return number of possibilities
    int p;
    if(n<0){
        return 1;
    }else{ // in index boundary
        if(block[n]>0){ // if know already, return
            return block[n];
        }else{ // do not know
            if(n==0){ // if n==1 only 1 possibility
                block[n] = 1;
            }else{ // if bigger than 1 do as below
                block[n] = (search(n-1) + 2*search(n-2))%d;
            }
            return block[n];
        }
    }
}

int main(){
    scanf("%d",&N); // get number of blocks
    int answer = search(N-1);    
    printf("%d", answer);
    return 0;
}