class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        //固定外層i
        for(int i = 0; i < nums.size(); ++i){
            //如果與上一數字重複則跳過
            if(i > 0 && nums[i] == nums[i-1]) continue;    //檢查i>0避免取到nums[-1]

            //變成Two Sum
            int L = i + 1;
            int R = nums.size() - 1;

            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                if(sum < 0) ++L;
                else if(sum > 0) --R;
                else{
                    ans.push_back({nums[i], nums[L], nums[R]});

                    ++L;    //跳至下一數
                    while(L < R && nums[L] == nums[L-1]) ++L;
                }
            }
        }
        return ans;
    }
};