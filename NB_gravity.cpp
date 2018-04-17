#include <iostream>
using std::cout;
using std::endl;
float f(float x, float y, float v);
float fz(float x, float y, float v);
int main()
{
	float G = 10.;
	float M = 1000.; 
	float h =0.01;	
	float x=10;
	float v=100;
	float y;
	int N = 10/h;
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
		k1 = h*f(x+h, y, v);
		k2 = h*f(x + h/2, y+(h/2*k1), v);
		k3 = h*f(x + h/2, y+(h/2*k2), v);
		k4 = h*f(x + h, y+(h*k3), v);
		y = y + (h*(k1 + 2*k2 + 2*k3 + k4)/6);
		x = x + h;
		y1 = y;
		k1z = h*fz(x+h, y1, v);
		k2z = h*fz(x+h/2, y1, v+(h/2*k1));
		k3z = h*fz(x+h/2, y1, v+(h/2*k2));
		k4z = h*fz(x+h, y1, v+(h*k3));
		v = v + (h*(k1z + 2*k2z + 2*k3z + k4z)/6);
		cout << y << " " << v << " " << x << endl;
	}
}
float fz(float x, float y, float v)
{
	float G=10;
	float M=1000;
	return (-G*M/(y*y));
}
float f(float x, float y, float v)
{
	return v;
}
