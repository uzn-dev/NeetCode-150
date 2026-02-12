class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size()-1;

        while(L < R){
            int sum = numbers[L] + numbers[R];
            
            if (sum < target){
                ++L;
            }
            else if(sum > target){
                --R;
            }
            else{
                return {L+1, R+1};
            }
        }
        return {};
    }
};