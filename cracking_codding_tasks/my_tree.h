#pragma once
#include <iostream>
#include <list>
#include <vector>

template<typename T>
class Tree {
    template<typename T>
    class Node {
    public:
        Node(T name = T()) : name(name), right(nullptr), left(nullptr) {}
        T name;
        Node* right;
        Node* left;
    };
    Node<T>* root;
private:
    void pushPreOrderTraversal(Node<T>* node, Node<T>* temp_node);
    void preOrderTraversalShow(Node<T>* node);

public:
    Tree() : root(nullptr) {};
    ~Tree() {};
    void push(const T& el);
    void show() { preOrderTraversalShow(root); }
    std::vector<std::list<T>> make_lists();
};


template<typename T>
inline void Tree<T>::pushPreOrderTraversal(Node<T>* node, Node<T>* temp_node)
{
    if (temp_node->name > node->name)
    {
        if (node->right != nullptr)
        {
            pushPreOrderTraversal(node->right, temp_node);
        }

        if (node->right == nullptr)
        {
            node->right = temp_node;
        }
    }
    else
    {
        if (node->left != nullptr)
        {
            pushPreOrderTraversal(node->left, temp_node);
        }

        if (node->left == nullptr)
        {
            node->left = temp_node;
        }
    }
}

template<typename T>
inline void Tree<T>::push(const T& el)
{
    Node<T>* temp_node = new Node<T>(el);
    if (root == nullptr)
    {
        root = temp_node;
    }
    else
    {
        pushPreOrderTraversal(root, temp_node);
    }
}

template<typename T>
inline std::vector<std::list<T>> Tree<T>::make_lists()
{
    
}

template<typename T>
inline void Tree<T>::preOrderTraversalShow(Node<T>* node)
{
    if (node != nullptr)
    {
        std::cout << node->name << std::endl;
        preOrderTraversalShow(node->left);
        preOrderTraversalShow(node->right);
    }
}
