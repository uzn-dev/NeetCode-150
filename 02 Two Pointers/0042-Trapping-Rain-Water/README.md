# 42. Trapping Rain Water

- **難度**: Hard
- **主題**: Array, Two Pointers
- **連結**: [LeetCode 42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

## 💡 解題邏輯
這題的核心是看**每一格（單格）能積多少水**。
單格水深公式：`min(左邊最高峰, 右邊最高峰) - 腳下陸地高度`。

為了把 $O(n^2)$ 的暴力解降到 $O(n)$，我們引入**Two Pointers與木桶效應**：
1. **設定雙指針與歷史最高峰**：`L` 在頭，`R` 在尾。同時維護兩個變數 `max_L` 和 `max_R`，記錄左右兩端看過的最高山峰。
2. **尋找短板 **：
   - 如果 `max_L < max_R`：左邊是短板！這代表左邊的水位上限已經被徹底鎖死，不管中間有沒有更高的山，左邊的水位最高就是 `max_L`。
   - 此時可以安心移動左指針 (`++L`)，更新 `max_L`，並將 `max_L - height[L]` 累加到總水量中（因為先更新了 `max_L`，保證相減絕對 $\ge 0$）。
3. **反之亦然**：如果 `max_R <= max_L`，右邊是短板，那就安心移動右指針 (`--R`) 並結算右邊的水量。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n)$
  - 左右指針相向而行，最多只會碰頭一次，整個陣列僅掃描一遍。
- **空間複雜度**: $O(1)$
  - 只使用了常數個整數變數 (`L`, `R`, `max_L`, `max_R`, `ans`)。直接捨棄了需要 $O(n)$ 空間的動態規劃 (Prefix/Suffix Array) 寫法，達成最優解。

## 💻 Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int L = 0;
        int R = height.size() - 1;

        int max_L = height[L];
        int max_R = height[R];

        int ans = 0;

        while(L < R){
            // 1. 找短板
            if(max_L < max_R){
                // 2. 移動指針
                ++L;
                // 3. 更新最高峰
                max_L = max(max_L, height[L]);
                // 4. 計算水量
                ans += max_L - height[L];
            }
            else{
                --R;
                max_R = max(max_R, height[R]);
                ans += max_R - height[R];
            }
        }
        return ans;
    }
};