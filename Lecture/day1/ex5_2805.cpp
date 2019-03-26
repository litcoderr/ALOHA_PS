#include <iostream>
using namespace std;
int n_tree, need;
int tree[1000010];
int MAX = 0;
long long result = 0;

bool valid(int mid){
	bool validity = true;
	long long temp = 0;
	for(int i=0;i<n_tree;i++){
		long long t = tree[i]-mid;
		if(t>0){
			temp += t;
		}
	}
	if(temp < need){
		validity = false;
	}
	return validity;
}

int search(int left, int right){
	if(left <= right){
		int mid = (left+right)/2;
		if(valid(mid)){
			result = mid;
			search(mid+1,right);			
		}else{
			search(left,mid-1);
		}
	}
	return result;
}
int main(){
	scanf("%d %d",&n_tree,&need);	
	for(int i=0;i<n_tree;i++){
		scanf("%d",&tree[i]);
		if(MAX < tree[i]){
			MAX = tree[i];
		}
	}
	int answer = search(0,MAX-1);
	printf("%d",answer);
	return 0;
}
