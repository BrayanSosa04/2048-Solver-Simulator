#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.h"
#include "ArgumentManager.h"

using namespace std;

bool pwrOfTwo(int x){
   if(x == 0){
       return false;
   }
    while (x != 1)
  {
      if (x%2 != 0)
         return false;
      x = x/2;
  }
  return true;
}

stack<int> bestPath(int lvl, matrix &theMatrix, stack<int> path){
    //lvl should be passed as 12 since I wanna go backwards and once I reach zero I'll say it's impossible if not solved
    if(theMatrix.countAmtGTZero() == 1){
        return path;
    }
    if(lvl < 0 || pwrOfTwo(theMatrix.addTotalOfM()) == false){
        return stack<int> ();
    }

    long int biggestNum = 999999999999;
    int leGoodDirection = 0;
    stack<int> theCoolestStack = path;

    for(int i = 1; i <= 4; i++) {
      matrix fakeM(theMatrix);
      fakeM.takeInMove(i);
      if(theMatrix.getMatrix() != fakeM.getMatrix()){ //this if statement only returns true if it found a difference in the matrix
          stack<int> cStack = bestPath(lvl - 1, fakeM, path);
          if(cStack.size() < biggestNum){
              biggestNum = cStack.size();
              leGoodDirection = i;
              theCoolestStack = cStack;
              theCoolestStack.push(leGoodDirection);
          }

      }
    }
    return theCoolestStack;
}

int main(int argc, char *argv[]){
  ArgumentManager am(argc, argv);

  string input_name = am.get("input");
  string output_name = am.get("output");

  ifstream ifs(input_name);
  ifstream ifsf(input_name);
  ofstream ofs(output_name);
  ofs << "";
  
  int size;
  ifs >> size;

  int rowN = size; //number of rows 
  int colN = size; //number of columns

 // Up = 1, right = 2, down = 3, and left = 4

  matrix myMatrix;
  myMatrix.fillInMatrix(rowN, colN, ifs);  //MATRIX FILLED HERE
  cout << myMatrix.countAmtGTZero();

  stack<int> path;
  int num = myMatrix.countAmtGTZero(); //stores the amt of numebers > 0 that arent 2048
  bool checker = pwrOfTwo(myMatrix.addTotalOfM()); //checks if the total of the matrix is a power of two

  if(num == 1 && checker == true){
    ofs << "0";
    return 0;
  }
  else{
    path = bestPath(12, myMatrix, path);

    if(path.empty() || path.top() == 0 || path.size() > 12){
        ofs << "Impossible";
    }
    else{
        while(!path.empty()){
            ofs << path.top();
            path.pop();
        }
    }
  }
  
    return 0;   
}
//if the total amount of the matrix is a power of two, then, it is possible otherwise it is impossible
//I check initially through any random move(up, leeft, right, down) if it doesnt change from the original dont even go through that branch