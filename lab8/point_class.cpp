
// 
// Name: Brian Culberson
//


#include <iostream>

using namespace std;

class point {
  public:

    friend istream& operator>>(istream &input, point &p ) {
      input >> p.x >> p.y;
	    return input;
    }

    friend ostream& operator<<(ostream &output, const point &p ) {
      output << "(" << p.x << "," << p.y << ")";
	    return output;
    }

    point(double x, double y){
      this->x = x;
      this->y = y;
    }
    point(){
      x = 0;
      y = 0;
    }
    
    double getX(){
      return x;
    }
    
    double getY(){
      return y;
    }
    
    void setX(double x){
      this->x = x;
    }
    
    void setY(double y){
      this->y = y;
    }
    
  private:
    double x;
    double y;
};

/*
int main() {
  point P1;
  point P2(1,2);
  
  cout << "Enter P1: ";
  cin >> P1;

  cout << "P1: ";
  cout << P1;
  cout << endl;
  cout << P2;
  cout << endl;
  P1.setX(10);
  P1.setY(20);
  
  cout << P1.getX();
  cout << P1.getY();
  
  return 0;
}
*/