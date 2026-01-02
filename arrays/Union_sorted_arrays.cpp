#include <bits/stdc++.h>
using namespace std;


vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int i,j;
    i=0; j=0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> unionArr;

    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            if(unionArr.size()==0 || unionArr.back()!=nums1[i]){
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=nums2[j]){
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=nums2[j]){
                unionArr.push_back(nums2[j]);
            }
            j++;
    }
    while(i<n1){
        if(unionArr.size()==0 || unionArr.back()!=nums1[i]){
                unionArr.push_back(nums1[i]);
            }
            i++;
    }
    return unionArr;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);

    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    vector<int> result = unionArray(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
