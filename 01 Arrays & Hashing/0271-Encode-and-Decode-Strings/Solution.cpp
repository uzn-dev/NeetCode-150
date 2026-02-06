class Solution {
public:

    string encode(vector<string>& strs) {
        string msg = "";
        for(string s : strs){
            msg += to_string(s.size()) + "#" + s;
        }
        return msg;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            // 1. 找 # 的位置 j
            int j = s.find('#', i);
        
            // 2. 算出長度 len
            int len = stoi(s.substr(i, j - i));
        
            // 3. 根據 len 挖出內容並放入 res
            string word = s.substr(j + 1, len);
            ans.push_back(word);
        
            // 4. 更新 i 到下一組的開頭
            i = j + 1 + len;
    }
    return ans;
    }
};
