class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //Bucket Sort

        unordered_map<int, int> vote; //[數字:次數]
        for(int n : nums){
            vote[n]++;
        }

        vector<vector<int>> count(nums.size()+1); //索引 = 次數，內容 = 數字列表
        for(auto [num, freq] : vote){
            count[freq].push_back(num);
        }
        
        vector<int> ans;
        for(int i = nums.size(); i >= 0 ; --i){ //從次數大的數字開始抓
            for(int n : count[i]){
                ans.push_back(n);
                if(ans.size() == k) return ans;
            }
        }
        return {};
    }
};