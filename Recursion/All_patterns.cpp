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

// for counting the number of subsequences
int countS(int ind, int s, int sum, vector<int> arr, int n){
    if(ind == n){
        if(s == sum) return 1;
        else return 0;
    }

    s += arr[ind];
    int l = countS(ind+1, s, sum, arr, n);
    s -= arr[ind];
    int r = countS(ind+1, s, sum, arr, n);
    return l+r;
}

int main(){
    vector<int> arr = {1,2,3,4};
    int k = 5;
    vector<int> ds;
    // printS(0,ds, 0, k, arr, arr.size());
    cout<<"number of subsequences with sum = k :=> "<<countS(0, 0, k, arr, arr.size())<<endl;
    return 0;
}