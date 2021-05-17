#include <iostream>
#include <fstream>
#include "MyMatrix.h"
using namespace std;

int main()
{
	ifstream f("coef.txt");
	int nrRow;
	int nrCol;
	f >> nrRow >> nrCol;

	MyMatrix Mat = MyMatrix(nrRow, nrCol);
	MyMatrix matTrans = MyMatrix(nrRow, nrCol);

	f >> Mat;
	cout << "Matricea coeficientilor necunoscutelor: " << endl << Mat;

	ifstream g("tliberi.txt");
	int nr;

	g >> nrRow >> nrCol;
	MyMatrix MatLib = MyMatrix(nrRow, nrCol);
	g >> MatLib;

	cout << "Matricea termenilor liberi: " << endl << MatLib;

	/*matTrans = Mat.transpusa();
	cout << "Matinitiala" << Mat;*/
	cout << endl << Mat.transpusa();

	system("pause");
	return 0;
}