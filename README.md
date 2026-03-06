# LeetCode Algorithm Solutions

C++ 为主、Python 为辅的 LeetCode 刷题记录。

## 文件命名

| 模式 | 说明 |
|------|------|
| `T{N}.cpp` / `T{N}.py` | 第 N 题的标准解法 |
| `T{N}_{描述}.cpp` / `.py` | 特定思路或方法变体 |

示例：`T394.cpp`、`T70_palouti.py`、`T20_stack.py`

## 代码结构

每个文件自成一体，包含：

```cpp
// {题号}.{题目} # 解题思路
class Solution {
public:
    TYPE solve(PARAMS) { /* 实现 */ }
};

class Solution2 { /* 优化版本 */ };

int main() {
    Solution sol;
    // 手动测试用例
}
```

- 同一文件内用 `Solution`、`Solution2` 等依次记录不同优化版本
- 注释使用中文说明思路与权衡

## 编译运行

```bash
g++ -g T{N}.cpp -o T{N}
./T{N}
```

## 技术栈

- **C++**：STL（`vector`、`stack`、`unordered_map` 等）
- **Python**：标准库，与 C++ 版本对比学习
