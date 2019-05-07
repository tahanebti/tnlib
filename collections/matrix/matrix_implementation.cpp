//
//	matrix class implementation
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;


template <class T>
class Matrix {
public:
	Matrix(int, int); 
	~Matrix(); 			  
	
	Matrix* operator+(const Matrix &) const; 
	Matrix &operator=(const Matrix &); 
	Matrix* operator*(const Matrix &) const;

	friend istream& operator>>(istream& input, Matrix &); 
	friend ostream& operator<<(ostream& output, const Matrix &);

	void Set(T[]);
	void Print();

	void find_Min();

private:
	int col, row;
	T **matrix;
};

stringstream Form_input(const int&, const int&);

template <class T>
Matrix<T>::Matrix(int r, int c) : row(r), col(c) {
	matrix = new T*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new T[col];
	}
}


template <class T>
Matrix<T>::~Matrix() {
	if (col > 0) {
		for (int i = 0; i < row; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
}


template <class T>
Matrix<T>* Matrix<T>::operator+(const Matrix<T> &right) const {
	if (row != right.row || col != right.col) { 
		cout << "Matrix dimensions don't allow sum!";
		exit(1);
	}
	else {
		Matrix *result = new Matrix<T>(row, col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				result->matrix[i][j] = matrix[i][j] + right.matrix[i][j];
		return result;
	}
}


template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &A) = default;


template <class T>
Matrix<T>* Matrix<T>::operator*(const Matrix<T> &right) const {
	Matrix *result = new Matrix<T>(row, right.col);
	int i, j, k;
	if (col == right.row) {
		for (i = 0; i < row; i++)
			for (j = 0; j < right.col; j++)
				result->matrix[i][j] = 0;
		for (i = 0; i < row; i++)
		 
			for (j = 0; j < right.col; j++)
						for (k = 0; k < col; k++)
					result->matrix[i][j] += this->matrix[i][k] * right.matrix[k][j];
		return result;
	}
	else {
		cout << "Matrix dimensions don't allow multiplication!";
		exit(1);
	}
}


template <class T>
istream &operator>>(istream &input, Matrix<T> &A) {
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			input >> A.matrix[i][j];
	return input;
}


template <class T>
ostream &operator<<(ostream& output, const Matrix<T> &A) {
	for (int i = 0; i < A.row; i++) {
		for (int j = 0; j < A.col; j++)
			output << setw(6) << A.matrix[i][j]; 
		output << std::endl;
	}
	return output;
}

 
template <class T>
void Matrix<T>::Set(T in[]) {
	int k;
	for (int i = 0, k = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++) {
			this->matrix[i][j] = in[k];
			k++;
		}
}

template <class T>
void Matrix<T>::Print() {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++)
			cout << setw(8) << this->matrix[i][j]; 
		cout << endl;
	}
}


template <class T>
void Matrix<T>::find_Min() {
	int i, j;
	T *min = new T[this->row];
	for (i = 0; i < this->row; i++)
		min[i] = this->matrix[i][0];

	for (i = 0; i < this->row; i++)
		for (j = 0; j < this->col; j++)
			if (this->matrix[i][j] <= min[i])
				min[i] = this->matrix[i][j];

	for (i = 0; i < this->row; i++)
		cout << setw(5) << min[i];
	cout << endl;
}



stringstream Form_input(const int& rows, const int& columns) {
	stringstream input;
	for (int i = 0; i < rows*columns; i++)
		input << rand() % 20 << " ";
	return input;
}


int main()
{
	const int rows(3), columns(3);
	Matrix <int> A(rows, columns);
	int array1[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int array1[1] = { 1 };
	A.Set(array1);
	cout << A << endl;

	Matrix <double> B(rows, columns);
	double array2[12] = { 1.44,2.56,3.89,4.32,5.88,6.222,7.55,8.55,9.22 };
	B.Set(array2);
	cout << B << endl;

	Matrix <string> C(2, 2);
	string array3[4] = { "one", "two", "three", "four" };
	C.Set(array3);
	cout << C << endl;

	Matrix <int> D = *(A + A);
	cout << D << endl;

	Matrix <int> E(rows, columns);
	Form_input(rows, columns) >> E;

	Matrix <int> F = *(A*E);
	cout << F << endl;

	A.find_Min();
	cout << endl;

	B.find_Min();
	cout << endl;

	C.find_Min();
	cout << endl;


	return 0;
}