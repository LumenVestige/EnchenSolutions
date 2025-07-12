//
// Created by sanenchen on 25-7-12.
//

#include "binary_tree-test.h"
#include "queue"
#include  "iostream"
using namespace std;

void BinaryTreeTest::test() {
    // 二叉树的初始化
    // C++ 语法小点
    // &代表取地址，*代表着解引用
    // 这里的auto* n1 中 n1 代表着一个地址
    auto *n1 = new TreeNode(1);
    auto *n2 = new TreeNode(2);
    auto *n3 = new TreeNode(3);
    auto *n4 = new TreeNode(4);
    auto *n5 = new TreeNode(5);
    auto *n6 = new TreeNode(6);
    auto *n7 = new TreeNode(7);
    // 构建节点间的引用
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    // 在n1 n2 之间插入一个P
    auto *P = new TreeNode(0);
    n1->left = P;
    P->left = n2;
    // 删除节点P
    n1->left = n2;
    delete P;

    // // bfs 遍历
    // for (auto &it: binaryTreeBfs(n1)) {
    //     cout << it << " ";
    // }

    // dfs 先序遍历
    vector<int> result;
    binaryTreeDfsPreOrder(n1, result);
    for (auto& it : result) {
        cout << it << " ";
    }
    cout << endl;
    // dfs 中序遍历
    result.clear();
    binaryTreeDfsInOrder(n1, result);
    for (auto& it : result) {
        cout << it << " ";
    }
    cout << endl;
    // dfs 后序遍历
    result.clear();
    binaryTreeDfsPostOrder(n1, result);
    for (auto& it : result) {
        cout << it << " ";
    }
    cout << endl << int(1/2);

    // 清空内存
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;
    delete n7;

}

/**
 * bfs 遍历
 * @param root
 * @return vector<int> 遍历结果
 */
vector<int> BinaryTreeTest::binaryTreeBfs(TreeNode *root) {
    queue<TreeNode *> tree_queue;
    vector<int> result;
    tree_queue.push(root);
    while (!tree_queue.empty()) {
        const TreeNode *now = tree_queue.front();
        // 保存当前值
        result.push_back(now->val);
        tree_queue.pop(); // 这一个遍历结束，最前面的出列
        if (now->left != nullptr)
            tree_queue.push(now->left);
        if (now->right != nullptr)
            tree_queue.push(now->right);
    }
    return result;
}


/**
 * dfs 先序遍历
 * 一条路走到黑，直到撞墙
 * 访问优先级：根节点->左节点->右节点
 * 实现使用递归实现
 * @param root
 * @return
 */
void BinaryTreeTest::binaryTreeDfsPreOrder(TreeNode *root, vector<int>& res) {
    if (root == nullptr)
        return;
    res.push_back(root->val);
    binaryTreeDfsPreOrder(root->left, res);
    binaryTreeDfsPreOrder(root->right, res);
}


/**
 * dfs 中序遍历
 * 一条路走到黑，直到撞墙
 * 访问优先级：左节点->根节点->右节点
 * 实现使用递归实现
 * @param root
 * @return
 */
void BinaryTreeTest::binaryTreeDfsInOrder(TreeNode *root, vector<int>& res) {
    if (root == nullptr)
        return;
    binaryTreeDfsInOrder(root->left, res);
    res.push_back(root->val);
    binaryTreeDfsInOrder(root->right, res);
}


/**
 * dfs 后序遍历
 * 一条路走到黑，直到撞墙
 * 访问优先级：左节点->右节点->根节点
 * 实现使用递归实现
 * @param root
 * @return
 */
void BinaryTreeTest::binaryTreeDfsPostOrder(TreeNode *root, vector<int>& res) {
    if (root == nullptr)
        return;
    binaryTreeDfsPostOrder(root->left, res);
    binaryTreeDfsPostOrder(root->right, res);
    res.push_back(root->val);
}
