#include <iostream>
#include <utility>      // std::swap
#include <math.h>
using namespace std;
typedef long long ll;
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>

#define max_num 1000

int main() {
    int N=3;
    int S[][max_num]={{1,2,3},{2,3,5},{3,5,6},{2,3,4},{1,2,3}};
    int count[max_num];
    for(int i=0;i<2*N-1;i++){
        for(int j=0;j<N;j++){
            count[S[i][j]]+=1;
        }
    }
    for(int i=0;i<max_num;i++){
        if(count[i]%2!=0){
            cout<<i<<"\n";
        }
    }
    return 0;
}
