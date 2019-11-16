#include "BinaryTree.h"
#include "gtest/gtest.h"



BinaryTree<int>* generateTree() {
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));
    BinaryTree<int> *tree = new BinaryTree<int>(root);

    return tree;
}

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}
TEST(tree, LCA) {
    BinaryTree<int>* tree = generateTree();
    ASSERT_EQ(tree->LCA(4, 4), 4);
    ASSERT_EQ(tree->LCA(7, 7), 7);
    ASSERT_EQ(tree->LCA(7, 3), 8);
    ASSERT_EQ(tree->LCA(7, 8), 8);
    ASSERT_EQ(tree->LCA(8, 6), 4);
    ASSERT_EQ(tree->LCA(3, 2), 4);
delete tree;
}

