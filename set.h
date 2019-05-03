//
// Created by alejandro on 02/05/19.
//

#ifndef DISJOINT_SET_ALEJANDRO_TANG_SET_H
#define DISJOINT_SET_ALEJANDRO_TANG_SET_H

#include "node.h"
#include <iostream>

template <typename T>
class Set {
private:
    Node<T> * root;

public:
    int rankOfRoot(){
        return root->getRank();
    }

    bool find(Node<T> * target){
        if(target->findRoot() == this->root) return true;
        else return false;
    }

    void joinArbitrary(Set<T>* other){

    }

    void printSet(){

    }
};


#endif //DISJOINT_SET_ALEJANDRO_TANG_SET_H
