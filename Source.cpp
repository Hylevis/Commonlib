#include "lib/array.h"
#include <vector>
#include <iostream>
#include "lib/staticarray.h"
#include "lib\SinglyLinkedList.h"
#include "lib/BinarySearchTree.h"
#include "lib/AVLTree.h"


void ArrayTest();
void StaticArrayTest();
void QueueTest();

template <typename type>
class BinaryTree
{
public:
    struct Treenode
    {
        type m_Data;
        Treenode* m_Parent = nullptr;
        Treenode* m_Left = nullptr;
        Treenode* m_Right = nullptr;


    };

    BinaryTree() = default;
    //private:
    Treenode* m_Root = nullptr;
};

bool find(const BinaryTree<int>::Treenode* node, int value)
{
    while (node != nullptr)
    {
        if (node->m_Data == value)
        {
            return true;
        }

        if (value < node->m_Data)
        {
            node = node->m_Left;
        }
        else if (value > node->m_Data)
        {
            node = node->m_Right;
        }
    }
    return false;
}

bool findRecursive(const BinaryTree<int>::Treenode* node, int value)
{
    if (node->m_Data == value)
    {
        return true;
    }

    if (value < node->m_Data)
    {
        node = node->m_Left;
    }
    else if (value > node->m_Data)
    {
        node = node->m_Right;
    }
    while (node != nullptr)
    {
        return false;
    }
    return findRecursive(node, value);

}
void TreeTest()
{
    BinaryTree<int> tree;
    tree.m_Root = new BinaryTree<int>::Treenode{ 5 };
    tree.m_Root->m_Left = new BinaryTree<int>::Treenode{ 2, tree.m_Root };
    tree.m_Root->m_Right = new BinaryTree<int>::Treenode{ 6, tree.m_Root };
    tree.m_Root->m_Left->m_Left = new BinaryTree<int>::Treenode{ 1, tree.m_Root->m_Left };
    tree.m_Root->m_Left->m_Right = new BinaryTree<int>::Treenode{ 3, tree.m_Root->m_Left };
    tree.m_Root->m_Left->m_Right->m_Right = new BinaryTree<int>::Treenode{ 4, tree.m_Root->m_Left->m_Right };

    find(tree.m_Root, 4);
}


int main()
{
   
   
    std::cout << std::endl;
    std::cout << std::endl;
    AVLTree<std::string> tree{ "h", "c", "e", "f", "a" , "z", "x", "r", "t", "b", "g"};
    AVLTree<std::string>::node* testnode = tree.GetRoot();
    tree.printTree(testnode, nullptr, false);

    std::cout << std::endl;
    std::cout << std::endl;
    AVLTree<std::string> tree2{ "a", "b", "c", "d", "e", "f", "g", "h"};
    AVLTree<std::string>::node* testnode2 = tree2.GetRoot();
    tree2.printTree(testnode2, nullptr, false);

    std::cout << std::endl;
    std::cout << std::endl;
    tree2.remove("d");
    tree2.printTree(testnode2, nullptr, false);
    return 0;
}


template <typename type>
void OutputArray(const type& values)
{
    std::cout << std::endl;
    for (unsigned int i = 0; i < values.size(); ++i)
    {
        std::cout << values[i] << " ";
    }
}

void StaticArrayTest()
{

    StaticArray<int, 10> test = { 1, 2, 3,};
    test.Insert(4, 2);
    test.AddUnique(1);
    StaticArray<int, 10> test2 = test;
    test2.RemoveAt(2);
    OutputArray(test2);
}
void ArrayTest()
{

    Array<int> testInt({ 1, 2, 3, 4 });
    Array<int> testInt2({ 1, 2, 3, 4 });
    Array<std::string> testString({ "a", "b", "c", "d" });
    std::cout << "\n ARRAY STUFF\n";
    OutputArray(testInt);
    testInt = { 4, 3, 2, 1, 0 };
    OutputArray(testInt);
    std::vector<int> vectortestint = { 4, 3, 2, 1, 0 };
    OutputArray(testInt);
    auto testend = vectortestint.end()--;
    std::cout << std::endl;
    
   
    auto sortComparison = [](const int& left, const int& right)
    {
        return left < right;
    };
    std::vector<int> vectortestint2{ 1,2,3,4,5 };

    std::vector<int>::reverse_iterator testit = vectortestint2.rbegin();
    std::vector<int>::reverse_iterator testit2 = ++vectortestint2.rbegin();




    if (testit < testit2)
    {
        std::cout << testit2[1] << std::endl;
    }

   
    for (const int& value : testInt)
    {
        std::cout << value << " ";
    }


}

template <typename type>
class Queue
{
public:
    Queue() = default;

    void enqueue(type value)
    {
        m_Data.Add(value);
    }

    void dequeue()
    {
        assert(!m_Data.IsEmpty());
        m_Data.RemoveAt(m_Data.begin());
    }

    const type& front() const
    {
        assert(!m_Data.IsEmpty());
        return m_Data[0];
    }

    unsigned int size() const
    {
        return m_Data.size();
    }
private:
    Array<type> m_Data;
};

template <typename type>
class Stack
{
public:
    Stack() = default;

    void push(type value)
    {
        m_Data.Add(value);
    }

    void pop()
    {
        assert(!m_Data.IsEmpty());
        m_Data.Remove(m_Data.end()-1);
    }

    const type& top() const
    {
        assert(!m_Data.IsEmpty());
        return m_Data[m_Data.size() -1];
    }

    unsigned int size() const
    {
        return m_Data.size();
    }
private:
    Array<type> m_Data;
};

void QueueTest()
{
    Queue<int> blah;
    blah.enqueue(1);
}
