# 242. Valid Anagram

- **難度**: Easy
- **主題**: String, Hash Table, Sorting
- **連結**: [LeetCode Link](https://leetcode.com/problems/valid-anagram/)

## 💡 解題思路

判斷兩個字串是否為「異位詞」(Anagram) 的核心在於：**字元出現的種類與次數必須完全相同**。

### 方法一：Fixed-Size Array (最佳解)
由於題目限制通常為小寫英文字母 ('a'-'z')，我們可以使用一個長度為 26 的陣列來當作「計數器」，這比 Hash Map 更快且更省記憶體。
1. **長度檢查**：若 `s` 與 `t` 長度不同，直接回傳 `false` (最強優化)。
2. **計數**：
   - 遍歷 `s`：對應字元位置 `+1`。
   - 遍歷 `t`：對應字元位置 `-1`。
3. **驗證**：檢查陣列中是否所有數值都歸零。若有非 0 的值，代表次數不匹配。

### 方法二：Hash Map (通用解)
若題目包含 **Unicode** (如中文、表情符號)，陣列大小無法預知，此時應改用 `unordered_map<char, int>`。
- 邏輯與上述相同，但空間複雜度會隨字元集大小增加。

## ⭐️ 複雜度分析 (Array 解法)
- **時間複雜度**: $O(n)$
  - 需要遍歷字串 `s` 和 `t` 各一次。
- **空間複雜度**: $O(1)$
  - 雖然我們使用了額外空間，但陣列大小固定為 26 (常數)，與輸入長度 $n$ 無關。

## 💻 Code (C++)

```cpp
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // --- Sol. 1: Frequency Array (Optimal for 'a'-'z') ---
        // 時間: O(n), 空間: O(1) (固定 26)
        
        // 1. 基礎長度檢查 (最強優化)
        if (s.length() != t.length()) return false;
        
        // 2. 宣告長度 26 的計數陣列
        vector<int> counts(26, 0); 
        
        // 3. 統計頻率：s 加, t 減
        for(char c : s) {
            counts[c - 'a']++;
        }
        for(char c : t) {
            counts[c - 'a']--;
        }

        // 4. 驗證是否完全抵銷
        for(int c : counts) {
            if(c != 0) return false;
        }
        return true;

        // --- Sol. 2: Unordered Map (For Unicode support) ---
        /*
        unordered_map<char, int> freqMap;
        for (char c : s) freqMap[c]++;
        for (char c : t) freqMap[c]--;
        for (auto [key, val] : freqMap) {
            if (val != 0) return false;
        }
        return true;
        */
    }
};