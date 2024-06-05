#include <utility>
#include <iostream>

using namespace std;

template<typename T>
class binary_search_tree
{
public:
  binary_search_tree()
  {
    root = nullptr;
  }

  const T& min( )
  {
    return (min(root)->element);
  }

  const T& max( )
  {
    return (max(root)->element);
  }

  bool contains( const T& x )
  {
    if (is_empty())
      return false;

    return contains(x, root);
  }

  bool is_empty( )
  {
    return is_empty(root);
  }

  void insert( const T& x )
  {
    insert(x, root);
  }

  void print( )
  {
    if(!is_empty())
      print(root, cout);
  }


private:

  struct binary_node
  {
    T element;
    binary_node* left;
    binary_node* right;

    binary_node(const T& an_element, binary_node* l, binary_node* r) :
      element { an_element }, left{ l }, right{ r } { }

    binary_node(const T&& an_element, binary_node* l, binary_node* r) :
      element { std::move(an_element) }, left{ l }, right{ r } { }
  };

  binary_node* root = nullptr;

  void insert ( const T& x, binary_node*& t )
  {
    if (t == nullptr)
    {
      t = new binary_node(x, nullptr, nullptr);
    }
    else if (x < t->element)
    {
      insert(x, t->left);
    }
    else if (x > t->element)
    {
      insert(x, t->right);
    }
  }

  binary_node* min(binary_node* t)
  {
    if(t->left == nullptr)
      return t;

    return min(t->left);
  }

  binary_node* max(binary_node* t)
  {
    if(t->right == nullptr)
      return t;

    return max(t->right);
  }

  bool is_empty(binary_node* t)
  {
    return (t == nullptr);
  }

  bool contains(const T& x, binary_node* t)
  {
    if (t == nullptr)
      return false;

    else if(x > t->element)
      return contains(x, t->right);

    else if(x < t->element)
      return contains(x, t->left);

    else
      return true;
  }

  void print(binary_node* t, ostream& out )
  {
    if(t == nullptr)
      return;

    print(t->left, out);
    out << t->element << endl;
    print(t->right, out);
  }

};


int main()
{
  binary_search_tree<int> bst;
  int x;

  while(cin >> x)
  {
    bst.insert(x);
  }

  bst.print();

  cout << "Minimal element = " << bst.min() << "\n";
  cout << "Maximal element = " << bst.max() << "\n";

}