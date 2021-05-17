#include <iostream>
#include "MyMatrix.h"
using namespace std;

MyMatrix::MyMatrix()
{

}

MyMatrix::MyMatrix(const MyMatrix& anotherMyMatrix)
{
	*this = anotherMyMatrix;
}

MyMatrix::MyMatrix(int Nrrow, int Nrcol)
{
	m_nrRow = Nrrow;
	m_nrCol = Nrcol;

	mat = new int* [m_nrRow];
	for (int i = 0; i < m_nrRow; i++)
	{
		mat[i] = new int[m_nrCol];
	}
}

MyMatrix::~MyMatrix()
{
	for (int i = 0; i < this->m_nrRow; i++)
	{
		delete[] this->mat[i];
	}
	delete[] this->mat;
}


std::ostream& operator<<(std::ostream& os, const MyMatrix& matrice)
{
	for (int i = 0; i < matrice.m_nrRow; i++)
	{
		for (int j = 0; j < matrice.m_nrCol; j++)
		{
			os << matrice.mat[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, MyMatrix& matrice)
{
	for (int i = 0; i < matrice.m_nrRow; i++)
	{
		for (int j = 0; j < matrice.m_nrCol; j++)
		{
			is >> matrice.mat[i][j];
		}
	}
	return is;
}


void MyMatrix::operator=(const MyMatrix& anotherMyMatrix)
{
	if (m_nrCol == anotherMyMatrix.m_nrCol && m_nrRow == anotherMyMatrix.m_nrRow)
	{
		for (int i = 0; i < m_nrRow; i++)
			for (int j = 0; j < m_nrCol; j++)
				mat[i][j] = anotherMyMatrix.mat[i][j];
	}
}

MyMatrix& MyMatrix::transpusa()
{
	MyMatrix Mat2;
	Mat2.m_nrRow = m_nrRow;
	Mat2.m_nrCol = m_nrCol;
	

	Mat2.mat = new int* [Mat2.m_nrRow];

	for (int i = 0; i < Mat2.m_nrRow; i++)
	{
		Mat2.mat[i] = new int[Mat2.m_nrCol];
	}
	/*MyMatrix mat2(m_nrRow, m_nrCol);*/

	for (int i = 0; i < m_nrRow; i++)
	{
		for (int j = 0; j < m_nrCol; j++)
		{
			Mat2.mat[j][i] = mat[i][j];
		}
	}

	cout << "Matriceatranspusa: " << endl;

	for (int i = 0; i < m_nrCol; i++)
	{
		for (int j = 0; j < m_nrRow; j++)
		{
			cout << Mat2.mat[i][j] << " ";
		}
		cout << endl;
	}
	return Mat2;
}
