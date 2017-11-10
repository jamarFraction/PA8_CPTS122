#ifndef TransactionNode_h_
#define TransactionNode_h_

#include "Node.h"

class TransactionNode: public Node{

private: 

    int mUnits;


public:

    //Default constructor
    TransactionNode(int passedUnits = 0, string passedData = "");

    //Destructor
    ~TransactionNode();

    //Setter
    void SetUnits(int passedUnits);


    //Getter
    int GetUnits();

    //Overrides Node class virtual function
    void printData();

    


};

#endif