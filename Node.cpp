#include "Node.h"


Node::Node(string passedData, Node *dLeft, Node *dRight){

    //setting default values
    mData = passedData;
    mpLeft = dLeft;
    mpRight = dRight;

}

Node::~Node(){

    delete(this->mpLeft);
    delete(this->mpRight);

}

string Node::GetData(){

    return mData;

}

Node*& Node::GetLeft(){

    return mpLeft; 


}

Node*& Node::GetRight(){

    return mpRight;


}

void Node::SetData(string passedData){

    mData = passedData;


}

void Node::SetLeft(Node*& passedLeft){

    this->mpLeft = passedLeft;


}

void Node::SetRight(Node*& passedRight){

    this->mpRight = passedRight;


}

