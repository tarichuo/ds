#include <iostream>
#include <list>
#include <stack>

namespace ds {

template<typename T>
class BinaryTreeNode {
public:
    BinaryTreeNode(const T &value) :
        _value(value),
        _left_child(nullptr),
        _right_child(nullptr)
    {
    }
    
    BinaryTreeNode() :
        _left_child(nullptr),
        _right_child(nullptr)
    {
    }

    bool empty(void)
    {
        return (_left_child == nullptr) && (_right_child == nullptr);
    }
    
    void inorder_traversal(void)
    {
        std::stack<BinaryTreeNode *> ptr_stack;
        
        BinaryTreeNode * curr_ptr = this;
        while (curr_ptr != nullptr || !ptr_stack.empty())
        {
            while (curr_ptr != nullptr)
            {
                ptr_stack.push(curr_ptr);
                curr_ptr = curr_ptr->_left_child;
            }

            if (!ptr_stack.empty())
            {
                curr_ptr = ptr_stack.top();
                std::cout << curr_ptr->_value << std::endl;
                ptr_stack.pop();
                curr_ptr = curr_ptr->_right_child;
            }
        }
    }

    T _value;
    BinaryTreeNode<T> * _left_child;
    BinaryTreeNode<T> * _right_child;
    
};

}

int main(int argc, char * argv[])
{
    ds::BinaryTreeNode<int> root(1);

    root._left_child = new ds::BinaryTreeNode<int>(2);
    root._right_child = new ds::BinaryTreeNode<int>(3);
    root._left_child->_left_child = new ds::BinaryTreeNode<int>(4);
    root._left_child->_right_child = new ds::BinaryTreeNode<int>(5);
    root._right_child->_left_child = new ds::BinaryTreeNode<int>(6);
    root._right_child->_right_child = new ds::BinaryTreeNode<int>(7);


    std::cout << "XXX" << std::endl;
    root.inorder_traversal();
}
