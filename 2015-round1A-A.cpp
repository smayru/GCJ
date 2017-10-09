#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

#define max_num 1000
#define N 6
int main() {
    
    int A[N]={23,90,40,0,100,9};
    
    //method1
    int num_eaten_1=0;
    for(int i=0;i<N-1;i++){
        if(A[i+1]<A[i]){
            int tmp=A[i]-A[i+1];
            num_eaten_1+=tmp;
        }
    }
    cout<<num_eaten_1<<"\n" ;

    
    //method2
    int max_value=-1;
    for(int i=0;i<N-1;i++){
        max_value=max(max_value,A[i]-A[i+1]);
    }
    int num_eaten_2=0;
    for(int i=0;i<N-1;i++){
        int tmp=min(A[i],max_value);
        num_eaten_2+=tmp;
    }
    cout<<num_eaten_2<<"\n" ;

    
    
    return 0;
}
