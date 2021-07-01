# STL库的使用

---------------------------

### 1. Vector容器类

#### 1.1 获取容器长度

```c++
vector<int>& container;
int len = container.size();
```

-------

#### 1.2 获取最大/最小值及其下标

```c++
vector<int>& v;
// 最大值
int max_elm = *max_element(v.begin(), v.end());
// 最小值
int min_elm = *min_element(v.begin(), v.end());
// ------------------------ 顺序第一个最值的下标 --------------------
int max_pos = max_element(v.begin(), v.end()) - v.begin();
int min_pos = min_element(v.begin(), v.end()) - v.begin();
// ------------------------ 倒序第一个最值的下标 --------------------
int max_pos_reverse = v.size() - 1 - (max_element(v.rbegin(), v.rend()) - v.rbegin());
int min_pos_reverse = v.size() - 1 - (min_element(v.rbegin(), v.rend()) - v.rbegin());
```

