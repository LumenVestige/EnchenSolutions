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
```c++
stringstream temp;
temp << "abc";
temp.put('a');
temp.str(); // 取出为string类型
```

## 数学相关的算法
### 1. 判断素数
对于素数的判断，通过一般数学层面来看的话，就是要尝试找到除了1和他本身的其他组合。  
那么，自然想到暴力解法。
```c++
bool isPrime(const int num) {
    int temp = num - 1;
    for (int i = 2; i < temp; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
```
但是，不难看出，这样的算法效率极低。仔细想想，根据基本不等式，分解出来的两个数，一定都是小于num的平方根的，大于num平方根的数就不需要考虑了
改进如下
```c++
bool isPrime(const int num) {
    int temp = sqrt(num);
    for (int i = 2; i < temp; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
```

## 算法笔记
### 1. 滑动窗口
暂时还没写
