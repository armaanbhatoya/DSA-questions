#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++) 
        {
            if(arr[j]<arr[mini]) mini = j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int didSwap = 0;      //for best case tc = O(n)
        for(int j = 0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap = 0){ break; }
    }
}

void insertion_sort(int arr[], int n){
    for (int i = 0; i <= n-1; i++)
    {
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp; 
        j--;    
       }
    }
}

void merge(int arr[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right <= high){
        if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
        else  temp.push_back(arr[right++]);
    }
    while(left<=mid){
        temp.push_back(arr[left++]);
    }
    while(right<=high){
        temp.push_back(arr[right++]);
    }
    for(int i = low; i<=high; i++) arr[i] = temp[i-low];
}

void merge_sort(int arr[], int low, int high){
    if(low >= high) return;
    int mid = (low+high) / 2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int findp(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i<j)
    {
       while(arr[i]<=pivot && i <= high-1) i++;       
       while(arr[j]>pivot && j >= low+1) j--;    
       if(i<j) swap(arr[i],arr[j]);   
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int partition = findp(arr,low,high );
        quick_sort(arr, low, partition - 1);
        quick_sort(arr, partition + 1, high);
    }
}

int main(){
    int n;
    cout<<"enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }


    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);

    // merge_sort(arr,0,n-1);
    quick_sort(arr,0,n-1);

    cout<<"After the  sort---->"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    
}