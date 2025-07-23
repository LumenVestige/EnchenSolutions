//
// Created by sanenchen on 25-7-12.
//

#ifndef BINARY_TREE_TEST_H
#define BINARY_TREE_TEST_H
#include <vector>

#include "binary_tree.h"


class BinaryTreeTest {
public:
    static void test();
    static std::vector<int> binaryTreeBfs(TreeNode* root);
    static void binaryTreeDfsPreOrder(TreeNode *root, std::vector<int> &res);
    static void binaryTreeDfsInOrder(TreeNode *root, std::vector<int> &res);
    static void binaryTreeDfsPostOrder(TreeNode *root, std::vector<int> &res);
};


#endif //BINARY_TREE_TEST_H
