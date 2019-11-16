#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        // homework, to be done iteratively
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
    }

    virtual ~BinaryTree() {
        // homework
    }

    TreeNode<T>* _LCA(TreeNode<T>* node, T value1, T value2) {
        if (node== nullptr) {
            return nullptr;
        }

        // check root
        if (node->val == value1 || node->val == value2) {
            return node;
        }

        // check both childrens
        TreeNode<T>* left = _LCA(node->left, value1, value2);
        TreeNode<T>* right = _LCA(node->right, value1, value2);

        if (left!= nullptr && right!= nullptr) {
            return node;
        }

        if (left == nullptr && right == nullptr) {
            return nullptr;
        }

        return left == nullptr ? right : left;
    }
    T LCA(T node1, T node2) {
        TreeNode<T>* node = _LCA(root, node1, node2);
        return node == nullptr ? -1 : node->val;
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
