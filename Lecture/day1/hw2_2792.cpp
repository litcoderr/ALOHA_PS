#include <iostream>
#include <algorithm>

using namespace std;

int color[300010];
int child_n, color_n;
int ANSWER = 0;

int MAX = 0;

int min_n(int max){ // minimum number of people able to distribute
    int temp=0;
    for(int i=0;i<color_n;i++){
        temp += color[i] / max;
        if(color[i]%max!=0){
            temp += 1;
        }
    }
    return temp;
}

bool is_valid(int max){ // check if valid at this max number
    int min = min_n(max); // minimum number of people with this max number of guceul
    if(child_n<min){
        return false;
    }else{
        return true;
    }
}

int search(int left, int right){ // search for valid low bound max guceul num
    if(left<=right){
        int est_max = (left+right) / 2; // estimated max value bound for minimum
        if(is_valid(est_max)){ // valid
            ANSWER = est_max;
            search(left,est_max-1);
        }else{ // not valid
            search(est_max+1,right);
        }
    }
    return ANSWER;
}

int main(){
    // get input
    scanf("%d %d",&child_n,&color_n);
    for(int i=0;i<color_n;i++){
        scanf("%d",&color[i]);
        if(color[i]>MAX){
            MAX = color[i];
        }
    }

    int answer = search(1,MAX);
    printf("%d",answer);

    return 0;
}