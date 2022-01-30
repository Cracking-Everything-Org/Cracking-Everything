#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

struct Gomita {
	int d;
	int h;
	int c;

	Gomita(int a, int b, int p) {
		d = a;
		h = b;
		c = p;
	}
};

void GomitasAux(vector<Gomita> gomitas, int desdeActual, int hastaActual, int costoActual, int costoMaximo, int largo, int &costoOpt, int posActual)
{
	if (gomitas.size() == posActual) {
		if (costoActual < costoMaximo && desdeActual <= largo && hastaActual >= largo) {
			costoOpt = costoActual;
		}
		return;
	}
	for (int i = posActual; i < gomitas.size(); i++)
	{
		Gomita gomitaActual = gomitas[i];
		int nuevoDesde = gomitaActual.d + desdeActual;
		int nuevoHasta = gomitaActual.h + hastaActual;
		int nuevoCosto = gomitaActual.c + costoActual;
		if (nuevoDesde <= largo && nuevoCosto <= costoMaximo) {
			GomitasAux(gomitas, nuevoDesde, nuevoHasta, nuevoCosto, costoMaximo, largo, costoOpt, i + 1);
		}
	}
}

void Gomitas() {
	fstream myfile("../../tryhard2.txt");
	ofstream mynewfile("../../resultado.txt");
	if (myfile.is_open())
	{
		int tc;
		int actual = 1;
		myfile >> tc;
		while (tc--)
		{
			int n, m, l;
			int costoOpt = MAX;
			myfile >> n >> m >> l;

			vector<Gomita> gomitas;
			while (n--) {
				int a, b, p;
				myfile >> a >> b >> p;
				gomitas.push_back(Gomita(a, b, p));
			}
			GomitasAux(gomitas, 0, 0, 0, m, l, costoOpt, 0);

			if (mynewfile.is_open())
			{
				if (costoOpt != MAX)
					mynewfile << "Caso " << actual << ": " << costoOpt;
				else
					mynewfile << "Caso " << actual << ": " << "IMPOSIBLE";
				if
					(tc > 0) mynewfile << endl;
			}
			actual++;
		}
		myfile.close();
		mynewfile.close();
	}
	else
		cout << "Unable to open file";
}

int main() {
	Gomitas();
	//system("pause");
	return 0;
}

