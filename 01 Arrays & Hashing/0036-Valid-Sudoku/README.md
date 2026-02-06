# 36. Valid Sudoku

- **難度**: Medium
- **主題**: Array, Hash Table, Matrix
- **連結**: [LeetCode Link](https://leetcode.com/problems/valid-sudoku/)

## 💡 解題邏輯

題目要求驗證一個 9x9 的數獨盤面是否有效（行、列、九宮格都不能有重複數字）。
**不需要解出數獨**，只要檢查**現有的數字**是否違規即可。

### 策略：一次遍歷 (One Pass)
不需要分別跑三次迴圈來檢查行、列和九宮格。可以只遍歷一次盤面，同時把數字登記在三個「計分板」上。

**資料結構：**
使用三個二維陣列來記錄數字是否出現過：
1. `row[9][10]`：第 `i` 行，數字 `num` 是否出現過？
2. `col[9][10]`：第 `j` 列，數字 `num` 是否出現過？
3. `box[9][10]`：第 `k` 個九宮格，數字 `num` 是否出現過？
   *(註：大小開 10 是為了讓數字 1-9 能直接對應 Index，比較直覺)*

**九宮格索引 (Box Index)：**
如何將座標 `(i, j)` 轉換成 0~8 的九宮格編號？
> `box_idx = (i / 3) * 3 + (j / 3)`
> - `i / 3` 決定是第幾排的九宮格 (0, 1, 2)
> - `j / 3` 決定是第幾列的九宮格 (0, 1, 2)

## ⭐️ 複雜度分析

- **時間複雜度**: $O(1)$ (因為盤面大小固定是 $9 \times 9 = 81$，視為常數時間
- **空間複雜度**: $O(1)$ (我們使用了固定大小的輔助陣列)

## 📝 新學到的語法/技巧

1. **Char 轉 Int**: `int num = board[i][j] - '0';`
   - 利用 ASCII 碼相減，將字元 `'5'` 轉為整數 `5`。
2. **九宮格映射**: 利用整數除法 `(i/3)*3 + (j/3)` 將二維座標映射到一維區域索引。

## 💻 Code (C++)

```cpp
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 初始化三個計分板，全部歸零
        // row[i][num] 代表第 i 行是否出現過數字 num
        // 使用 10 是為了讓 index 直接對應數字 1-9
        int row[9][10] = {0};
        int col[9][10] = {0};
        int box[9][10] = {0};

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                // 遇到空格直接跳過
                if(board[i][j] == '.') continue;
                
                // 將字元轉為數字 (ASCII)
                int num = board[i][j] - '0';
                
                // 計算九宮格索引 (0~8)
                int box_idx = (i / 3) * 3 + (j / 3);

                // 檢查是否曾經出現過
                if(row[i][num] || col[j][num] || box[box_idx][num]){
                    return false;
                }
                
                // 如果沒出現過，就設為 1
                row[i][num] = col[j][num] = box[box_idx][num] = 1;
            }
        }
        return true;
    }
};