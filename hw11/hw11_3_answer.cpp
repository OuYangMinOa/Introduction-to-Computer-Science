#include <iostream>
using namespace std;

void selection_sort(int* A,int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if (A[min] > A[j]){
                min = j;
            }
        }
        swap(A[min],A[i]);
    }
}


int main(){
    int packet,student;
    cout<<"plz input the number of packet & student:\n";
    cin>>packet>>student;
    cout<<"plz input the number of chocolates in each packet:\n";
    int c[packet];
    for (int i=0;i<packet;i++){
        cin>>c[i];
    }

    selection_sort(c,packet);  // 先從小排到大

    int gap = abs(c[0]-c[student-1]); // 先假設 前 學生個巧克力 的差距是最小的
    int start = 0;  // 根據上面假設的，所以第一個位置是 0
    for (int i=1;i+student-1<packet;i++){
        if (abs(c[i]-c[i+student-1])<=gap){ // 如果發現差距更小的 就取代
            gap = abs(c[i]-c[i+student-1]);
            start = i;
        }
    }


    for (int i=start;i<start+student;i++){
        cout<<c[i]<<" ";
    }
}