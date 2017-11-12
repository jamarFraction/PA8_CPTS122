#include "BST.h"

BST::BST(TransactionNode *passedRootNode){

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
    cout << "\n";
    
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
    while(location->GetRight() != nullptr){

        //update location
        location = (TransactionNode*) location->GetRight();

    }

    //location = (TransactionNode*)location;

    return *location;



}

void BST::Insert(TransactionNode *&passedNode){

    //pass the root of the tree and the passedNode to
    //the recursive insert function
    Insert(this->mpRoot, passedNode);

}

void BST::Insert(Node *&pTree, TransactionNode *&passedNode){


    //base case.. AKA "insert here"
    if(pTree == nullptr){

        pTree = passedNode;

    }else if(passedNode->GetUnits() < (dynamic_cast <TransactionNode*> (pTree)->GetUnits())){

        //Insert left subtree
        Insert(pTree->GetLeft(), passedNode);

    }else if(passedNode->GetUnits() > (dynamic_cast <TransactionNode*> (pTree)->GetUnits())){

        //Insert right subtree
        Insert(pTree->GetRight(), passedNode);

    }


}
