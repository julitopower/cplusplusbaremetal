#define BOOST_TEST_MODULE TreeTests

#include <boost/test/unit_test.hpp>
#include <Tree.ipp>
#include <string>

using namespace tree;

BOOST_AUTO_TEST_CASE( ConstructorTest )
{
  Tree<int> t;
  BOOST_CHECK_EQUAL(0, t.inOrder()->size());
}

BOOST_AUTO_TEST_CASE( AddOneElementTest )
{
  Tree<int> t;
  t.add(3);
  std::list<int> *listInOrder = t.inOrder();
  BOOST_CHECK_EQUAL(1, listInOrder->size());
  BOOST_CHECK_EQUAL(3, listInOrder->front());
  delete listInOrder;
}

BOOST_AUTO_TEST_CASE( InOrderTest )
{
  Tree<int> t;
  t.add(3);
  t.add(5);
  t.add(4);
  std::list<int> l;
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  std::list<int> *listInOrder = t.inOrder();
  BOOST_CHECK_EQUAL(3, listInOrder->size());
  for (std::list<int>::iterator it = l.begin() ; it != l.end() ; ++it) {
    BOOST_CHECK_EQUAL(*it, listInOrder->front());
    listInOrder->pop_front();
  }
  delete listInOrder;
}

BOOST_AUTO_TEST_CASE( AddOneElementStringTest )
{
  Tree<std::string> t;
  t.add("there");
  t.add("hi");
  std::list<std::string> *listInOrder = t.inOrder();
  BOOST_CHECK_EQUAL(2, listInOrder->size());
  BOOST_CHECK_EQUAL("hi", listInOrder->front());
  listInOrder->pop_front();
  BOOST_CHECK_EQUAL("there", listInOrder->front());
  delete listInOrder;
}


