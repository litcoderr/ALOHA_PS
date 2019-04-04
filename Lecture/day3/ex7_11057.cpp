#include <iostream>
using namespace std;

int N; // number of wanted number of places
int arr[1010][10]; // posibilites depending on each number in that place
int DIV = 10007;

int Pos(int n, int index){ // returns possibilites devides by 10007 for nth number of places
    int result;
    if(n<=0){ // if n is first or out of bound range
        result = 1;
    }else{ // n is second or larger
        if(arr[n][index]==0){ // do not know --> calulate
            for(int i=0;i<=index;i++){
                arr[n][index] += Pos(n-1,i) % DIV;
                arr[n][index] %= DIV;
            }
        }
        result = arr[n][index];
    }
    return result;
}

int main(){
    scanf("%d",&N);    
    int result  = 0;
    for(int i=0;i<10;i++){
        result += Pos(N-1,i);
    }
    printf("%d",result%DIV);
    return 0;
}