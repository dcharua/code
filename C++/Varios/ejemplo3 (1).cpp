#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Estudiante
{
	char nombre[20];
	int matricula;
public:
	void capturaDatos();
	void verDatos();
	void busca(int x);
};

void Estudiante ::  capturaDatos()
{
	cout << "Nombre:" << endl;
	cin >> nombre;
	cout << "Matricula:" << endl;
	cin >> matricula;
}

void Estudiante ::  verDatos()
{
	cout << "Datos del Estudiante:" << endl;
	cout << "Nombre: " <<  nombre << endl
		<< "Matricula: " <<  matricula << endl;
}

void Estudiante::busca(int x)
{
	if (matricula == x)
		cout << "Encontrado! " << endl;
}

int main(int argc, char *argv[])
{
	char res='s';
	Estudiante sobj;
	vector <Estudiante>varios;

	//Archivo en modo "append"
	
	//Primero leo los que ya estan....
	ifstream in("student.dat"); 
	if(in.is_open())
	{
		while(!in.eof())
		{
			in.read((char*) &sobj, sizeof(sobj));
			if(!in.eof())
			{
			   sobj.verDatos();
			   varios.push_back(sobj);
			}
		}
	}
	in.close();

	cout << "--------------------------------" << endl;

	//Ahora capturo uno más....
	Estudiante stu;
	stu.capturaDatos();

	//Lo añado al vector.....
	varios.push_back(stu);

	//Ahora imprimo el vector para ver
	for (int i = 0; i < varios.size(); i++)
	{
		cout << i << " es: " << endl;
		varios[i].verDatos();
	}

	//Ahora escribo el archivo....
	//En realidad escribo todo el contenido del vector y encimo todo el archivo.
	//Así que lo sobreescribo completamente.

	ofstream out("student.dat", ios::out);

	if (out.is_open())
	{
		for (int i = 0; i < varios.size(); i++)
		{
			out.write((char*)& varios[i], sizeof(varios[i]));
		} 
	}
	out.close();

	cout << "Adios...." << endl;
	int o;
	cin >> o;
}
