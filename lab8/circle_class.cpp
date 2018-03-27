
// 
// Name:
//


#include <iostream>

#include "line_class.cpp"

using namespace std;

const double pi = 3.14159265;

class circle {
    public:
      circle(){
        l = line();
      }
      circle(line l){
        this->l = l;
      }
      
      line getL(){
        return l;
      }
      void setL(line l){
        this->l = l;
      }
      
      friend istream& operator>>(istream &input, circle &c){
        input >> c.l;
	      return input;
      }
      
      friend ostream& operator<< (ostream &output, circle &c){
        output << "(R:" << c.l.getP1() << " " << c.l.getP2() << ")";
        return output;
      }
      
      double getRadius(){
        return l.getLength();
      }
      
      double getDiameter(){
        return getRadius()*2;
      }
      
      double getArea(){
        return (pi*pow(getRadius(),2));
      }
      
      double getCircumference(){
        return (getDiameter()*pi);
      }
      
      bool doesIntersect(circle c){
        double temp = line(c.getL().getP1(),l.getP1()).getLength();
        //cout << temp << endl;
        double temp2 = c.getRadius()+getRadius();
        //cout  << temp2 << endl;
        
        return (temp2>=temp);
      }
      
      bool doesFitInside(circle c){
        double temp = line(c.getL().getP1(),l.getP1()).getLength();
        //cout << temp << endl;
        double temp2 = c.getRadius()-getRadius();
        return (temp2>temp);
      }
      
      
    
    private:
      line l;
};


int main() {
  circle c1(line(point(0,0),point(5,0)));
  circle c2(line(point(100,0),point(90,0)));
  circle c3(line(point(1,0),point(2,0)));
  //cout << c1 << endl;
  //cout << c1.doesIntersect(c2) << endl;
  cout << c3.doesFitInside(c1) << endl;
  
  
  //cout << "Enter C1: ";
  //cin >> c1;

  //cout << "C1: ";
  //cout << c1;
  //cout << endl;
  
  return 0;
}
