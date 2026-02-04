class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;

        //處理n個字串，時間O(n*k*logk)
        for (string s : strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); //長度為k的字串排序一次，時間O(k*logk)
            group[sorted_s].push_back(s);
        }

        //搬運n個長度為k的字串，時間O(n*k)
        for (auto& pair : group){  //這裡的&給原始資料臨時別名，零複製，直接操作原件，效能最快。
            ans.push_back(pair.second);
        }
    }
};