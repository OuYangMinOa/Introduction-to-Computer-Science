#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int num,exp;
    cout<<"input a number :";
    cin>>num;
    
    cout<< int (num/pow( 10,int( log10(num) ) ) );

    return 0;
}