#include<bits/stdc++.h>
using namespace std;

// for printing any one subsequence whose sum == k;
bool printS(int ind, vector<int> &ds, int s, int sum, vector<int>& arr, int n){
    //base condition
    if(ind == n){
        if(s == sum){
            for(auto it : ds) cout<< it << " ";
            cout<<endl;
            return true;
        }
        else return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printS(ind + 1, ds, s, sum, arr, n) == true) return true;

    ds.pop_back();
    s -= arr[ind];
    if(printS(ind + 1, ds, s, sum, arr, n) == true) return true;
    return false;
}

int main(){
    vector<int> arr = {41,2,3,4};
    int k = 48;
    vector<int> ds;
    printS(0,ds, 0, k, arr, arr.size());
    return 0;
}