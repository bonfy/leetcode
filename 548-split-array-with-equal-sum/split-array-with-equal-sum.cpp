//
// Given an array with n integers, you need to find if there are triplets  (i, j, k) which satisfies following conditions:
//
//  0 < i, i + 1 < j, j + 1 < k < n - 1 
//  Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal. 
//
// where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
//
//
// Example:
//
// Input: [1,2,1,2,1,2,1]
// Output: True
// Explanation:
// i = 1, j = 3, k = 5. 
// sum(0, i - 1) = sum(0, 0) = 1
// sum(i + 1, j - 1) = sum(2, 2) = 1
// sum(j + 1, k - 1) = sum(4, 4) = 1
// sum(k + 1, n - 1) = sum(6, 6) = 1
//
//
//
// Note:
//
//  1 <= n <= 2000. 
//  Elements in the given array will be in range [-1,000,000, 1,000,000]. 
//


class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int i=0, j=nums.size()-2;
        int s=0; vector<int> sum;
        for(auto x: nums)
        {
            s+=x;
            sum.push_back(s);
        }
        int total = sum.back();
        for(j=nums.size()-2; j>i; j--)
        {
            for(i=0; i<j-1; i++)
            {
                if(sum[i]==total-sum[j]) //found i+1 = x, j = z
                {
                    int y = total - 4*sum[i] - nums[i+1] - nums[j]; 
                    for(int k = i+1+1; k < j-1; k++)
                        if(nums[k] == y) return true;
                }
            }
            i=0;
        }
        return false;
    }
};
