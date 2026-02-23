class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;

        int max_L = height[L];
        int max_R = height[R];

        int ans = 0;

        while(L < R){
            //1. 找短板
            if(max_L < max_R){
                //2. 移動指針
                ++L;

                //3. 更新最高峰
                max_L = max(max_L, height[L]);

                //4. 計算水量
                ans += max_L - height[L];
            }
            else{
                --R;
                max_R = max(max_R, height[R]);
                ans += max_R - height[R];
            }
        }
        return ans;
    }
};