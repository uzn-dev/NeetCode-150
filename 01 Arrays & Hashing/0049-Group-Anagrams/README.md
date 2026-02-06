# 49. Group Anagrams

- **難度**: Medium
- **主題**: Array, Hash Table, String, Sorting
- **連結**: [LeetCode Link](https://leetcode.com/problems/group-anagrams/)

## 💡 解題思路

這題的目標是把「重組字 (Anagrams)」歸類在一起。核心觀念在於：**如何幫每一組重組字找到一個「共同的身分證 (Key)」？**

只要這兩個字串是重組字，它們轉換出來的 Key 就應該要長得一模一樣，這樣才能丟進同一個 Hash Map 的 bucket 裡。

### 方法一：Sorting (排序法)
* **想法**：既然重組字的字母組成一樣，那把它們依照字母順序排好 (e.g., "tea" -> "aet")，長相就會一樣了。
* **作法**：把排序後的字串當作 Map 的 Key。
* **缺點**：雖然直覺，但對每個字串做 Sorting 的成本是 $O(K \log K)$，如果字串很長會比較慢。

### 方法二：Frequency Counting (最佳解)
* **想法**：重組字的定義就是「字母出現的次數相同」。我們不如直接統計 a-z 各出現幾次當作 Key。
* **操作技巧**：
    * 因為 C++ 的 `unordered_map` 不支援直接用 `vector` 當 Key。
    * 我們可以開一個 `string(26, 0)` 來模擬長度 26 的陣列（利用 ASCII `c - 'a'` 來對應索引）。
    * 這樣做就不需要排序，只要掃描一遍字串即可。
* **優點**：理論時間複雜度更優，從 $O(K \log K)$ 降到 $O(K)$。

## ⭐️ 複雜度分析

令 $N$ 為字串的總數，$K$ 為字串的最大長度。

| 方法 | 時間複雜度 | 空間複雜度 | 說明 |
| :--- | :--- | :--- | :--- |
| **Sol 1. Sorting** | $O(N \cdot K \log K)$ | $O(N \cdot K)$ | 瓶頸在於對 $N$ 個字串進行排序。 |
| **Sol 2. Counting** | $O(N \cdot K)$ | $O(N \cdot K)$ | 只需要遍歷所有字元，理論上是 Linear Time 的最佳解。 |

## 💻 Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Sol.1 Sorting O(n*k*logk)
        /*
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;

        // 處理n個字串，時間O(n*k*logk)
        for (string s : strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // 長度為k的字串排序一次，時間O(k*logk)
            group[sorted_s].push_back(s);
        }

        // 搬運n個長度為k的字串，時間O(n*k)
        for (auto& pair : group){  // 這裡的&給原始資料臨時別名，零複製，直接操作原件，效能最快。
            ans.push_back(pair.second);
        }

        return ans;
        */

        // Sol.2 Frequency Counting (Hash Map with Array Key) O(n * k) (最佳解)
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;

        for (string s : strs){
            // 利用字串模擬 array(26, 0) 作為 Key
            string count(26, 0);
            for (char c : s){
                count[c - 'a']++;
            }
            group[count].push_back(s);
        }
        
        for (auto& pair : group){
            ans.push_back(pair.second);
        }

        return ans;
    }
};