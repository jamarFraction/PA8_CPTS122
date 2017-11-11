#include "BST.h"

BST::BST(Node *passedRootNode){

    //set the default root node to the passedRootNode/nullptr
    mpRoot = passedRootNode;

}

BST::~BST(){

    //Call the destroy tree
    this->DestroyTree();

}

void BST::DestroyTree(){

    //Delete the root which recursively calls the post-order destructor in Node class
    delete(this->mpRoot);

}

void BST::InOrderTraversal(){


    //pass the root to the private version of this function
    InOrderTraversal(this->mpRoot);

}

void BST::InOrderTraversal(Node *&passedNode){

    //Left, Print, Right

    //Left
    if(passedNode->GetLeft() != nullptr){

        InOrderTraversal(passedNode->GetLeft());

    }

    //Print
    passedNode->printData();
    
    //Right
    if(passedNode->GetRight() != nullptr){

        InOrderTraversal(passedNode->GetRight());

    }
    

}

TransactionNode& BST::FindSmallest() const{


    TransactionNode *location;
    
    location = (TransactionNode *)mpRoot;


    //keep updating pointer to move to the left.. this Node will have the lowest value
    while(location->GetLeft() != nullptr){

        //update location
        location = (TransactionNode*) location->GetLeft();

    }

    //location = (TransactionNode*)location;

    return *location;


}

 TransactionNode& BST::FindLargest() const{


    TransactionNode *location;
    
    location = (TransactionNode *)mpRoot;


    //keep updating pointer to move to the right.. this Node will have the highest value
    while(location->GetLeft() != nullptr){

        //update location
        location = (TransactionNode*) location->GetRight();

    }

    //location = (TransactionNode*)location;

    return *location;



}

