#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    queue<int> q;
    for(int i=0;i<100;i++){
        cout << "enqueing " << i << endl;
        q.push(i);
    }
    cout << "length of queue" << q.size() << endl;
    cout << "last of queue" << q.back() << endl;

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}