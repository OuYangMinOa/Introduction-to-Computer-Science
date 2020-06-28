#include <bits/stdc++.h>
using namespace std;

double func(float x){
    return exp(-x)*sin(5*x);
}

double integrate(double up, double down, int n){
    double delta_x = (up - down) / n;
    double a,b;

    double ans = func(up) + func(down);
    for (int i=1;i<n-1;i+=2){
        a = down + delta_x*(i);
        b = down + delta_x*(i+1);
        ans += 4*func(a)+2*func(b);
    }
    ans = delta_x/3*ans;
    return ans;
}

// 這是另外一個辛普森
double integrate_2(double up, double down, double n){ 
    double delta_x = (up - down) / n;
    double a,b;
    double ans_2 = 0;
    for (int i=0;i<n;i++){
        a = down + delta_x*(i);
        b = down + delta_x*(i+1);
        ans_2 += (func(a)+func(b)+4*func((a+b)/2));
    }
    ans_2 = delta_x/6*ans_2;
    return ans_2;
    
}


int main(void){
    double up = 1, down = -5;
    double exact_ans = 29.03890175153003;
    double ans, error;

    printf("\n|   n   |  ans        |  exact      |  error(%%)  |\n");
    for (int i=50;i<=1000;i+=50){
        ans = integrate(up,down,i);  
        //ans = integrate_2(up,down,i); //可以自己改看看，看一下哪個比較準
        error = abs(exact_ans - ans)/exact_ans*100;
        printf("| %5d | %-3.8f | %-3.8f | %-3.8f |\n",i,ans,exact_ans,error);
    }

}