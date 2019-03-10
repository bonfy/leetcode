// Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.
//
//  
//
// Example:
//
//
// Vector2D iterator = new Vector2D([[1,2],[3],[4]]);
//
// iterator.next(); // return 1
// iterator.next(); // return 2
// iterator.next(); // return 3
// iterator.hasNext(); // return true
// iterator.hasNext(); // return true
// iterator.next(); // return 4
// iterator.hasNext(); // return false
//
//
//  
//
// Notes:
//
//
// 	Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
// 	You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.
//
//
//  
//
// Follow up:
//
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.
//


class Vector2D {
public:
    Vector2D(vector<vector<int>> V): v(V), i(v.begin()), end(v.end()), j(0) {
        
    }
    
    int next() {
        if (!hasNext()) {
            return -1;
        } else {
            return (*i)[j++];
        }
    }
    
    bool hasNext() {
        while (i != end && j >= i->size()) {
            ++i, j = 0;
        }
        return i != end;
    }
    vector<vector<int>> v;
    vector<vector<int>>::iterator i, end;
    int j;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
