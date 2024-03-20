#include<iostream>
#include <ostream>

using namespace std;

class Tiempo {
private:
	int segundos, minutos, horas;
	//friend es declarar
	friend istream& operator >> (istream&, Tiempo&);
	friend ostream& operator<<(ostream&, const Tiempo&); //const porque se supone que al objeto Tiempo no se cambia
public :
	Tiempo();
	Tiempo(int, int, int);
	virtual ~Tiempo();
};

Tiempo::Tiempo()
{
	horas = 0;
	minutos = 0,
		segundos = 0;
}

Tiempo::Tiempo(int horas_, int minutos_, int segundos_)
{
	horas = horas_;
	minutos = minutos_;
	segundos = segundos_;

}

Tiempo::~Tiempo()
{
}
//Sobrecarga del operador de flujo de entrada
//Aqui es donde se da el ingreso de horas,minutos y segundos a un
//obejto, separado por un espacio o por (enter)
istream& operator >> (istream&inp, Tiempo&t) {
	inp >> t.horas >> t.minutos >> t.segundos;
	return inp;//Este flujo de entrada esta cargando la informacion del objeto
}

//sobrecarga del poredor de flujo de salida,
//LLea un objeto a la derecha de << y se 
//imprime la informacion del objeto T de acuerdo
//a un gormato de salida ====>toString().
ostream& operator<<(ostream&outp, const Tiempo&t) {
	outp << "Horas ......" << t.horas << "minuto..." << t.minutos << "segundos..." << t.segundos << endl;
	return outp;

}

int main() {

	Tiempo tiempo;
	cout << "Introduzca los tres valores" << endl;
	cin >> tiempo; //aqui para que esto trabaje, debe estar sobrecargado el operador de flujo de entrada (>>)
	cout << endl;
	cout << "La hora ingresada fue.." << endl;
	cout << tiempo << endl;//Aqui debe estar sobrecargado el operador de flujo de salida(<<)



	system("pause");
	return 0;

}

