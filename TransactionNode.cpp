#include "TransactionNode.h"

TransactionNode::TransactionNode(int passedUnits, string passedData){

    //set the default units and data
    mUnits = passedUnits;

    this->mData = passedData;

}

TransactionNode::~TransactionNode(){

    //do something
}

void TransactionNode::SetUnits(int passedUnits){

    //set the units
    mUnits = passedUnits;

}

int TransactionNode::GetUnits() const{

    //return the units
    return this->mUnits;

}

void TransactionNode::printData(){

    //Data:      
    //Units:
    cout << "Data: " << this->GetData() << "\nUnits: " << this->GetUnits() << endl;

}