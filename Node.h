#ifndef Node_h_
#define Node_h_

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Node{

protected:

    string mData;
    Node *mpLeft;
    Node *mpRight;
    
public:

    //default constructor values
    Node(string passedData = "", Node *dLeft = nullptr, Node *dRight = nullptr);

    virtual ~Node();

    //Getters
    string GetData();
    Node*& GetLeft();
    Node*& GetRight();

    //Setters
    void SetData(string passedData);
    void SetLeft(Node*& passedLeft);
    void SetRight(Node*& passedRight);

    //Virtual printData
    virtual void printData() = 0;



};

#endif