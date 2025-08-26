#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"enter the size of the array";
    int x;
    cin>>x;
    int arr[x];
    cout<<"enter the elements of the array";
    for(int i=0; i<x; i++){
        cin>>arr[i];
    }

    //using array hashing:---
    // cout<<"enter the highest no. till which numbers can be stored in the array: ";
    // int q;
    // cin>>q;
    // //precompute
    // int hash[q+1] = {0};
    // for(int i=0; i<x; i++){
    //     hash[arr[i]]+=1;
    // }

    // int n;
    // cout<<"enter the no. of times u want to check: ";
    // cin>>n;
    // while(n--){
    //     int number;
    //     cin>>number;
    //     //fetch
    //     cout<<hash[number];

    // }

    // using Map hashing :---
    map<int,int> hash;
    for(int i=0; i<x; i++){
        hash[arr[i]]++;
    }

    int n;
    cout<<"enter the no. of times u want to check: ";
    cin>>n;
    while(n--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }



    return 0;
}
