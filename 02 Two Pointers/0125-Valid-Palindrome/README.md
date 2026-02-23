# 125. Valid Palindrome

- **難度**: Easy
- **主題**: Two Pointers, String
- **連結**: [LeetCode Link](https://leetcode.com/problems/valid-palindrome/)

## 💡 解題邏輯
這題的核心是判斷字串是否為「迴文」(Palindrome)，即正讀和反讀都一樣。
由於題目要求**忽略大小寫**且**只考慮字母與數字**，我們使用 **雙指針 (Two Pointers)** 技巧：

1.  **初始化指針**：
    -   左指針 `L` 指向字串開頭 (`0`)。
    -   右指針 `R` 指向字串結尾 (`s.size() - 1`)。
2.  **向中間逼近** (`while L < R`)：
    -   **過濾無效字符**：若 `L` 或 `R` 指向的不是字母或數字，則移動指針並跳過。
    -   **比較字符**：將兩邊字符統一轉為**小寫** (`tolower`) 後比較。
        -   若**不相等**：直接回傳 `false`。
        -   若**相等**：`L` 往右移，`R` 往左移，繼續檢查下一組。
3.  **結束條件**：
    -   若迴圈跑完都沒有發現不相等的情況，則回傳 `true`。

## ⭐️ 複雜度分析
- **時間複雜度**: $O(n)$
  - 每個指針最多移動 $n$ 次，總共遍歷字串一次。
- **空間複雜度**: $O(1)$
  - 只使用了兩個整數變數 (`L`, `R`)，沒有額外使用與輸入大小相關的空間。

## 📝 新學到的語法 (C++)
| 語法 | 功能 | 範例 |
| :--- | :--- | :--- |
| **`isalnum(char c)`** | 檢查字符是否為**字母 (A-Z, a-z)** 或 **數字 (0-9)**。<br>需引入 `<cctype>`。 | `isalnum('A')` $\rightarrow$ `true`<br>`isalnum(',')` $\rightarrow$ `false` |
| **`tolower(char c)`** | 將大寫字母轉為小寫字母。若原本就是小寫或符號則不變。<br>需引入 `<cctype>`。 | `tolower('A')` $\rightarrow$ `'a'` |

## 💻 Code (C++)

```cpp
#include <iostream>
#include <string>
#include <cctype> // 必須加入，用於 isalnum 和 tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;

        while (L < R) {
            // 1. 左邊遇到非字母/數字 -> 跳過
            if (!isalnum(s[L])) {
                L++;
                continue; 
            }
            
            // 2. 右邊遇到非字母/數字 -> 跳過
            if (!isalnum(s[R])) {
                R--;
                continue;
            }

            // 3. 兩邊都是合法字符，轉小寫比較
            if (tolower(s[L]) != tolower(s[R])) {
                return false; // 不一樣就不是迴文
            }

            // 4. 一樣的話，縮小範圍繼續檢查
            L++;
            R--;
        }

        return true; // 全部檢查完畢
    }
};