class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i){
            int wantNum = target - nums[i];
            
            if(seen.count(wantNum)){
                return {seen[wantNum], i}; 
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};