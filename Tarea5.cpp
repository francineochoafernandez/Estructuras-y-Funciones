#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

struct Punto
{
  float x, y;

  Punto operator+ (Punto aux)
  { //Componenete de la derecha de la suma o el operador a usar
    Punto temp;
    temp.x = x + aux.x;
    temp.y = y + aux.y;
    return temp;
  }

  Punto operator- (Punto aux)
  {
    Punto temp;
    temp.x = x - aux.x;
    temp.y = y - aux.y;
    return temp;
  }

  Punto operator+= (Punto aux)
  { // a la misma variable x, x= x+y
    x = x + aux.x;
    y = y + aux.y;
    return *this;
  }

  void Muestra ()
  {
  cout << "(" << x << "," << y << ")" << endl;
  }

};

float Dist(Punto a, Punto b)
{
  float dpun=sqrt( pow(b.x-a.x,2) + pow(b.y-a.y,2));
  return dpun;
}

float DistManhattan(Punto a, Punto b)
{
  float dpun=abs( (b.x-a.x) + (b.y-a.y) );
  return dpun;
}

void Arreglo(Punto arreglo[5], float arreglodis[4])//Funcion que  que compara distancia de punto con el origen y lo pone en un arreglo en orden decreciente
{
  int i,j,n=4;
  float a;
  arreglodis[0]=abs((arreglo[1].x-arreglo[0].x) + (arreglo[1].y-arreglo[0].y));
  arreglodis[1]=abs((arreglo[2].x-arreglo[0].x) + (arreglo[2].y-arreglo[0].y));
  arreglodis[2]=abs((arreglo[3].x-arreglo[0].x) + (arreglo[3].y-arreglo[0].y));
  arreglodis[3]=abs((arreglo[4].x-arreglo[0].x) + (arreglo[4].y-arreglo[0].y));
  //Comparando distancias de  menor a mayor
  for(i= 0;i<n;++i)
  {
    for(j=i+1;j<n;++j)
   {
     if (arreglodis[i] > arreglodis[j])
     {
       a = arreglodis[i];
       arreglodis[i] = arreglodis[j];
       arreglodis[j] = a;
     }
   }
  }
  printf("\nLas distancias en orden creciente es: \n");
  for(i=0;i<=n;i++)
  {
    printf("%f ",arreglodis[i]);
  }

}


int main (void)
{
  Punto pa, pb, pc;
  pa.x = 3.0;
  pa.y = -5.4;
  pb.x = 7.28;
  pb.y = 6.45;
  pa.Muestra();

  pc= pa + pb;
  pc.Muestra();
  pc= pa - pb;
  pc.Muestra();

  pa+=pb;
  pa.Muestra();

  Punto a,b;
  a.x=5;
  a.y=4;
  b.x=3;
  b.y=2;

  float d,dm;
  //Distancia Normal
  d=Dist(a,b);
  printf("La distancia entre los puntos %f,%f y %f,%f es %f\n",a.x,a.y,b.x,b.y,d);

  //Distancia Manhattan
  dm=DistManhattan(a, b);
  printf("La distancia Manhattan entre los puntos %f,%f y %f,%f es %f\n",a.x,a.y,b.x,b.y,dm);

  //Distancia entre puntos
  Punto arreglo[5];
  arreglo[0].x=0;
  arreglo[0].y=0;
  arreglo[1].x=8.3;
  arreglo[1].y=4.3;
  arreglo[2].x=3.34;
  arreglo[2].y=3;
  arreglo[3].x=8.4542;
  arreglo[3].y=4.3;
  arreglo[4].x=10;
  arreglo[4].y=45;
  float arreglodis[4];//Arreglo de distacia
  Arreglo(arreglo,arreglodis);


  return 0;
}
