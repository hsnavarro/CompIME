#include <bits/stdc++.h>
using namespace std;

class Point{
  public:
    double x, y, z;
    double Dist(Point a);
    Point(double a, double b, double c);
};

double Point::Dist(Point b){
  return sqrt((this->x-b.x)*(this->x-b.x) + (this->y-b.y)*(this->y-b.y) + (this->z-b.z)*(this->z-b.z));
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

int main(){
  double x, y, z;
  cout << "Forneça as coordenadas: " << endl;
  cin >> x >> y >> z;
  Point a = Point(x, y, z);
  cout << "Forneça as coordenadas: " << endl;
  cin >> x >> y >> z;
  Point b = Point(x, y, z);
  cout << "A dist é: " << endl;
  cout << a.Dist(b) << endl;
}
