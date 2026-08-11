// what
// I need to calculate the maximum area

// which pattern
// I can do it with two pointers

// how
// lets have two pointers, left and right

// we calculate the max area, then compare left and right
// which one is smaller than the other one, move it


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int area = (right - left) * (min(heights[left], heights[right]));

            maxArea = area > maxArea ? area : maxArea;

            if (heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
                
    }
};
