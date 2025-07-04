#include <iostream>
#include <thread>

#include "hashmap.h"
#include "hashmap-test.h"
using namespace std;

void hashmap_test::test() {
    // // 初始化操作
    // unordered_map<int, string> hashMap;
    // // 添加操作
    // hashMap[1997] = "123";
    // hashMap[2008] = "三";
    // // 访问操作
    // cout << hashMap[1997] << endl;
    // // 删除操作
    // hashMap.erase(1997);
    //
    // /* 遍历Hash表 */
    // // 遍历键值对
    // for (const auto&[fst, snd] : hashMap) {
    //     cout << fst << ":" << snd << endl;
    // }
    // for (const auto& kv : hashMap) {
    //     cout << kv.first << ":" << kv.second << endl;
    // }
    // // 使用迭代器
    // for (auto iter = hashMap.begin(); iter != hashMap.end(); iter++) {
    //     cout << iter->first << ":" << iter->second << endl;
    // }

    HashMap<int, string> map;
    map[1] = "HashMap"; // 赋值
    cout << map[1] << endl;
    map.erase(1); // 删除
    map[1] = "Map";
    cout << map[1] << endl; //输出


    // // 多线程测试
    //
    // thread t1([](HashMap<int, string> &hash_map) {
    //     int counter = 0;
    //     while (true) {
    //         hash_map[counter] = to_string(counter);
    //         counter++;
    //         if (counter == 1000) {
    //             return;
    //         }
    //     }
    // }, ref(map));
    //
    // thread t2([](HashMap<int, string> &hash_map) {
    //     int counter = 0;
    //     while (true) {
    //         cout << hash_map[counter] << "//";
    //         hash_map.erase(counter);
    //         counter++;
    //         if (counter == 1000) {
    //             return;
    //         }
    //     }
    // }, ref(map));
    // thread t3([](HashMap<int, string> &hash_map) {
    //     int counter = 0;
    //     while (true) {
    //         cout << hash_map[counter] << "//";
    //         hash_map.erase(counter);
    //         counter++;
    //         if (counter == 1000) {
    //             return;
    //         }
    //     }
    // }, ref(map));
    // t1.join();
    // t2.join();
    // int a = 0;
    // int *b = &a;
    // *b = 2;
    // a=2;
    // printf("%d", *b);
}


// // TIP 要<b>Run</b>代码，请按 <shortcut actionId="Run"/> 或点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
// int main() {
//     // TIP 当文本光标位于 <b>lang</b> 变量名称处时，按 <shortcut actionId="RenameElement"/> 可以查看 CLion 如何帮助您重命名该变量。
//     auto lang = "C++";
//     std::cout << "Hello and welcome to " << lang << "!\n";
//
//     for (int i = 1; i <= 5; i++) {
//         // TIP 按 <shortcut actionId="Debug"/> 开始调试代码。我们已为您设置了一个 <icon src="AllIcons.Debugger.Db_set_breakpoint"/> 断点，但您可以随时按 <shortcut actionId="ToggleLineBreakpoint"/> 添加更多断点。
//         std::cout << "i = " << i << std::endl;
//     }
//     return 0;
//     // TIP 请访问 <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a> 查看 CLion 帮助。此外，您还可以从主菜单中选择“帮助 | 学习 IDE 功能”，尝试 CLion 的交互式课次。
// }
