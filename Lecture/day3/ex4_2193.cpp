#include <iostream>

using namespace std;
int N;
long p[100][2]; // number of pinary number for each number of digit
int check[100];

pair<long, long> search(int n){ // return number of pinary number for number of digit n+1
    if(n==0){ // if n_digit is 1 -> only 1 is alowed
        p[n][0] = 0;
        p[n][1] = 1;
    }else{
        if(check[n]!=1){ // do not know
            pair<long, long> prev = search(n-1);
            p[n][0] = prev.first + prev.second;
            p[n][1] = prev.first;
            check[n] = 1;
        }
    }
    return make_pair(p[n][0],p[n][1]);
}

int main(){
    scanf("%d",&N); // got N number of binary number
    pair<long, long> result = search(N-1);
    printf("%ld",result.first+result.second);
    return 0;
}