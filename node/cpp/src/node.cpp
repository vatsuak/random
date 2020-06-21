#include "Node.h"
#include <iostream>

// template <class T>
Node::Node(){
    value = 0;
    child = NULL;
}

// template <class T>
Node::Node(int value, Node &child){
    this->value = value;
    this->child = &child;
}

// template <class T>
std::ostream & operator<<(std::ostream &o, Node &node){
    o<<node.value;
    return o;
}
int Node::get_child(){
    return child->value;
}