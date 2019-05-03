#include <bits/stdc++.h>
using namespace std;

class Point{
  float x, y, z;
  public:
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
    ~Point(){}
    void opos(){
      this->x *= -1;
      this->y *= -1;
    }

    void show(){
      cout << this->x << " " << this->y << " " << this->z <<  endl;
    }

    float dist(Point a){
      return sqrt((a.x - this->x)*(a.x - this->x) + (a.y - this->y)*(a.y - this->y) + (a.z - this->z)*(a.z - this->z));
    }


};

int main(){
  Point x = Point();
  x.show();
  Point a = Point(1, 1, 0);
  cout << x.dist(a) << endl;
  a.opos();
  a.show();


}
