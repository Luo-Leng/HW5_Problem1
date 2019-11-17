#pragma once
using namespace std;
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
        std::vector<T> result;
        LinkedStack<TreeNode<T> *> stack;
        TreeNode<T>* cur = root;
        while(cur != nullptr || !stack.isEmpty()) {
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.peek();
            stack.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override
    {

        LinkedStack<TreeNode<T> *> stk;
        LinkedStack<TreeNode<T> *> stk1;
        stk.push(root);
        std::vector<T> result;
        while (!stk.isEmpty())
        {
            TreeNode<T> *cur = stk.peek();
            stk.pop();
            stk1.push(cur);
            if (cur->left)
                stk.push(cur->left);
            if (cur->right)
                stk.push(cur->right);
        }
        while(!stk1.isEmpty()){
            result.push_back(stk1.peek()->val);
            stk1.pop();

        }

        return result;
    }



        virtual ~BinaryTree() {
            LinkedStack<TreeNode<T> *> stk;

            stk.push(root);

            while (!stk.isEmpty())
            {
                TreeNode<T> *cur = stk.peek();
                TreeNode<T> *left = cur->left;
                TreeNode<T> *right = cur->right;
                stk.pop();
               delete cur;
                if (left)
                    stk.push(left);
                if (right)
                    stk.push(right);
            }




    }

    TreeNode<T>* _LCA(TreeNode<T>* node, T value1, T value2) {
        if (node== nullptr) {
            return nullptr;
        }
        if (node->val == value1 || node->val == value2) {
            return node;
        }

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
