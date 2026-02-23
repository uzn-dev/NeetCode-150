# 11. Container With Most Water

- **難度**: Medium
- **主題**: Array, Two Pointers, Greedy
- **連結**: [LeetCode 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

## 💡 解題邏輯
這題的核心就是物理學的**「木桶效應」**加上演算法的**「貪心策略 (Greedy)」**。
水桶能裝多少水，永遠取決於**最矮**的那塊木板。

1. **初始狀態 (貪最大寬度)**：
   - 左指標 `L` 放開頭，右指標 `R` 放結尾，先拿到最大的「寬度」。
   - 計算目前面積：`寬度 * min(左板高, 右板高)`，並更新歷史最大面積。
2. **移動策略 (汰弱留強)**：
   - 每次移動指標，寬度一定會減 1。
   - **如果移動高的那根**：水位上限還是被原本矮的那根卡死，面積絕對變小，毫無意義。
   - **所以永遠只動矮的那根！** 捨棄短板往內找，才有機會遇到更高的木板，讓整體面積突破極限。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n)$
  - 左右指針相向而行，最多碰頭一次，整個陣列只遍歷了一遍。
- **空間複雜度**: $O(1)$
  - 只使用了常數個整數變數 (`max_area`, `L`, `R`, `current_width`, `current_height`)，不需要額外開陣列。

## 💻 Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // 為了使用 max 和 min

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int L = 0;
        int R = height.size() - 1;

        while (L < R) {
            int current_width = R - L;
            // 高度取決於短板
            int current_height = min(height[L], height[R]);
            
            // 更新歷史最大面積
            max_area = max(current_width * current_height, max_area);

            // 誰矮就捨棄誰，換下一個試試看
            if (height[L] > height[R]) {
                --R;
            } else {
                ++L;
            }
        }
        return max_area;
    }
};