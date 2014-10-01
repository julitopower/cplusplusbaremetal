#ifndef TREE_IPP
#define TREE_IPP

#include <Tree.hpp>

namespace tree {

  template<class T>
  void Tree<T>::add(T value) {
    _root = addToNode(_root, value);
  }

  template<class T> TreeNode<T> * addToNode(TreeNode<T> *node, T value) {
    if (node == 0)
      return new TreeNode<T>(value);
    if (value > node->value)
      node->right = addToNode(node->right, value);
    else if (value < node->value)
      node->left = addToNode(node->left, value);
    return node;
  }


  template<class T>
  list<T> * Tree<T>::inOrder() {
    list<T> *l = new list<T>();
    inorder(_root, *l);
    return l;
  }

  template<class T> void inorder(TreeNode<T> *node, list<T> &l) {
    if (node == 0)
      return;
    inorder(node->left, l);
    l.push_back(node->value);
    inorder(node->right, l);
  }
}

#endif //TREE_IPP