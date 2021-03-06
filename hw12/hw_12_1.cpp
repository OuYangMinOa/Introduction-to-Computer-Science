#include <iostream>
using namespace std;

int count(int *A,int n,int num){ // 算出 num 在 A 矩陣裡面出現幾次
    int time = 0;
    for (int i=0;i<n;i++){
        if (A[i]==num)
            time++;
    }
    return time;
}


int main(){

    int n;
    cout<<"plz input the number of value\n";
    cin>>n;
    int A[n];
    cout<<"plz input the value\n";
    for (int i=0;i<n;i++){
        cin>>A[i];
    }

    // 想法是製作出一個次數矩陣
    // say for example :
    // 題目矩陣 : 2 5 2 8 5 6 8 8
    // 次數矩陣 : 2 2 2 3 2 2 3 3 << 相對應'元素'出現在'題目矩陣'的次數
    // 之後對 次數矩陣 做排序，由大排到小
    // 而 題目矩陣 也跟著做同樣的動作 (元素交換)
    // 這樣出現次數高的數字就會到前面

    int times[n];  // 製造出次數矩陣
    for (int i=0;i<n;i++){
        times[i] = count(A,n,A[i]); // 回傳 A[i] 在 A 出現的次數
    }
    

    for (int i=0;i<n;i++){
        for (int j=0;j<n-1-i;j++){
            if (times[j] < times[j+1]){
                swap(times[j],times[j+1]); // 次數矩陣交換
                swap(A[j],A[j+1]);         // 題目矩陣跟著換
            }
        }
    }
        
    // 處理先來後到的問題

    // 排完後 :
    // 題目矩陣 : 8 8 8 2 5 2 5 6
    // 次數矩陣 : 3 3 3 2 2 2 2 1
    // 想法是先找到 前後次數相同 但數字不同的 位置 i
    // 然後 往後搜尋去找到 跟 位置i 一樣的數字
    // 在跟 i+1 做交換... 再找，i+2 做交換... 再找，i+3 做交換... 


    for (int i=0;i<n-1;i++){
        if (times[i]==times[i+1] && A[i]!=A[i+1]){
            for (int j=i+2;j<n-1;j++){
                if (A[i]==A[j]){
                    swap(A[++i],A[j]);
                }
            }
        }
    }


    
    for (int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    
}




