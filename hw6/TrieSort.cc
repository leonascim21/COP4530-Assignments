
#include "Sort.h"
#include <iostream>
#include <string>

// TrieSort implementation

class Sort::ImplSort
{

  /* -----      DO NOT MODIFY ABOVE THIS LINE       ----- */
  /* ----- YOUR CODE GOES IN BETWEEN THESE COMMENTS ----- */
  /* vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv */
public:
  ImplSort() : root(nullptr) {}

  void insert(const std::string & key, const std::string & value)
  {
    insert(key,key.substr(0, 10), root, 0);
  }

  void enumerate(std::ostream& output_file)
  {
    enumerate(root, output_file);
  }

private:
  struct Node
  {
    bool isWord;
    std::string data;
    Node* children[26];

    Node() : isWord(false), data("")
    {
      for (int i = 0; i < 26; i++)
        children[i] = nullptr;
    }
  };

  Node* root;

  void insert(const std::string& str, const std::string& subSrting, Node*& node, int count)
  {
    if (node == nullptr)
      node = new Node();

    if (count == subSrting.length())
    {
      node->isWord = true;
      node->data = str;
      return;
    }

    int index = subSrting[count] - 'A';
    if (!node->children[index])
      node->children[index] = new Node();

    insert(str, subSrting, node->children[index], count + 1);
  }

  void enumerate(Node* node, std::ostream& output_file)
  {
    if (node == nullptr)
      return;

    if (node->isWord)
      output_file << node->data << std::endl;

    for (int i = 0; i < 26; i++)
    {
      if (node->children[i] != nullptr)
        enumerate(node->children[i], output_file);
    }
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



