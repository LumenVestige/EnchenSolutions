# 学习笔记

## 踩过的坑
### 1. C++中字符串的快速新增字符
如果使用
```C++
string a = "abc";
a += 'c';
```
则会导致字符串的重新复制，导致复杂的内存操作

可以使用
```C++
stringstream temp;
temp.str("abc");
temp.put('a');
temp.str(); // 取出为string类型
```