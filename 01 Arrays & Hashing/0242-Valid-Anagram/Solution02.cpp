class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; // 別忘了這個最強優化！
        
        unordered_map<char, int> freqMap;
        
        for (char c : s) {
            freqMap[c]++;
        }
        for (char c : t) {
            freqMap[c]--;
        }
        
        for (auto [c, count] : freqMap) {
            if (count != 0) return false;
        }
        return true;
    }
};