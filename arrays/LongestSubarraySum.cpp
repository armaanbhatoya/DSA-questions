// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) { 
        //   -----------------------optimal solution for only non-negatives
        int right = 0;
        int left = 0;
        int n = nums.size();
        long long sum = nums[0];
        int maxL = 0;
        while(right<n){
            while(sum > k && left<=right) {
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                maxL = max(maxL,right-left+1);
            }
            right++;
            if(right<n){
                sum += nums[right];
            }
        }
        return maxL;

        

    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.longestSubarray(nums, k);

    return 0;
}
