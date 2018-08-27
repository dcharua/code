#include<iostream>
#include<fstream>
using namespace std;

class Estudiante
{
	char nombre[20];
	int matricula;
public:
	void capturaDatos();
	void verDatos();
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

int main(int argc, char *argv[])
{
	char res='s';
	Estudiante sobj;

	//Archivo en modo "append"
	ofstream out("student.dat", ios::app);

	if(out.is_open())
	{
                do
		{
	        	sobj.capturaDatos();
			out.write((char*) & sobj, sizeof(sobj));
			cout << endl << "Continuar?";
			cin >> res;
		}
		while( res == 's');
	}
	out.close();

	ifstream in("student.dat");
	if(in.is_open())
	{
		while(!in.eof())
		{
			in.read((char*) &sobj, sizeof(sobj));
			if(!in.eof())
			{
			sobj.verDatos();
			}
		}
	}
	in.close();
}
