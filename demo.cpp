#include<bits/stdc++.h>
using namespace std;

void revarr(int* l, int* r){
    if(l>=r) return;
    swap(*l,*r);
    revarr(l+1,r-1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    revarr(&arr[0],&arr[4]);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}