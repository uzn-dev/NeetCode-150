# 1. Two Sum

- **難度**: Easy
- **主題**: Array, Hash Table
- **連結**: [LeetCode Link](https://leetcode.com/problems/two-sum/)

## 💡 解題邏輯 (One-Pass Hash Table)
這題的核心在於「以空間換取時間」。我們利用 **Hash Map** 的快速查找特性 $O(1)$，在遍歷陣列的同時尋找目標。

1. **資料結構**：
   建立一個 `unordered_map<int, int>` (變數名 `seen`)，用來記錄 `{數值: 索引}`。

2. **核心步驟**：
   我們遍歷陣列 `nums`，對於當前的數字 `nums[i]`：
   - **計算目標**：算出我們需要的另一個數字 `wantNum = target - nums[i]`。
   - **查詢**：檢查 `wantNum` 是否已經在 `seen` 裡面。
     - **若存在**：代表找到了配對，直接回傳 `{seen[wantNum], i}`。
     - **若不存在**：將目前的 `{nums[i]: i}` 存入 Map，供後面的數字配對。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n)$
  - 我們只遍歷陣列一次，Hash Map 的查找與插入平均為 $O(1)$。
- **空間複雜度**: $O(n)$
  - 最壞情況下，所有的數字都找不到配對，需要將整個陣列存入 Map。

## 💻 Code (C++)
```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // key: 數值, value: 索引

        for (int i = 0; i < nums.size(); ++i) {
            int wantNum = target - nums[i];
            
            // 檢查目標數字 (wantNum) 是否已存在
            if (seen.count(wantNum)) {
                return {seen[wantNum], i}; 
            }

            // 沒找到，則記錄當前數字與位置
            seen[nums[i]] = i;
        }
        return {};
    }
};