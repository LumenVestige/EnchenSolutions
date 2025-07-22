//
// Created by sanenchen on 25-7-3.
//

#include "LeetCodes.h"

using namespace std;
// 入口程序
void LeetCodes::run() {
    // T1 两数之和
    // vector<int> v = {2,7,11,15};
    // constexpr int target = 9;
    // for (auto &item: twoSum(v, target)) {
    //     cout << item << " ";
    // }

    // 456周赛 T1
    // for (auto &item: partitionString("xm")) {
    //     cout << item << " ";
    // }

    // T3304 找出第 K 个字符 I
    // cout << kthCharacterI(500) << endl;

    // T3307 找出第 K 个字符 II 未解决 超时
    // vector<int> operations = {0,1,0,1};
    // cout << kthCharacterII(10, operations) << endl;

    // T394 找幸运数 哈希表 set
    // vector<int> arr = {1,2,2,3,3,3};
    // cout << findLucky(arr) << endl;

    // T50 快速幂
    // cout << myPow(2,999) << endl;

    // T3 无重复字符的最长子串
    // cout << lengthOfLongestSubstring("dvdf") << endl;

    // T30 串联所有单词的子串 未解决 超时
    // vector<string> words = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
    // string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    // for (auto it : findSubstring(s, words)) {
    //     cout << it << " ";
    // }

    // 25.7.5 双周赛
    // T1 16进制和36进制的转化
    // cout << concatHex36(13) << endl;

    // 3169 无需开会的工作日 // 超时 未解决
    // int days = 10;
    // vector<vector<int> > meetings = {{5, 7}, {1, 3}, {9, 10}};
    // cout << countDays(days, meetings);

    // 457 周赛
    // Q1. T3606 优惠券校验器
    // vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    // vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    // vector<bool> isActive = {true,true,true,true};
    // for (auto& item : validateCoupons(code, businessLine, isActive)) {
    //     cout << item << " ";
    // }

    // 2410 运动员和训练师最大的匹配数
    // 贪心 排序 双指针
    // 贪心 找到最优解
    // vector<int> players = {4,7,9};
    // vector<int> trainers = {8,2,5,8};
    // cout << matchPlayersAndTrainers(players, trainers);

    // 周赛458 Q1 用特殊操作处理字符串
    // cout << processStr("a#b%*");

    // 周赛458 Q3 用特殊操作处理字符串 II 超出内存限制的做法
    // cout << processStr("%edx#n#lkc####uom##qg#%#b#ek%##%%ocr#m%#fv%i%%#n#u%%#n#q%v#rwvd##t###%#%%%o*##r#gr*gz#dm%ez",4780);

    // 2 两数相加
    // ListNode* root_l1 = new ListNode(5);
    // root_l1->next = new ListNode(6);
    // ListNode* root_l2 = new ListNode(5);
    // root_l2->next = new ListNode(4);
    // root_l2-next->next = new ListNode(9);
    // addTwoNumbers(root_l1, root_l2);

    // 双周赛 25-9-19 Q1
    // vector<int> nums = {-602741550,-243097563,435785956,-567926486,-462415908};
    // cout << splitArray(nums);

    // 双周赛 25-9-19 Q2 错误解答 没搞定
    vector<vector<int> > grid = {
        {0},
        {0},
        {0},
        {10},
        {0}

    };
    cout << countIslands(grid, 10);

    // 1470 重新排列数组
    //shuffle()

    // 周赛 459
    // cout << checkDivisibility(23);
}
