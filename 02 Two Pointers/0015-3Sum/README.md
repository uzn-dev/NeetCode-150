# 15. 3Sum

- **難度**: Medium
- **主題**: Array, Two Pointers, Sorting
- **連結**: [LeetCode 15. 3Sum](https://leetcode.com/problems/3sum/)

## 💡 解題邏輯
這題的核心思想就是，把複雜的三個數簡化成 Two Sum 邏輯。因為題目規定不能有重複的組合，所以排序跟去重是這題的關鍵。

1. **先排序**：一開始就先對陣列進行 `sort`。這不但讓後面可以用雙指針，還能把一樣的數字全擠在一起，方便我們判斷跟跳過重複的組合。
2. **固定一個數字 (降維)**：用 `for` 迴圈每次抓一個數字固定當作 `i`。這時候剩下的部分，就變成在 `i` 右邊的範圍裡找兩個數字，讓這三個數字加起來等於 0。
3. **雙指針夾擊**：
   - 設左指標 `L = i + 1` (從固定的下一個數字開始)。
   - 設右指標 `R = nums.size() - 1` (從尾巴開始)。
   - 把這三個位置的數字加起來 (`sum`)：
     - 如果 `sum < 0`：代表目前的總和小了，要把左數往右移 (`++L`) 來增加總數。
     - 如果 `sum > 0`：代表目前的總和大於目標，要把右數往左移 (`--R`) 將總數變小。
     - 如果 `sum == 0`：找到我們要的組合了！存進答案陣列裡。
4. **關鍵的「去重」邏輯**（避免程式跑到越界或產出重複答案）：
   - **外層去重**：在固定 `i` 時，如果跟上一個數字重複就直接跳過 (`if(i > 0 && nums[i] == nums[i-1]) continue;`)。注意保護條件 `i > 0` 要寫在前面避免讀到 `nums[-1]`。
   - **內層去重**：當找到一組答案後，`L` 必須跳到下一個數字。如果發現新走到位置的數字跟剛剛一樣，就要用 `while` 迴圈繼續往下跳，不然會配對出重複的組合。一樣要把邊界防護 `L < R` 寫在前面 (`while(L < R && nums[L] == nums[L-1]) ++L;`)。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n^2)$
  - 陣列排序花費 $O(n \log n)$。
  - 外層迴圈跑 $n$ 次，內層雙指針最多也跑 $n$ 次，相乘為 $O(n^2)$。因為 $n^2$ 遠大於 $n \log n$，所以整體時間複雜度為 $O(n^2)$。
- **空間複雜度**: $O(1)$ 或 $O(n)$
  - 排除用來裝答案回傳的 `vector<vector<int>>`，我們只用了常數個指標變數，所以是 $O(1)$（取決於編譯器底層 `sort` 所需的空間，有些視為 $O(\log n)$ 乃至 $O(n)$）。

## 💻 Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        // 固定外層 i
        for(int i = 0; i < nums.size(); ++i){
            // 如果與上一數字重複則跳過，檢查 i > 0 避免取到 nums[-1]
            if(i > 0 && nums[i] == nums[i-1]) continue;    

            // 變成 Two Sum
            int L = i + 1;
            int R = nums.size() - 1;

            while(L < R){
                int sum = nums[i] + nums[L] + nums[R];
                
                if(sum < 0) {
                    ++L;
                } 
                else if(sum > 0) {
                    --R;
                } 
                else {
                    ans.push_back({nums[i], nums[L], nums[R]});

                    ++L;    // 跳至下一數
                    // 內層去重：如果跟前一個數字一樣就繼續跳過
                    while(L < R && nums[L] == nums[L-1]) ++L;
                }
            }
        }
        return ans;
    }
};