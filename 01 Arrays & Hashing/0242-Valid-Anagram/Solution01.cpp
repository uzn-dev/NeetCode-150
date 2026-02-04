class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> counts(26, 0); //宣告一個長度 26，全部填 0 的陣列
        for(char c : s){
            counts[c - 'a']++;
        }
        for(char c : t){
            counts[c - 'a']--;
        }

        for(int c : counts){
            if(c != 0) return false;
        }
        return true;
    }
};