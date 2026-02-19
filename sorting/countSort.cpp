#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& arr){
    int n = arr.size();
    int maxVal = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>maxVal) maxVal = arr[i];
    }

    vector<int> count(maxVal+1,0);
    vector<int> output(n);
    for(int i = 0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i = 1; i<maxVal+1; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i>=0; i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    arr = output;
}


int main(){
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    vector<int> arr;
    cout<<"enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;   
        arr.push_back(val);
    }

    countSort(arr);
    
    cout<<"After the  sort---->"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    
}