# 238. Product of Array Except Self

- **難度**: Medium
- **主題**: Arrays & Hashing, Prefix/Suffix Product
- **連結**: [LeetCode Link](https://leetcode.com/problems/product-of-array-except-self/)

## 💡 解題邏輯

題目要求算出「除了自己以外」的所有數字乘積，且**不能使用除法**，並要在 $O(n)$ 時間內完成。

核心公式：**答案[i] = (i 左邊所有人的乘積) × (i 右邊所有人的乘積)**

### 方法一：Prefix & Suffix Arrays
開兩個輔助陣列：
1. `prefix`：存每個位置左邊的乘積。
2. `suffix`：存每個位置右邊的乘積。
3. 最後兩個陣列對應位置相乘就是答案。
* **缺點**：需要 $O(n)$ 的額外空間。

### 方法二：Space Optimized (最佳解)
題目進階要求 **$O(1)$ 額外空間**（輸出陣列不計入）。
我們可以利用「輸出的陣列 (`ans`)」來暫存資訊：
1. **第一輪 (由左往右)**：先計算「左積」並直接填入 `ans`。
2. **第二輪 (由右往左)**：不需要開新的陣列存右積，只要用一個變數 `R` (Running Suffix Product) 隨身攜帶目前的右邊累積乘積，邊走邊乘進 `ans` 裡即可。

## ⭐️ 複雜度分析

- **時間複雜度**: $O(n)$
  - 只需要遍歷陣列兩次。
- **空間複雜度**: 
  - **Sol 1**: $O(n)$ (使用了額外的 `prefix` 和 `suffix` 陣列)。
  - **Sol 2**: $O(1)$ (除了回傳用的 `ans` 陣列外，只用了一個變數 `R`)。

## 💻 Code (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Sol.1 Prefix & Suffix Arrays (Space O(n))
        /*
        int n = nums.size();
        vector<int> prefix(n, 1); // 左積陣列
        vector<int> suffix(n, 1); // 右積陣列
        vector<int> ans(n);

        // 1. 計算左積：prefix[i] = prefix[i-1] * nums[i-1]
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        // 2. 計算右積：suffix[i] = suffix[i+1] * nums[i+1]
        for(int i = n - 2; i >= 0; --i){
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        // 3. 合併
        for(int i = 0; i < n; ++i){
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
        */

        // Sol.2 Space Optimized (Space O(1))
        int n = nums.size();
        vector<int> ans(n, 1); // 直接用 ans 暫存左積，初始化為 1
        
        // 1. 第一輪：算出左積直接存入 ans
        for(int i = 1; i < n; ++i){
            ans[i] = ans[i-1] * nums[i-1];
        }

        // 2. 第二輪：由右往左掃描，使用變數 R 取代 suffix 陣列
        int R = 1; // R 代表目前右邊累積的乘積
        for(int i = n - 1; i >= 0; --i){
            ans[i] = ans[i] * R; // 左積 * 右積 = 答案
            R = R * nums[i];     // 更新 R，乘入當前的數字，給下一位(i-1)使用
        }

        return ans;        
    }
};