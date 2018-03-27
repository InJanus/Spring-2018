
// 
// Name: Brian Culberson
//


#include <iostream>
#include <cmath>

#include "point_class.cpp"

using namespace std;

// We have setup class framework for you. Please copy the point 
// class you created to this file.

class line {
  public:
    friend istream& operator>>(istream &input, line &l){
      input >> l.p1 >> l.p2;
	    return input;
    }
    
    friend ostream& operator<<(ostream &output, line &l){
      output << "(" << l.p1 << " " << l.p2 << ")";
      return output;
    }
    
    line(point p1, point p2){
      this->p1 = p1;
      this->p2 = p2;
    }
    
    line(){
      this->p1 = point();
      this->p2 = point();
    }
    point getP1(){
      return p1;
    }
    
    point getP2(){
      return p2;
    }
    
    void setP1(point p1){
      this->p1 = p1;
    }
    
    void setP2(point p2){
      this->p2 = p2;
    }
    
    double getSlope(){
      return (((double)(p2.getY()-p1.getY()))/((double)(p2.getX()-p1.getX())));
    }
    
    double getLength(){
      double temp = pow((p2.getX()-p1.getX()),2)+pow((p2.getY()-p1.getY()),2);
      temp = pow(temp,0.5);
      return temp;
    }
    
    bool isVertical(){
      return (p1.getY() == p2.getY());
    }
    
    bool isHorizontal(){
      return (p1.getX() == p2.getX());
    }
    
    bool isParallel(line test){
      return (getSlope() == test.getSlope());
    }
    
    bool doesIntersect(line test){
      return (!isParallel(test));
    } 
    
    point getYIntercept(){
      return point((((-1*p1.getY())/getSlope())+p1.getX()),0);
      //this is constructed from the point slope formula;
    }
    
    
    
    
    
  private:
    point p1;
    point p2;
};

/*
int main() {
  line L1;
  line L2;
  
  cout << "Enter L1: ";
  cin >> L1;

  cout << "L1: ";
  cout << L1;
  cout << endl;
  
  cout << L1.getP1() << endl;
  cout << L1.getP2() << endl;
  cout << L1.getP1().getX() << endl;
  L1.setP1(point(0,0));
  L1.setP2(point(10,10));
  L2.setP1(point(-6,-5));
  L2.setP2(point(9,10));
  cout << L1.getP1() << endl;
  cout << L1.getSlope() << endl;
  cout << L1.getLength() << endl;
  cout << L1.isHorizontal() << endl;
  cout << L1 << endl << L2 << endl;
  cout << L1.isParallel(L2) << endl;
  cout << L2.getYIntercept() << endl;
  
  
  return 0;
}

*/
