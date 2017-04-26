// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


func twoSum(nums []int, target int) []int {
    t := make(map[int]int)
    for i, v := range nums {
        num, ok := t[v] 
        if ok {
            return []int{num, i}
        } else {
            t[target - v] = i
        }
    }
    return []int{-1, -1}
}
