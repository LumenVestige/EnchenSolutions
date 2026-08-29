#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main() {
    constexpr int SIZE = 32768;
    constexpr int ITERATIONS = 50000;
    
    std::vector<int> data(SIZE);
    
    // 填充 0~255 的随机数
    std::mt19937 rng(1337);
    std::uniform_int_distribution<int> dist(0, 255);
    for (int &x : data) {
        x = dist(rng);
    }

    // ----------------------------------------------------
    // 测试 1：在【未排序（随机）】数组上跑循环
    // ----------------------------------------------------
    long long sum_unsorted = 0;
    auto start_unsorted = std::chrono::high_resolution_clock::now();

    for (int iter = 0; iter < ITERATIONS; ++iter) {
        for (int i = 0; i < SIZE; ++i) {
            if (data[i] >= 128) {
                sum_unsorted += data[i];
            }
        }
    }

    auto end_unsorted = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_unsorted = end_unsorted - start_unsorted;

    // ----------------------------------------------------
    // 排序数组
    // ----------------------------------------------------
    auto start_sorted = std::chrono::high_resolution_clock::now();
    std::sort(data.begin(), data.end());

    // ----------------------------------------------------
    // 测试 2：在【已排序】数组上跑完全相同的循环
    // ----------------------------------------------------
    long long sum_sorted = 0;


    for (int iter = 0; iter < ITERATIONS; ++iter) {
        for (int i = 0; i < SIZE; ++i) {
            if (data[i] >= 128) {
                sum_sorted += data[i];
            }
        }
    }

    auto end_sorted = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_sorted = end_sorted - start_sorted;

    // ----------------------------------------------------
    // 输出结果对比
    // ----------------------------------------------------
    std::cout << "未排序数组耗时: " << elapsed_unsorted.count() << " ms (sum=" << sum_unsorted << ")\n";
    std::cout << "已排序数组耗时: " << elapsed_sorted.count()   << " ms (sum=" << sum_sorted << ")\n";
    std::cout << "性能提升倍数:   " << elapsed_unsorted.count() / elapsed_sorted.count() << "x\n";

    return 0;
}