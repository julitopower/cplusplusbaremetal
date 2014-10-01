#ifndef TREE
#define TREE

#include <list>

using std::list;

namespace tree {

  template<class T> class TreeNode;
  
  template<class T>
  class Tree {
  public:
    Tree() : _root(0)
    {}

    ~Tree()
    {
      if (_root != 0 )
	delete _root;
    }

    void add(T value);
    bool contains(T value);
    list<T> *inOrder();
  private:
    TreeNode<T> *_root;
  };

  template<class T>
  class TreeNode {
  public:
    TreeNode(const T& value) : value(value), left(0), right(0)
    {}

    ~TreeNode()
    {
      if (left != 0)
	delete left;
      if (right != 0)
	delete right;
    }

    T value;
    TreeNode *left;
    TreeNode *right;
  };
}

#endif // TREE
