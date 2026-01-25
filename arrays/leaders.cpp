//Given an integer array nums, return a list of all the leaders in the array.

//A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      vector<int> ans;
      int maxi = INT_MIN;
      int n = nums.size();
      for(int i = n-1; i>=0; i--){
        if(nums[i]>maxi){
            maxi = nums[i];
            ans.push_back(nums[i]);
        }
      }
      return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    vector<int> res = obj.leaders(nums);

    // if you want leaders in left-to-right order:
    reverse(res.begin(), res.end());

    for(int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << (i + 1 < (int)res.size() ? " " : "");
    }
    cout << "\n";

    return 0;
}
