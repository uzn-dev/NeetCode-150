class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;
        for (auto [key, val] : counts) {
            if (val > 1) return true;
        }
        return false;
    }
};