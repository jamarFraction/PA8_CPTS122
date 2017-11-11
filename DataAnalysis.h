// Lastly, define a class DataAnalysis, which encapsulates the following:
// Data members:
//           - mTreeSold : BST
//           - mTreePurchased : BST
//           - mCsvStream : ifstream

// Member functions:
// - A function that opens data.csv // yes, it’s private, and must use mCsvStream to open the file
//           - A function that reads one line from the file and splits the line into units, type, and transaction fields
//           - A function that loops until all lines are read from the file; calls the function below, and then displays the current contents of both BSTs; use inOrderTraversal () to display the trees
//           - A function that compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased) // note with the way the data.csv file is organized the trees will be fairly balanced
//           - A function that writes to the screen the trends we see in our tree; the function must display the type and number of units that are least purchased and sold, and the most purchased and sold
//           + runAnalysis (), which is the only public function in the class, aside from possibly a constructor and/or destructor; this function calls the other private functions
#ifndef DataAnalysis_h
#define DataAnalysis_h

#include "BST.h"
#include <fstream>

using std::ifstream;

class DataAnalysis{

  private:
    BST mTreeSold;
    BST mTreePurchased;
    ifstream mCsvStream;

  public:
    void RunAnalysis();
};

#endif