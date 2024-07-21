
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

  }

  void enumerate(std::ostream& output_file)
  {

  }

private:
  struct Node {
    bool isWord;
    bool hasData;
    std::string data;
    Node* children[26];

    Node() : hasData(false), isWord(false)
    {
      for (int i = 0; i < 26; ++i)
      {
        children[i] = nullptr;
      }
    }

  };

  Node* root;


  void insert(const std::string& str, Node*& node, int count)
  {
    if (node == nullptr)
    {
      node = new Node;
    }

    if (count < str.length())
    {
      int index = str[count] - 'A';

      if (node->children[index] == nullptr)
      {
        node->children[index] = new Node;
        node->children[index]->data = str[count];
        node->children[index]->hasData = true;
      }

      if (count + 1 == str.length())
      {
        node->children[index]->isWord = true;
      }
      else
      {
        insert(str, node->children[index], count + 1);
      }
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



