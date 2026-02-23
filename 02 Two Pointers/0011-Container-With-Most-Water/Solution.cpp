class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int L = 0;
        int R = height.size() - 1;

        while(L < R){
            int current_width = R - L;
            int current_height = min(height[L], height[R]);
            
            max_area = max(current_width * current_height, max_area);

            if(height[L] > height[R]) --R;
            else ++L;
        }
        return max_area;
    }
};