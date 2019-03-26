#include <iostream>

using namespace std;

int N,M;
int marble[302];
int answer[301];
int ans_size = 1;

int ans = 0;

void print_ans_array(){
    int need = M - ans_size; // number of categories needed
    for(int i=0;i<ans_size;i++){
        if(answer[i] == 1){
            printf("%d ", answer[i]);
        }else{
            while(answer[i]>1 && need > 1){
                printf("1 ");
                answer[i]--;
                need--;
            }
            printf("%d ", answer[i]);
        }
    }
}

void make_ans_array(int biggest){
    // Initialize answer array
    for(int i=0;i<N;i++){
        answer[i] = 0;
    }
    int temp = 0;
    for(int i=0;i<N;i++){
        temp += marble[i];
        answer[ans_size-1] += 1;
        if(temp>biggest){ // if temp is bigger, change temp to current / revert coung / add new count / add ans_size
            temp = marble[i];
            answer[ans_size-1] -= 1;
            answer[ans_size] = 1;
            ans_size += 1;
        }
    }
}

bool valid(int mid){
    int temp = 0;
    int num = 1;
    bool validness = true;
    for(int i=0;i<N;i++){
        if(marble[i]<=mid){
            temp += marble[i]; // add current marble
            if(temp>mid){ // if temp is bigger than max value -> add num and clear temp
                temp = marble[i];
                num ++;
            }
        }else{
            validness = false;
            break;
        }
    }
    if(num>M){
        validness = false;
    }
    return validness;
}

int search(int left, int right){
    if(left<=right){
        int mid = (left+right)/2;
        if(valid(mid)){
            // valid
            if(mid<ans){
                ans = mid;
            }
            search(left,mid-1);
        }else{
            // not valid
            search(mid+1,right);
        }
    }
    return ans;
}

int main(){
    scanf("%d %d",&N, &M);
    for(int i=0;i<N;i++){
        scanf("%d", &marble[i]);
    }
    ans = 100*N;
    int result = search(0,100*N);
    printf("%d\n", result);

    // make answer array based on result
    make_ans_array(result);
    // print answer array based on rule
    print_ans_array();
    return 0;
}