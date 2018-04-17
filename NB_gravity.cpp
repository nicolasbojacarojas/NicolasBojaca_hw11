#include <iostream>
using std::cout;
using std::endl;
float f(float x, float y, float v);
float fz(float x, float y, float v);
int main()
{
	//variable que guarda el valor de la gravedad
	float G = 10.;
	//variable que guarda el valor del objeto mas masivo
	float M = 1000.; 
	//variable qu determina la evolucion temporal
	float h =0.01;	
	//variable que guarda el tiempo
	float x=0;
	//variable que guarda la velocidad inicial 
	float v=100;
	//variable que guarda la distancia inicial 
	float y=100;
	//cantidad de pasos que doy
	int N = 10/h;
	//variables donde se guardan los valores de las funciones para el metodo de tunge kutta
	float k1;
	float k2;
	float k3;
	float k4;
	float k1z;
	float k2z;
	float k3z;
	float k4z;
	float y1;
	for (int i = 0; i < N; i++)
	{
		//aplicacion del metodo runge kutta para la primera derivada de la distancia
		k1 = h*f(x+h, y, v);
		k2 = h*f(x + h/2, y+(h/2*k1), v);
		k3 = h*f(x + h/2, y+(h/2*k2), v);
		k4 = h*f(x + h, y+(h*k3), v);
		//modificacion de la distancia por los promedios del metodo
		y = y + (h*(k1 + 2*k2 + 2*k3 + k4)/6);
		//evolucion temporal
		x = x + h;
		y1 = y;
		//aplicacion del metodo tunge kutta para la derivada de la velocidad
		k1z = h*fz(x+h, y1, v);
		k2z = h*fz(x+h/2, y1, v+(h/2*k1));
		k3z = h*fz(x+h/2, y1, v+(h/2*k2));
		k4z = h*fz(x+h, y1, v+(h*k3));
		//cambio de las velocidades por el promedio del metodo 
		v = v + (h*(k1z + 2*k2z + 2*k3z + k4z)/6);
		cout << y1 << " " << v << " " << x << endl;
	}
}
//funcion para la derivada de la velocidad
float fz(float x, float y, float v)
{
	float G=10;
	float M=1000;
	return (-G*M/(y*y));
}
//funcion para el cambio de la distancia a través del tiempo 
float f(float x, float y, float v)
{
	return v;
}
