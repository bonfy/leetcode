// Given a nested list of integers, implement an iterator to flatten it.
//
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
// Example 1:
//
//
//
// Input: [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// Explanation: By calling next repeatedly until hasNext returns false, 
//              the order of elements returned by next should be: [1,1,2,1,1].
//
//
// Example 2:
//
//
// Input: [1,[4,[6]]]
// Output: [1,4,6]
// Explanation: By calling next repeatedly until hasNext returns false, 
//              the order of elements returned by next should be: [1,4,6].
//
//
//
//


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillstk(nestedList);
    }

    int next() {
        int n = stk.top().getInteger();
        stk.pop();
        return n;
    }

    bool hasNext() {
        while (!stk.empty()) {
            auto p = stk.top();
            if (p.isInteger()) {
                return true;
            } else {
                stk.pop();
                auto lst = p.getList();
                fillstk(lst);
            }
        }
        return false;
    }
    stack<NestedInteger> stk;
    void fillstk(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = n - 1; i >= 0; i--) {
            stk.emplace(nestedList[i]);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
