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
	std::vector<std::list<T>> vec_lists;
	std::list<T> list;
	void width_first_traversal(Node<T>* node);
public:
	Tree() : root(nullptr) {};
	~Tree() {};
	void push(const T& el);
	void show() { preOrderTraversalShow(root); }
	std::vector<std::list<T>> make_lists();
	std::vector<std::list<T>> make_lists_recursive();
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
	Node<T>* node = root;
	std::list<T> list;
	list.push_back(node->name);
	std::vector<std::list<T>> vec_lists;
	vec_lists.push_back(list);
	Node<T>* temp_right = root->right;

	while (node != nullptr)
	{
		list.clear();
		Node<T>* temp = node;

		node = node->left;
		if (node != nullptr)
		{
			list.push_back(node->name);
		}
		node = temp;
		node = node->right;
		if (node != nullptr)
		{
			list.push_back(node->name);
		}
		node = temp->left;
		if (temp->left == nullptr && temp->right == nullptr)
		{
			node = temp_right;
			temp_right = nullptr;
		}

		if (!list.empty())
		{
			vec_lists.push_back(list);
		}
	}
	return vec_lists;
}

template<typename T>
inline std::vector<std::list<T>> Tree<T>::make_lists_recursive()
{
	list.push_back(root->name);
	vec_lists.push_back(list);
	width_first_traversal(root);
	return vec_lists;
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

template<typename T>
inline void Tree<T>::width_first_traversal(Node<T>* node)
{
	list.clear();
	if (node->left != nullptr)
	{
		list.push_back(node->left->name);
	}
	if (node->right != nullptr)
	{
		list.push_back(node->right->name);
	}

	if (!list.empty())
	{
		vec_lists.push_back(list);
	}

	if (node->left != nullptr)
	{
		width_first_traversal(node->left);
	}
	if (node->right != nullptr)
	{
		width_first_traversal(node->right);
	}
}
