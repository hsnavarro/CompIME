#include <bits/stdc++.h>
using namespace std;

long double d, vf, vg;

int main(){
  while(~scanf("%Lf%Lf%Lf", &d, &vf, &vg)){ 
    printf("%s\n", (12.0*vg >= sqrt(144.0+d*d)*vf) ? "S" : "N");
  }
}
