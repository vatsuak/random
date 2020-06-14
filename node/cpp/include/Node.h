#ifndef NODE_H
#define NODE_H

#include <iostream>

// template <class T>
class Node{
    friend std::ostream & operator<<(std::ostream &o, Node &node);
    private:
        int value;
        Node *child;
    public:
        Node();
        Node(int value,Node &child);
        int get_child();
};
#endif