#include <iostream>

#include "DataAnalysis.h"

using std::cout;
using std::cin;
using std::endl;


int main(void){


    //testing
    string tItem = "", tTransactionType = "";

    string tLine = "9000,iPhone6s,Purchased";

    int tUnits = 0;

    cout << "Hello, World!" << endl;

    DataAnalysis test;

    test.ProcessLine(tLine, tUnits, tItem, tTransactionType);

    return 0;
}