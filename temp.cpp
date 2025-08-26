#include<iostream>
#include<math.h>
using namespace std;


int main(){
    int nsp, nst;
    int td, ld,dd,rd;
    int n=9;
    int sd;
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            td = i;
            ld = j;
            dd = 2*n-2-i;
            rd = 2*n-2-j;
            sd = min(min(td,dd),min(rd,ld));
            cout<<n-sd<<" ";
        }
        cout<<endl;
    }
    return 0;
}