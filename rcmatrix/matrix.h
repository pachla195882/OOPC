#pragma once
#include <iostream>

using namespace std;

class Matrix{
	struct rcmat;
private:
	rcmat *mat;
	void detach();
	bool checkDimensions(const Matrix&);
	bool canMultiply(const Matrix&);
public:
	class Mref;
	Matrix();
	Matrix(int x, int y);
	Matrix(const Matrix& mx);
	~Matrix();
	
	Mref operator()(int x, int y);
	bool operator==(const Matrix& matrix);
	Matrix& operator+=(const Matrix& matrix);
	Matrix& operator-=(const Matrix& matrix);
	Matrix& operator*=(const Matrix& matrix);
	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	void operator= (const Matrix& matrix);
	friend ostream & operator<<(ostream&, const Matrix& matrix);
	friend istream & operator>>(istream&, Matrix& matrix);
};


struct Matrix::rcmat {
	double **data;
	unsigned int x, y, refCount;
	rcmat(int x, int y);
	rcmat(int x, int y, double**);
	~rcmat();
};



class Matrix::Mref {
	friend class Matrix;
	Matrix& matrix;
	int x, y;
	Mref (Matrix& cmx, int x, int y): matrix(cmx), x(x), y(y) {}
public:
	operator double() const;
	Matrix::Mref& operator=(double n);
	Matrix::Mref& operator=(const Mref& ref);
};
