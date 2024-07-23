
#include "Sort.h"
#include <iostream>
#include <string>

// HeapSort implementation

class Sort::ImplSort {
/* -----      DO NOT MODIFY ABOVE THIS LINE       ----- */
    /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
    /* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
public:
  ImplSort() : root(nullptr) {}

  void insert(const std::string & key, const std::string & value)
  {
    Node* newNode = insert(value, root);
    heapifyUp(newNode);
  }

  void enumerate(std::ostream& output_file)
  {
    while (root != nullptr)
    {
      output_file << root->data << "\n";
      removeRoot();
    }
  }

private:
  struct Node
  {
    std::string data;
    Node* left;
    Node* right;
    Node* parent;

    int left_count;
    int right_count;

    Node(const std::string& value)
        : data(value), left(nullptr), right(nullptr), parent(nullptr), left_count(0), right_count(0) {}
  };

  Node* root;

  Node* insert(const std::string& value, Node*& node, Node* parent = nullptr)
  {
    if (node == nullptr)
    {
      node = new Node(value);
      node->parent = parent;
      return node;
    }
    if (node->left_count <= node->right_count)
    {
      ++(node->left_count);
      return insert(value, node->left, node);
    }

    ++(node->right_count);
    return insert(value, node->right, node);
  }

  void heapifyUp(Node* node)
  {
    if (node == nullptr || node->parent == nullptr)
      return;

    if (node->data < node->parent->data)
    {
      std::swap(node->data, node->parent->data);
      heapifyUp(node->parent);
    }
  }

  void heapifyDown(Node* node)
  {
    if (node == nullptr)
      return;

    Node* smallest = node;

    if (node->left != nullptr && node->left->data < smallest->data)
      smallest = node->left;

    if (node->right != nullptr && node->right->data < smallest->data)
      smallest = node->right;

    if (smallest != node)
    {
      std::swap(node->data, smallest->data);
      heapifyDown(smallest);
    }
  }

  void removeRoot()
  {
    if (root == nullptr)
    {
      return;
    }

    Node* last_node = getLastNode(root);
    if (last_node == root)
    {
      delete root;
      root = nullptr;
      return;
    }

    std::swap(root->data, last_node->data);

    if (last_node->parent->left == last_node)
    {
      last_node->parent->left = nullptr;
      last_node->parent->left_count--;
    }
    else
    {
      last_node->parent->right = nullptr;
      last_node->parent->right_count--;
    }

    delete last_node;
    heapifyDown(root);
  }

  Node* getLastNode(Node* node)
  {
    if (node == nullptr)
      return nullptr;

    if (node->left == nullptr && node->right == nullptr)
      return node;

    Node* left_last = getLastNode(node->left);
    Node* right_last = getLastNode(node->right);

    if (right_last != nullptr)
      return right_last;

    return left_last;
  }

  /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* -----      DO NOT MODIFY BELOW THIS LINE       ----- */

};


Sort::Sort() : implSort_(new ImplSort) {}

Sort::~Sort()
{
  delete implSort_;
}

void Sort::insert(const std::string & key, const std::string & value)
{
  implSort_->insert(key,value);
}

void Sort::enumerate(std::ostream& output_file)
{
  implSort_->enumerate(output_file);
}
