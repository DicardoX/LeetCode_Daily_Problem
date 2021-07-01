# STL库的使用

---------------------------

### 1. Vector容器类

**头文件 `#include <vector>`**

#### 1.1 基本操作

- 初始化：

```c++
std::vector<std::wstring> v1;                //创建一个空的wstring类型的vector
std::vector<std::wstring> v2(3, L"c");       //创建一个容量为3，全部初始化L"c"
std::vector<int> v3(5);                      //创建容量为5，数据类型为int的vector
std::vector<int> v4(v3);                     //创建一个从v3拷贝过来的vector
std::vector<int> v5 = {1,2,3,4,5,6,7};       //C++11才支持，直接值初始化，最方便
```

- 获取容器长度：

```c++
vector<int>& container;		// 参数传递
int len = container.size();
```

- 获取最大值/最小值及下标：

```c++
vector<int>& v;						// 参数传递
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

- **排序**：

```c++
vector<int>& v;						// 参数传递
sort(v.begin(), v.end());
```

- **插入元素**：

```c++
vector<int>& v;						// 参数传递
// 在指定位置插入
v.insert(v.begin()+4, 1);
// 在末尾插入
v.push_back(1);
v.insert(v.end(), 1);
// 在开头插入
v.insert(v.begin(), 1);
```

- **迭代器输出**：

```c++
vector<int>& v;						// 参数传递
// 顺序输出
for(auto itr = v.begin(); itr < v.end(); it++) {
	cout << *itr;
}
// 逆序输出
for(auto itr = v.rbegin(); itr < v.rend(); it++) {
	cout << *itr;
}
```



--------

#### 1.2 特殊的vector

- 函数返回空的vector：`return {};`
- 

------

#### 1.4 Vector排序

-----

#### 1.5 二维容器vector<vector\<int\>>

```c++
// 声明（C++11之前为 vector<vector<int> > v;）
vector<vector<int>> v;
// 插入元素
vector<int> tmp_v;
tmp_v.push_back(1);
v.push_back(tmp_v);
// 
```



