class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;

        for (string s : strs){
            string count(26, 0);
            for (char c : s){
                count[c - 'a']++;
            }
            group[count].push_back(s);
        }
        for (auto& pair : group){
            ans.push_back(pair.second);
        }

        return ans;
    }
};