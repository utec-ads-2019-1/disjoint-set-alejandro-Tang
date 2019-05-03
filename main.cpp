//
// Created by alejandro on 02/05/19.
//

#include <iostream>
#include "node.h"
#include "set.h"
#include <vector>

using namespace std;

void joinAndPrintRank(int a, int b, vector<Node<int> *> *vector){
    (*vector)[a-1]->joinByRank((*vector)[b-1]);
    cout << "join(" << a <<", " << b << "):\n";
    for(int i = 1; i<=(*vector).size(); i++){
        cout << "El root del nodo " << i << " es " << ((*vector)[i-1]->findRoot())->getData() << endl;
    }
    cout << endl;
}

void joinAndPrintArbitrario(int a, int b, vector<Node<int> *> *vector){
    (*vector)[a-1]->joinArbitrary((*vector)[b-1]);
    cout << "join(" << a <<", " << b << "):\n";
    for(int i = 1; i<=(*vector).size(); i++){
        cout << "El root del nodo " << i << " es " << ((*vector)[i-1]->findRoot())->getData() << endl;
    }
    cout << endl;
}

int main(){

    auto nodeVector1 = new vector<Node<int>*>;
    auto nodeVector2 = new vector<Node<int>*>;

    for(int i = 1; i < 17; i++){
        auto node1 = new Node<int>(i);
        auto node2 = new Node<int>(i);
        nodeVector1->push_back(node1);
        nodeVector2->push_back(node2);
    }

    cout << "Se realizan los joins por rank: \n";
    joinAndPrintRank(1, 2, nodeVector1);
    joinAndPrintRank(3, 4, nodeVector1);
    joinAndPrintRank(3, 5, nodeVector1);
    joinAndPrintRank(1, 7, nodeVector1);
    joinAndPrintRank(3, 6, nodeVector1);
    joinAndPrintRank(8, 9, nodeVector1);
    joinAndPrintRank(1, 8, nodeVector1);
    joinAndPrintRank(3, 10, nodeVector1);
    joinAndPrintRank(3, 11, nodeVector1);
    joinAndPrintRank(3, 12, nodeVector1);
    joinAndPrintRank(3, 13, nodeVector1);
    joinAndPrintRank(14, 15, nodeVector1);
    joinAndPrintRank(16, 1, nodeVector1);
    joinAndPrintRank(14, 16, nodeVector1);
    joinAndPrintRank(1, 3, nodeVector1);
    joinAndPrintRank(1, 14, nodeVector1);

    for(int i = 1; i < 17; i++){
        delete (*nodeVector1)[i-1];
    }
    delete nodeVector1;


    cout << "Se realizan los joins arbitrarios: \n";
    joinAndPrintArbitrario(1, 2, nodeVector2);
    joinAndPrintArbitrario(3, 4, nodeVector2);
    joinAndPrintArbitrario(3, 5, nodeVector2);
    joinAndPrintArbitrario(1, 7, nodeVector2);
    joinAndPrintArbitrario(3, 6, nodeVector2);
    joinAndPrintArbitrario(8, 9, nodeVector2);
    joinAndPrintArbitrario(1, 8, nodeVector2);
    joinAndPrintArbitrario(3, 10, nodeVector2);
    joinAndPrintArbitrario(3, 11, nodeVector2);
    joinAndPrintArbitrario(3, 12, nodeVector2);
    joinAndPrintArbitrario(3, 13, nodeVector2);
    joinAndPrintArbitrario(14, 15, nodeVector2);
    joinAndPrintArbitrario(16, 1, nodeVector2);
    joinAndPrintArbitrario(14, 16, nodeVector2);
    joinAndPrintArbitrario(1, 3, nodeVector2);
    joinAndPrintArbitrario(1, 14, nodeVector2);

    for(int i = 1; i < 17; i++){
        delete (*nodeVector2)[i-1];
    }
    delete nodeVector2;




    return 0;
}