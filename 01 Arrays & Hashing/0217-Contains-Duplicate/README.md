# 217. Contains Duplicate

- **難度**: Easy
- **主題**: Array, Hash Table
- **連結**: [LeetCode Link](https://leetcode.com/problems/contains-duplicate/)

## 💡 解題思路

這題的目標是檢查陣列中是否有重複元素。我們有兩種常見的 Hash 表解法：

### 方法一：Hash Set (更佳解法，比較不占空間)
由於我們只需要判斷「是否存在」，不需要計算「出現次數」，使用 `unordered_set` 是最高效的。
1. **遍歷陣列**：對於每個數字 `n`。
2. **查詢**：檢查 `n` 是否已在 `set` 中。
   - ✅ **若存在**：代表重複，直接回傳 `true` (Early Exit)。
   - ❌ **若不存在**：將 `n` 加入 `set`。
3. 若遍歷結束都沒找到，回傳 `false`。

### 方法二：Hash Map (計數法，我最初的想法)
使用 `unordered_map<int, int>` 記錄每個數字出現的次數。
- 雖然邏輯正確，但因為同時儲存了 `Key` (數字) 與 `Value` (次數)，在空間上比 Set 消耗更多，且不需要「次數」這個資訊，因此本題 **Set 優於 Map**。

## ⭐️ 複雜度分析 (Hash Set)
- **時間複雜度**: $O(n)$
  - 只需遍歷一次，查詢與插入平均為 $O(1)$。
- **空間複雜度**: $O(n)$
  - 最壞情況下（無重複），Set 需要儲存所有元素。

## 💻 Code (C++)

```cpp
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 解法選擇：
     * 雖然可以用 Map 計算次數，但使用 Set 進行查重更節省空間且語意更精確。
     */
     
    // --- Sol. 2: Unordered Set (Optimal) ---
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            // 如果已經存在 set 中，代表重複
            if (seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }

    /* // --- Sol. 1: Unordered Map (Alternative) ---
    // 雖然可行，但空間開銷較大 (儲存 key + value)
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int n : nums) counts[n]++;
        for (auto [key, val] : counts) {
            if (val > 1) return true;
        }
        return false;
    }
    */
};