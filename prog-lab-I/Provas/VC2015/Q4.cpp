#include <bits/stdc++.h>
using namespace std;

const float PI = acos(-1.0);

class Ponto{
  private:
    float x, y;
  public:
    Ponto() : x(0), y(0) {}
    Ponto(float x, float y) : x(x), y(y) {}
    
    float getX(){
      return x;
    }

    float getY(){
      return y;
    }
};

class Figura{
  public:
    float Dist(Ponto a, Ponto b){
      float distX = a.getX() - b.getX();
      float distY = a.getY() - b.getY();
      return sqrt(distX*distX + distY*distY);
    }
};

class Retangulo : public Figura{
  private:
    Ponto P1, P2, P3;
  public:
    Retangulo(float x1, float y1, float x2, float y2, float x3, float y3) : P1(x1, y1), P2(x2, y2), P3(x3, y3) {}
    
    float getArea(){
      return Dist(P3, P1)* Dist(P2, P1);
    }

    float getPerimeter(){
      return 2*(Dist(P3, P1) + Dist(P2, P1)); 
    }
};

class Quadrado : public Figura{
  private:
    Ponto P1, P2;
  public:
    Quadrado(float x1, float y1, float x2, float y2) : P1(x1, y1), P2(x2, y2) {}

    float getArea(){
      return Dist(P1, P2)*Dist(P1, P2)/2.0;
    }

    float getPerimeter(){
      return 4*Dist(P1, P2)/sqrt(2);
    }
};

class Circulo : public Figura{
  private:
    Ponto P;
    float r;
  public:
    Circulo(float x, float y, float r) : P(x, y), r(r) {}

    float getArea(){
      return PI*r*r;
    }

    float getPerimeter(){
      return 2*PI*r;
    }
};

int main(){

}
