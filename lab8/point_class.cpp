
// 
// Name:
//


#include <iostream>

using namespace std;

// We have setup class framework for you.
// Please add cin/cout overload first and at the same time add the coordinates
//
// See github example as specified in the assignment handout for exaamples
//

class Point {
    public:

    friend istream& operator>>(istream &input, Point &p ) {
	// Finish me second by adding proper input >> statement
	return input;
    }

    friend ostream& operator<<(ostream &output, const Point &p ) {
	// Finish me thrid by adding proper output << statement
	return output;
    }

    // Please add constructors and other functions here.

    private:
	// Add me first

};


int main() {
  Point P1;
  
  cout << "Enter P1: ";
  cin >> P1;

  cout << "P1: ";
  cout << P1;
  cout << endl;
  
  return 0;
}
