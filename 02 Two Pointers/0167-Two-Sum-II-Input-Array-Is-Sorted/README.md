# 167. Two Sum II - Input Array Is Sorted

- **難度**: Medium
- **主題**: Two Pointers, Array
- **連結**: [LeetCode Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

## 💡 解題邏輯
這題與標準 Two Sum 最大的不同在於 **Input Array 已經排序 (Sorted)**。
利用這個特性，使用 **雙指針 (Two Pointers)** 來達到 $O(n)$ 的時間複雜度與 $O(1)$ 的空間複雜度。

1.  **初始化**：
    -   `L` (左指針) 指向陣列頭部 (最小值)。
    -   `R` (右指針) 指向陣列尾部 (最大值)。

2.  **移動策略** (`while L < R`)：
    -   計算當前總和 `sum = numbers[L] + numbers[R]`。
    -   **若 `sum > target`**：代表總和**太大**。因為陣列是遞增的，為了讓總和變小，我們必須移動右指針 (`R--`) 去找較小的數。
    -   **若 `sum < target`**：代表總和**太小**。為了讓總和變大，我們必須移動左指針 (`L++`) 去找較大的數。
    -   **若 `sum == target`**：找到答案！

3.  **回傳結果**：
    -   題目要求 **1-based index** (索引從 1 開始)，所以回傳 `{L + 1, R + 1}`。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n)$
  - 兩個指針從兩端往中間移動，最差情況下遍歷整個陣列一次。
- **空間複雜度**: $O(1)$
  - 只使用了常數個變數 (`L`, `R`, `sum`)。

## 💻 Code (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;

        while (L < R) {
            int sum = numbers[L] + numbers[R];
            
            if (sum < target) {
                // 總和太小 -> 左指針往右移 (找大的)
                ++L;
            }
            else if (sum > target) {
                // 總和太大 -> 右指針往左移 (找小的)
                --R;
            }
            else {
                // 找到目標 -> 回傳 1-based index
                return {L + 1, R + 1};
            }
        }
        return {};
    }
};