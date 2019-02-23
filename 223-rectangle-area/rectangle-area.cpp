// Find the total area covered by two rectilinear rectangles in a 2D plane.
//
// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//
//
// Example:
//
//
// Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
// Output: 45
//
// Note:
//
// Assume that the total area is never beyond the maximum possible value of int.
//


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = (C - A) * (D - B);
        int b = (G - E) * (H - F);
        
        int left = max(A, E);
        int bottom = max(B, F);
        int right = min(C, G);
        int top = min(D, H);
        
        int c = 0;
        if (left < right and bottom < top) c = (right - left) * (top - bottom);
        return a + b - c;
    }
};
