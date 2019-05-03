#include <bits/stdc++.h>
using namespace std;

class Point{
  private:
    float x, y, z;
  public:
    Point() : x(0), y(0), z(0) {}
    Point(float x, float y, float z) : x(x), y(y), z(z) {}

    void oposto(){
      x = -x;
      y = -y;
      z = -z;
    }

    float dist(){
      return sqrt(x*x+y*y+z*z);
    }

    void print(){
      cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main(){
  Point a(1, 1, 1);
  cout << a.dist() << endl;
  a.print();
  a.oposto();
  a.print();

}
