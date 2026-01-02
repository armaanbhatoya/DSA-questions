#include <bits/stdc++.h>
using namespace std;


vector<int> intersection_arr(vector<int>& nums1, vector<int>& nums2) {
    int i,j;
    i=0; j=0;
    int n,m;
    n = nums1.size();
    m = nums2.size();
    vector<int> ans;

    while(i<n && j<m){
        if(nums1[i]<nums2[j]) i++;
        else if(nums1[i]>nums2[j]) j++;
        else{
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return ans;
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

    vector<int> result = intersection_arr(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
