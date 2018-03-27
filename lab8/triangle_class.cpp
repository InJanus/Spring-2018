
// 
// Name: Brian Culberson
//


#include <iostream>
#include "line_class.cpp"


using namespace std;

// We have setup class framework for you. Please copy the point 
// class and/or line class you created to this file.

class triangle {
    public:
      triangle(point p1, point p2, point p3){
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
      }
      
      triangle(){
        p1 = point();
        p2 = point();
        p3 = point();
      }
      
      friend istream& operator>>(istream &input, triangle &t){
        input >> t.p1 >> t.p2 >> t.p3;
	      return input;
      }
      
      friend ostream& operator<<(ostream &output, triangle &t){
        output << "("<< t.p1 << " " << t.p2 << " " << t.p3 << ")";
        return output;
      }
      
      void setP1(point p1){
        this->p1 = p1;
      }
      void setP2(point p2){
        this->p2 = p2;
      }      
      void setP3(point p3){
        this->p3 = p3;
      }
      
      point getP1(){
        return p1;
      }
      point getP2(){
        return p2;
      }
      point getP3(){
        return p3;
      }
      
      double getPerimeter(){
        return (line(p1,p2).getLength()+line(p2,p3).getLength()+line(p3,p1).getLength());
      }
      
      double getSide1(){
        return line(p1,p2).getLength();
      }
      double getSide2(){
        return line(p2,p3).getLength();
      }
      double getSide3(){
        return line(p3,p1).getLength();
      }
      
      bool isEquilateral(){
        return ((line(p1,p2).getLength()==line(p2,p3).getLength())&&(line(p3,p1).getLength()==line(p2,p3).getLength()));
      }
      
      bool isTriangle(){
        return (getArea() > 0);
      }
      
      double getHypotnuse(int &side){
        double temp = getSide1();
        //cout << temp << endl;
        side = 1;
        if (temp < getSide2()){
          temp = getSide2();
          side = 2;
        }
        if(temp < getSide3()){
          temp = getSide3();
          side = 3;
        }
        return temp;
      }
      
      bool isRight(){
        int side = 0;
        getHypotnuse(side);
        double temp = (-pow(getHypotnuse(side),2));
        //cout << temp << endl;
        if(side == 1){
          temp += (getSide2()*getSide2()+getSide3()*getSide3());
          //temp = temp / (2*getSide2()*getSide3());
        } else if(side == 2){
          temp += (getSide1()*getSide1()+getSide3()*getSide3());
          //temp = temp / (2*getSide1()*getSide3());
        } else if(side == 3){
          temp += (getSide2()*getSide2()+getSide1()*getSide1());
          // = temp / (2*getSide2()*getSide1());
        }
        //temp = acos(temp);
        temp = abs(temp);
        //cout << temp << endl;
        
        return (temp < 0.00001);
        
        //sin 90 = 1
        //law of cosines
      }
      
      double getArea(){
        double s = getPerimeter()/2;
        //cout << s << endl;
        return pow((s*(s-getSide1())*(s-getSide2())*(s-getSide3())),0.5);
        //get the area of any triangle
        //hurons formula
      }
      
      
    
    
    private:
      point p1;
      point p2;
      point p3;
};


int main() {
  triangle T1(point(1,2),point(36,9),point(78,30));
  triangle T2(point(1,2),point(5,2),point(5,6));
  //point P1(1,2);
  //cin >> T1;
  //cout << T1 << endl;
  //cout << T1.getPerimeter() << endl;
  //cout << T1.isEquilateral() << endl;
  //cout << T1.isTriangle() << endl;
  //cout << T1.isRight() << endl;
  //cout << T2.isRight() << endl;
  
  cout << T1.getArea() << endl;
  
  cout << T2.getArea() << endl;
  //int side;
  //cout << T1.getHypotnuse(side) << endl;
  //cout << T1.getArea() << endl;
  return 0;
}
