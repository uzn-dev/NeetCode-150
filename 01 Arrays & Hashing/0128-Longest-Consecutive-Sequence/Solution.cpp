class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //unordered_set查詢：O(1)
        unordered_set<int> s(nums.begin(), nums.end()); //把所有數字丟進 unordered_set去掉重複

        int longest = 0;

        for(int n : s){
            //判斷起點（若前一數字不存在，代表該數為頭）
            if(!s.count(n-1)){
                int current = n;
                int len = 1;

                //一直往後找接下來的數字
                while(s.count(current+1)){
                    current++;
                    len++;
                }

                //更新最大長度
                longest = max(longest, len);
            }
        }
        return longest;
    }
};