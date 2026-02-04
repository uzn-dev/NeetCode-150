class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> counts;
        for (int n : nums){
            if(counts.count(n)) return true;
            counts.insert(n);
        }
        return false;
    }
};