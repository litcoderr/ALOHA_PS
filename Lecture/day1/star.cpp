#include <iostream>

using namespace std;

int main(){
    int n = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1);j++){ //print gong bak
            printf(" ");
        }
        for(int j=0;j<(2*i+1);j++){ //print star
            printf("*");
        }
        printf("\n");//go to next line
    }
    return 0;
}