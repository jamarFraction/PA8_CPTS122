#include <string>

using std::string;


class Node{

protected:

    // Data members:
    // # mData : std::string // # denotes protected
    // # mpLeft : Node *
    // # mpRight : Node *

    string mData;
    Node *mpLeft;
    Node *mpRight;
    
public:

    //default constructor values
    Node(string passedData = "", Node *dLeft = nullptr, Node *dRight = nullptr);

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