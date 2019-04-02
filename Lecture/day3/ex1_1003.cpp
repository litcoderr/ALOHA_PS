#include <iostream>
#include <vector>

using namespace std;
int check[50];
int zero[50];
int one[50];
int T;

void init(){
    for(int i=0;i<50;i++){
        check[i] = 0;
        zero[i] = 0;
        one[i] = 0;
    }
}

pair<int, int> fibo(int num){
    if(check[num] !=1){
        int z = 0;
        int o = 0;
        if(num<=0){
            z = 1;
        }else if(num==1){
            o = 1;
        }else{
            pair<int, int> a = fibo(num-1);
            pair<int, int> b = fibo(num-2);
            //find zero
            z = a.first + b.first;
            //find one
            o = a.second + b.second;
        }
        zero[num] = z;
        one[num] = o;
        check[num] = 1;
    }
    return make_pair(zero[num],one[num]);
}

void ex(int n){
    init();
    pair<int, int> result = fibo(n);
    printf("%d %d\n",result.first, result.second);
}

int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int task;
        scanf("%d",&task);
        ex(task);
    }
    return 0;
}