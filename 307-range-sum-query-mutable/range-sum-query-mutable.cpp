// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
//
// Example:
//
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
//
//
// Note:
//
//
// 	The array is only modifiable by the update function.
// 	You may assume the number of calls to update and sumRange function is distributed evenly.
//
//


class NumArray {
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        BIT.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int d = val - nums[i];
        nums[i] = val;
        add(i + 1, d);
    }
    
    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
    void add(int i, int val) {
        while (i <= nums.size()) {
            BIT[i] += val;
            i += i & (-i);
        }
    }
    int sum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += BIT[i];
            i -= i & (-i);
        }
        return ans;
    }
    vector<int> BIT;
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
