# 347. Top K Frequent Elements

- **難度**: Medium
- **主題**: Array, Hash Table, Sorting, Bucket Sort, Quickselect, Counting
- **連結**: [LeetCode Link](https://leetcode.com/problems/top-k-frequent-elements/)

## 💡 解題邏輯

這題的直覺解法是先算次數再 Sorting ($O(n \log n)$)，但題目要求優於 $O(n \log n)$，所以我們使用 **Bucket Sort (桶排序)**。

**核心思路：利用「頻率」當作陣列的索引 (Index)**

1.  **統計頻率**：先用 `unordered_map` 算出每個數字出現幾次。
2.  **建立桶子**：
    - 開一個 `vector<vector<int>>`，大小設為 `nums.size() + 1`。
    - **為什麼是 n+1？** 因為如果有個數字出現了 $n$ 次，我們需要索引 $n$ 的位置來放它 (索引 0~n)。
    - **索引 (Index)** = 出現次數。
    - **內容 (Value)** = 出現該次數的數字列表。
3.  **倒序收集**：
    - 因為要找「前 K 高頻」，所以從桶子的**最後面 (最大頻率)** 開始往前找。
    - 把桶子裡的數字拿出來，直到湊滿 $k$ 個為止。

## ⭐️ 複雜度分析

- **時間複雜度**: $O(n)$
  - 統計頻率 $O(n)$ + 分配入桶 $O(n)$ + 倒序收集 $O(n)$。
  - **為什麼比 Sorting 快？** 不需要比較數字大小 ($O(n \log n)$)，而是利用陣列索引的特性直接定位。
  
- **空間複雜度**: $O(n)$
  - 空間換時間，需要額外的 Map 和桶子陣列來存資料。

- **Pitfall**:
  - 記得桶子大小要開 `nums.size() + 1`，否則當某個數字全勤 (出現 n 次) 時會 Access Violation。

## 💻 Code (C++)

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Bucket Sort Approach - O(n)

        // Step 1: 統計每個數字的出現頻率
        unordered_map<int, int> vote; //[數字:次數]
        for(int n : nums){
            vote[n]++;
        }

        // Step 2: 建立桶子，索引代表頻率
        // 大小設為 size+1 是為了處理「出現 n 次」的極端情況
        vector<vector<int>> count(nums.size() + 1); // 索引 = 次數，內容 = 數字列表
        for(auto [num, freq] : vote){
            count[freq].push_back(num);
        }
        
        // Step 3: 從頻率最高的桶子開始往回找
        vector<int> ans;
        for(int i = nums.size(); i >= 0 ; --i){ // 從次數大的數字開始抓
            for(int n : count[i]){
                ans.push_back(n);
                if(ans.size() == k) return ans; // 湊滿 k 個就交卷
            }
        }
        return {};
    }
};