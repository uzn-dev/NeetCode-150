# 271. Encode and Decode Strings

- **難度**: Medium
- **主題**: Arrays & Hashing, String Manipulation, Design
- **連結**: [NeetCode Link](https://neetcode.io/problems/string-encode-and-decode)

## 💡 解題邏輯

挑戰在於如何將「字串列表」打包成「單一字串」，並在傳輸後完美還原，且**不受內容字元干擾**（例如內容本身就包含分隔符號）。

### 解決方案：Length-Prefix Encoding (長度前綴法)
單純用分隔符號（如 `#`）是不夠的，因為內容可能包含該符號。我們必須在每個字串前加上「長度資訊」。

**格式**：`長度` + `#` + `內容`
例如 `["Hello", "World"]` $\rightarrow$ `5#Hello5#World`

- **Encode (編碼)**：遍歷列表，將每個字串轉換為 `len + "#" + str` 的形式接起來。
- **Decode (解碼)**：
  1. 使用指標 `i` 從頭掃描。
  2. 找到下一個 `#` 的位置 `j`。
  3. 截取 `i` 到 `j` 之間的數字，轉為整數 `len`。
  4. 從 `#` 後面截取 `len` 個字元作為內容。
  5. 移動 `i` 到下一段的開頭 (`j + 1 + len`)。

## ⭐️ 複雜度分析

- **時間複雜度**: $O(n)$
  - Encode: 遍歷所有字串一次。
  - Decode: 雖然有巢狀操作 (find, substr)，但指標 `i` 只會由左向右掃描一次，不會回頭。
- **空間複雜度**: $O(1)$ (Extra Space)
  - 除了儲存結果的 `ans` 以外，不需要額外的資料結構。

## 📝 新學到的語法 (New Syntax)

這題運用了 C++ 的字串處理函式：

1. **`to_string(int val)`**: 將整數轉換為字串。
   - `to_string(5)` $\rightarrow$ `"5"`
2. **`s.find(char c, int pos)`**: 從位置 `pos` 開始尋找字元 `c` 第一次出現的索引。
   - `s.find('#', i)`
3. **`stoi(string s)`**: 將字串轉換為整數 (String to Integer)。
   - `stoi("12")` $\rightarrow$ `12`
4. **`s.substr(int pos, int len)`**: 從位置 `pos` 開始，截取長度為 `len` 的子字串。
   - `s.substr(j + 1, length)`

## 💻 Code (C++)

```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string msg = "";
        for(string s : strs){
            // 格式：長度 + # + 內容
            msg += to_string(s.size()) + "#" + s;
        }
        return msg;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            // 1. 找 # 的位置 j (代表長度資訊的結束點)
            int j = s.find('#', i);
        
            // 2. 算出長度 len (截取 i 到 j 之間的數字字串)
            int len = stoi(s.substr(i, j - i));
        
            // 3. 根據 len 挖出內容並放入 ans
            // 內容從 j + 1 開始，長度為 len
            string word = s.substr(j + 1, len);
            ans.push_back(word);
        
            // 4. 更新 i 到下一組的開頭 (跳過長度、#、內容)
            i = j + 1 + len;
        }
        return ans;
    }
};