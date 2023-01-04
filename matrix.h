#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

class matrix {
    private:
        vector<vector<int>> myM;
    public:
        //matrix(matrix& matrixCopyFrom);
        int getRowN() {return myM.size();}
        int getColN() {return myM.size();}
        vector<vector<int>> getMatrix() {return myM;}
        void fillInMatrix(int row, int col, ifstream & ifs);
        int addTotalOfM(); //adds all of the values of the matrix except for 2048
        int countAmtGTZero(); //this checks if there is only a single number in my matrix
        void shiftUp();
        void shiftDown();
        void shiftRight();
        void shiftLeft();
        void reverseCol(int row, int col);
        void reverseRow(int row, int col);
        int at(int row, int col); //returns the value at a certain location
        bool compMatrix(matrix &fakeM); //compare two matrixes
        void printMatrix(int row, int col, ofstream & ofs); //this was just to print the matrix, dont need tho
        void takeInMove(int num);
};