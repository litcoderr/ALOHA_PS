#include <iostream>
using namespace std;

int N;
int cost[1010][3];
int path[1010][3]; // min cost when coloring each color

int search(int n,int color){ // searching n for every color
    int smallest =-1;
    for(int i=0;i<3;i++){
        if(i!=color){
            int c = 0;
            if(path[n-1][i]>0){
                c = path[n-1][i]; // know the least
            }else{
                if(n<=0){
                    c = 0;
                }else{
                    c = search(n-1,i);
                }
            }
            int t = c+cost[n][color];
            if(smallest==-1){
                smallest = t;
            }else{
                if(t<smallest){
                    smallest = t;
                }
            }
        }
    }
    path[n][color] = smallest;
    return smallest;
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    int re[3];
    int a = search(N-1,0);
    for(int i=1;i<3;i++){
        int temp = search(N-1,i);
        if(temp<a){
            a = temp;
        }
    }
    printf("%d",a);
    return 0;
}