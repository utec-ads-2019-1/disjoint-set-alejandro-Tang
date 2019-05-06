//
// Created by alejandro on 02/05/19.
//

#ifndef DISJOINT_SET_ALEJANDRO_TANG_NODE_H
#define DISJOINT_SET_ALEJANDRO_TANG_NODE_H

template <typename T>
class Node {
private:
    T data;
    Node<T> * father;
    int rank;

public:
    Node<T>(T data){
        this->data = data;
        father = this;
        rank = 0;
    }

    Node<T> * findRoot(){
        if(father == this){
            return this->father;
        }else{
            return this->father->findRoot();
        }
    }

    void increaseRank(){
        rank++;
    }

    void setNewFather(Node<T> * newFather){
        this->father = newFather;
        newFather->increaseRank();
    }

    int getData(){
        return data;
    }

    int getRank(){
        return rank;
    }

    Node<T> * getFather(){
        return this->father;
    }

    void joinArbitrary(Node<T> * other){
        auto otherRoot = other->findRoot();
        auto thisRoot = this->findRoot();
        if(otherRoot != thisRoot){
            otherRoot->setNewFather(thisRoot);
        }
    }

    void joinByRank(Node<T> * other){
        auto otherRoot = other->findRoot();
        auto thisRoot = this->findRoot();
        if(otherRoot != thisRoot){
            if(thisRoot->getRank() >= otherRoot->getRank()){
                otherRoot->setNewFather(thisRoot);
            }else{
                thisRoot->setNewFather(otherRoot);
            }
        }
    }


    void compressPath(){
        if(this->father != this){
            this->father = this->father->compressPathHelper();
        }
    }

    Node<T> * compressPathHelper(){
        if(this->father != this){
            this->father = this->father->compressPathHelper();
            return this->father;
        }else{
            return this;
        }
    }

};


#endif //DISJOINT_SET_ALEJANDRO_TANG_NODE_H
