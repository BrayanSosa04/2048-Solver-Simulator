#include "matrix.h"
#include  <algorithm>

void matrix::fillInMatrix(int row, int col, ifstream & ifs){
    int num; //reads in the numbers
    for(int i = 0; i < row; i++){
        vector<int> tmp;
        for(int j = 0; j < col; j++){
            ifs >> num;
            tmp.push_back(num);
        }
        myM.push_back(tmp);
    }
}

int matrix::addTotalOfM(){
    int count = 0;
    for(int i = 0; i < getRowN(); i++){
        for(int j = 0; j < getColN(); j++){
            if(myM.at(i).at(j) != 2048){
                count = count + myM.at(i).at(j);
            }
        }
    }
    return count;
}

int matrix::countAmtGTZero(){
    int count = 0;
    for(int i = 0; i < getRowN(); i++){
        for(int j = 0; j < getColN(); j++) {
            if((myM.at(i).at(j) != 2048) && myM.at(i).at(j) > 0){
                count += 1;
            }
        }
    }
    return count;
}

void matrix::shiftUp(){
  stack<int> stack;
  int counter = 0;
  int val;
  int temp;
  //nested for loop to loop thru every element in matrix
  for (int j = 0; j < getRowN(); j++) {
    for (int i = 0; i < getColN(); i++) {
      //if the element is not 0 or 2048
      if (myM.at(i).at(j) != 0 && myM.at(i).at(j) != 2048) {
        //if the element is equal to the top of the stack
        if (!stack.empty() && myM.at(i).at(j) == stack.top()) {
          //double the top of the stack
          val = stack.top();
          stack.pop();
          stack.push(val*2);
          //push in -1 to indicate that the element already merged
          //this is to stop the next equal elements from merging since it will compare to -1
          stack.push(-1);
          //after pushing in -1, need to increase counter by 1
          counter++;
        }
        //else if the stack is empty or element is not equal to top of stack, just push it in stack
        else {
            stack.push(myM.at(i).at(j));
        }
      }
      //if the element is 2048
      else if (myM.at(i).at(j) == 2048) {
        //while stack size not equal to counter, push in 0 until size equal counter
        while (stack.size() < counter){
          stack.push(0);
        }
        //after push in 0 to make size equal counter, push 2048 in
        stack.push(2048);
      }
      //after reading an element, increase counter by 1
      counter ++;
    }
    //when you reach this point, mean that you reach the end of a column
    //while stack size is not equal counter, push in 0 until size equal counter
    while (stack.size() < counter){
        stack.push(0);
    }
  }
  stack.push(-1);
  counter += 1;
  //after everything is inside the stack, start poping elements back to the matrix
  for (int j= getRowN()-1; j >= 0; j--) {
    for (int i= getColN()-1; i >= 0; i--) {
      temp = stack.top(); //THIS IS THE POP U MIGHT WANNA CHANGE
      stack.pop();
      //if the popped element is -1, skip it and pop the next element
      if (temp == -1){
        myM.at(i).at(j) = stack.top();
        stack.pop();
    }
      else
        myM.at(i).at(j) = temp;
    }
  }
}

void matrix::shiftDown(){
  reverseCol(getRowN(), getColN());
  shiftUp();
  reverseCol(getRowN(), getColN());
}

void matrix::shiftRight(){
  reverseRow(getRowN(), getColN());
  shiftLeft();
  reverseRow(getRowN(), getColN());
}//rewrite this

void matrix::shiftLeft(){
  stack<int> stack;
  int counter = 0;
  int val;
  int temp;
  //nested for loop to loop thru every element in matrix
  for (int j = 0; j < getRowN(); j++) {
    for (int i = 0; i < getColN(); i++) {
      //if the element is not 0 or 2048
      if (myM.at(j).at(i) != 0 && myM.at(j).at(i) != 2048) {
        //if the element is equal to the top of the stack
        if (!stack.empty() && myM.at(j).at(i) == stack.top()) {
          //double the top of the stack
          val = stack.top();
          stack.pop();
          stack.push(val*2);
          //push in -1 to indicate that the element already merged
          //this is to stop the next equal elements from merging since it will compare to -1
          stack.push(-1);
          //after pushing in -1, need to increase counter by 1
          counter++;
        }
        //else if the stack is empty or element is not equal to top of stack, just push it in stack
        else {
            stack.push(myM.at(j).at(i));
        }
      }
      //if the element is 2048
      else if (myM.at(j).at(i) == 2048) {
        //while stack size not equal to counter, push in 0 until size equal counter
        while (stack.size() < counter){
          stack.push(0);
        }
        //after push in 0 to make size equal counter, push 2048 in
        stack.push(2048);
      }
      //after reading an element, increase counter by 1
      counter ++;
    }
    //when you reach this point, mean that you reach the end of a column
    //while stack size is not equal counter, push in 0 until size equal counter
    while (stack.size() < counter){
        stack.push(0);
    }

    stack.push(-1);
    counter += 1;
  }
  //after everything is inside the stack, start poping elements back to the matrix
  for (int j= getRowN()-1; j >= 0; j--) {
    for (int i= getColN()-1; i >= 0; i--) {
      temp = stack.top(); //THIS IS THE POP U MIGHT WANNA CHANGE
      stack.pop();
      //if the popped element is -1, skip it and pop the next element
      if (temp == -1){
        myM.at(j).at(i) = stack.top();
        stack.pop();
      }
      else{
        myM.at(j).at(i) = temp;
      }
    }
  }
}

void matrix::reverseCol(int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col/2; j++){
            swap(myM.at(j).at(i), myM.at(col-j-1).at(i));
        }
    }
} 

void matrix::reverseRow(int row, int col){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row/2; j++){
            swap(myM.at(i).at(j), myM.at(i).at(row-j-1));
        }
    }
}

int matrix::at(int row, int col){
    return this->myM.at(row).at(col);
}

bool matrix::compMatrix(matrix &fakeM) {
    for(int i = 0; i < getRowN(); i++) {
        for(int j = 0; j < getColN(); j++) {
            if(this->myM.at(i).at(j) != fakeM.at(i, j)) {
                return true;
            }
        }
    }
    return false;
}

void matrix::takeInMove(int num) {
    if(num == 1){
        shiftUp();
    }
    else if(num == 2){
        shiftRight();
    }
    else if(num == 3){
        shiftDown();
    }
    else if(num == 4){
        shiftLeft();
    }
}

// void matrix::printMatrix(int row, int col, ofstream & ofs){
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < col; j++){
//             cout << myM.at(i).at(j) << " ";
//         }
//         cout << endl;
//     } 
// } //don't need this only used it to test if it was reading the matrix in correctly