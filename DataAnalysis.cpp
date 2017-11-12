#include "DataAnalysis.h"

using std::getline;

void DataAnalysis::OpenInputStream(){

    this->mCsvStream.open("data.csv");

    if(!mCsvStream.is_open()){

        system("cls");
        cout << "Error: .csv file not found!" << endl;
        system("pause");

    }
}

void DataAnalysis::CloseInputStream(){

    //close the stream if it is open
    if(mCsvStream.is_open()){

        mCsvStream.close();
    }
}

void DataAnalysis::ProcessLine(string &line, int &units, string &item, string &transactionType){

    //find the location of the first comma
    int pos = line.find(","); 

    //substring the line and convert to an int with our function
    units = ConvertToInt(line.substr(0, pos));

    //chop the line down to start from the old location of the first comma
    line = line.substr(pos + 1);

    //find the position of the next comma
    pos = line.find(","); 

    //substring the line
    item = line.substr(0, pos);

    //chop the line down to start from the old location of the second comma
    line = line.substr(pos + 1);

    //substring the line
    transactionType = line;


}

int DataAnalysis::ConvertToInt(string someNumber){

    int result = std::stoi(someNumber);

    return result;

}

void DataAnalysis::ProcessFile(){

    //variables whos values will be set for new TransactionNodes
    string tItem = "", tTransactionType = "";
    int tUnits = 0;

    //Declare and set the first line of the file.. this won't be of use
    string currentLine = "";

    getline(mCsvStream, currentLine);

    //Loop through the entire file
    while (!mCsvStream.eof())
    {

        //get the line and pop_back to get rid of the \r char at the end of the line
        getline(mCsvStream, currentLine);
        currentLine.pop_back();

        //Create a new node
        TransactionNode *newNode = new TransactionNode();

        //Process the line, which will assign the necessary variables for a node
        ProcessLine(currentLine, tUnits, tItem, tTransactionType);

        //assign the line info to the node
        newNode->SetData(tItem);
        newNode->SetUnits(tUnits);

        //the Node will either be inserted into the proper function or deleted
        //DUN DUN DUN!
        InsertNodeInProperTree(newNode, tTransactionType);

    }
}

void DataAnalysis::InsertNodeInProperTree(TransactionNode *&passedNode, string transactionType){

    
        //check for where to insert the node
        if (transactionType == "Purchased")
        {

            //insert into the purchased tree
            mTreePurchased.Insert(passedNode);
        }
        else if (transactionType == "Sold")
        {

            //insert into the sold tree
            mTreeSold.Insert(passedNode);
        }
        else
        {

            //delete whatever node was created
            delete (passedNode);
        }



}

void DataAnalysis::RunAnalysis(){

    //open the input stream
    this->OpenInputStream();

   
    if(mCsvStream.is_open()){
        
        //Process the file
        ProcessFile();

        //close the stream
        this->CloseInputStream();

        //Display the contents of both trees
        //Sold tree
        cout << "Sold Tree Contents:" << endl;
        mTreeSold.InOrderTraversal();

        //Purchased Tree
        cout << "Purchased Tree Contents:" << endl;
        mTreePurchased.InOrderTraversal();

        //Display the data trends
        this->DisplayDataTrends();
    }

}

 void DataAnalysis::DisplayDataTrends(){
    cout << "\n\n////////////////////////////" << endl;
    cout << "DATA TRENDS:\n";

    //worker!
    TransactionNode currentNode;

    //Sold
    currentNode = mTreeSold.FindSmallest();

    cout << "\n\nLeast Sold" << endl;
    currentNode.printData();

    currentNode = mTreeSold.FindLargest();
    cout << "\nGreatest Sold" << endl;
    currentNode.printData();


    //Purchased
    currentNode = mTreePurchased.FindSmallest();

    cout << "\n\nLeast Purchased" << endl;
    currentNode.printData();

    currentNode = mTreePurchased.FindLargest();
    cout << "\nGreatest Purchased" << endl;
    currentNode.printData();
    cout << "////////////////////////////" << endl;

 }

