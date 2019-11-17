#include "BinaryTree.h"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;



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


TEST(tree,destructor){
    BinaryTree<int>* tree = generateTree();
    delete tree;
    ASSERT_EQ(TreeNode<int>::getCount(),7);
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



TEST(tree,inorder_iterative){
    BinaryTree<int>* tree = generateTree();
    std::vector<int> answer{7,8,3,4,2,6,9};

    ASSERT_EQ(answer,tree->traverseInOrder());

}



TEST(tree,postorder_iterative){
    BinaryTree<int>* tree = generateTree();
    std::vector<int> answer{7,3,8,2,9,6,4};

    ASSERT_EQ(answer,tree->traversePostOrder());

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

