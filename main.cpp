#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class rect
{
	double l;//long 
	double w;//wigth
public:
	double S;
	rect(double lo, double wi)//инициализация 
	{
		l = lo;
		w = wi;
	}

	void area()
	{
		S = l * w;
	}
	void prin()
	{

		cout << "area:" << S << " long:" << l << " wigth:" << w << endl;
		
	}
};

int main()
{
	int n; // колличество прямоугольников 
	double min;
	double LL, WW; // вспомогательные переменные: длинна, ширина
	ifstream fint("MyRect.txt");
	ofstream foutt("MyRectWrite.txt");
	if (!fint)
	{
		cout << endl << "Error";
	}
	fint >> n; // чтение колличества прямоугольников 
	rect** ppA; //массив прямоугольников 
	ppA = new rect * [n];
	fint >> min;// минимальное значение площади 
	for (int i = 0; i < n; i++)
	{
		fint >> LL;//long
		fint >> WW;//wight
		ppA[i] = new rect(LL, WW);
		ppA[i]->area();
		if (ppA[i]->S > min)
			foutt << ppA[i]->S << " "<< LL << " " << WW << " ";
		delete ppA[i];
	}
	delete ppA;
	fint.close();
	foutt.close();
}
