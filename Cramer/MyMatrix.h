#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class MyMatrix
{
private:
	int m_nrRow;
	int m_nrCol;
	int** mat;

public:

	MyMatrix();
	MyMatrix(int Nrrow, int Nrcol);
	MyMatrix(const MyMatrix& anotherMyMatrix);  //constructor de copiere
	~MyMatrix();

	friend ostream& operator << (ostream& os, const MyMatrix& matrice);
	friend istream& operator >> (istream& is, MyMatrix& matrice);

	void operator = (const MyMatrix& anotherMyMatrix);

	MyMatrix& transpusa();

};
