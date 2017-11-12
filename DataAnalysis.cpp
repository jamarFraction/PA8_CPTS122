#include "DataAnalysis.h"

using std::getline;

DataAnalysis::DataAnalysis(){

    this->OpenInputStream();

}

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

    //chop the line down to start from the old location of the first comma
    line = line.substr(pos + 1);

    //substring the line
    transactionType = line.substr(pos + 1);


}

int DataAnalysis::ConvertToInt(string someNumber){

    int result = std::stoi(someNumber);

    return result;

}

void DataAnalysis::ProcessFile(){

    //check to make sure that the file is open
    if(mCsvStream.is_open()){

        //variables whos values will be set for new TransactionNodes
        string tItem = "", tTransactionType = "";
        int tUnits = 0;

        //Declare and set the first line of the file.. this won't be of use
        string currentLine = "";

        getline(mCsvStream, currentLine);

        //Loop through the entire file
        while(!mCsvStream.eof()){

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


            //check for where to insert the node
            if(tTransactionType == "Purchased"){

                //insert into the purchased tree


            }else if(tTransactionType == "Sold"){

                //insert into the sold tree


            }else{

                //delete whatever node was created
                delete(newNode);
            }
        }
        
    }
}


    //testing

    // string test = "";
    // while(!mCsvStream.eof()){

    //     //get the line and pop the back to get rid of the \r char at the end of the line
    //     //'\n' isn't neccesarry, as no delimeter still returns the \r
    //     getline(mCsvStream, test, '\n');
    //     test.pop_back();



    // }



