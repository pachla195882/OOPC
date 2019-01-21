#include "matrix.h"
#include "errors.h"
#include <iostream>

using namespace std;


Matrix::Matrix(){
	
	mat = NULL;
}


Matrix::Matrix(int x,int y){
	
	mat = new rcmat(x, y);
}


Matrix::Matrix(const Matrix& matrix){
	
	this->mat = matrix.mat;
	matrix.mat->refCount++;
	this->detach();
}


Matrix::~Matrix(){
	
	if(mat){
		mat->refCount--;

		if(mat->refCount == 0)
			delete mat;
		else
			mat = NULL;
	}
}


Matrix::rcmat::rcmat(int x,int y){
	
	this->x = x;
	this->y = y;	
	refCount = 1;

	data = new double* [y];

	for (int i = 0; i < y; i++) {
		data[i] = new double [x];
	}
}


Matrix::rcmat::rcmat(int x, int y, double** data){
	
	this->x = x;
	this->y = y;
	refCount = 1;

	this->data = new double*[y];

	for(int i = 0; i < y; i++){
		this->data[i] = new double [x];

		for(int j = 0; j < x; j++){
			this->data[i][j] = data[i][j];
		}
	}
}


Matrix::rcmat::~rcmat(){

	for (int i = 0; i < y; i++){
		delete[] data[i];
	}

	delete[] data;
}


bool Matrix::checkDimensions(const Matrix& matrix){
	
	return (mat->x == matrix.mat->x && mat->y == matrix.mat->y);
}


bool Matrix::canMultiply(const Matrix& matrix){
	
	return (mat->y == matrix.mat->x);
}


void Matrix::detach(){
	
	if(mat)
		if(mat->refCount > 1){
			mat->refCount--;
			mat = new rcmat(mat->x, mat->y, mat->data);
		}
}


bool Matrix::operator==(const Matrix& matrix){
	
	return (this->mat) == (matrix.mat);
}


Matrix& Matrix::operator+=(const Matrix& matrix){

	if(this->checkDimensions(matrix)){
		this->detach();
		for(int i = 0; i < this->mat->y; i++){
			for(int j = 0; j < this->mat->x; j++){
				this->mat->data[i][j] += matrix.mat->data[i][j];
			}
		}
		return *this;
	}
	else abort();
		throw WrongMatrixDimensions();
}


Matrix& Matrix::operator-=(const Matrix& matrix){
	
	if(this->checkDimensions(matrix)){
		this->detach();
		for(int i = 0; i < this->mat->y; i++){
			for(int j = 0; j < this->mat->x; j++){
				this->mat->data[i][j] -= matrix.mat->data[i][j];
			}
		}
		return *this;
	}
	else
		throw WrongMatrixDimensions();
}


Matrix& Matrix::operator*=(const Matrix& matrix){
	
	*this = *this * matrix;
	return *this;
}


Matrix Matrix::operator+(const Matrix& matrix){
	
	Matrix newMat(*this);
	newMat += matrix;
	return Matrix(newMat);
}


Matrix Matrix::operator-(const Matrix& matrix){
	
	Matrix newMat(*this);
	newMat -= matrix;
	return Matrix(newMat);
}


Matrix Matrix::operator*(const Matrix& matrix){
	
	if(this->canMultiply(matrix)){
		Matrix newMat(this->mat->x, matrix.mat->y);

		for(int i = 0; i < this->mat->y; i++){
			for(int j = 0; j < matrix.mat->x; j++){
				newMat.mat->data[i][j] = 0;
				for (int compI = 0; compI < matrix.mat->x; compI++){
					newMat.mat->data[i][j] += (matrix.mat->data[i][compI] * matrix.mat->data[compI][j]);
				}
			}
		}
		return newMat;
	}
	else
		throw WrongMatrixDimensions();
}


void Matrix::operator=(const Matrix& matrix){
	
	if(this->mat){
		this->mat->refCount--;
		if(this->mat->refCount == 0)
			delete this->mat;
	}

	this->mat = matrix.mat;
	matrix.mat->refCount++;
}


ostream & operator<<(ostream& out, const Matrix& matrix){
	
	if(matrix.mat){
		for(int i = 0; i < matrix.mat->y; i++){
			for(int j = 0; j < matrix.mat->x; j++){
				out << matrix.mat->data[i][j];
				if (j != matrix.mat->x - 1)
					out << "	";
			}
			out << endl;
		}
	}
	else
		out << "Matrix is empty" << endl;
	return out;
}


istream & operator>>(istream& in, Matrix& matrix){

	int x, y;
	if (!matrix.mat){
		if(&in == &cin){
			cout << "Put dimensions: ";
		}
		while(true){
			if((in >> y) && (in >> x))
				break;
			else
				throw WrongInput();
		}

		matrix.mat = new Matrix::rcmat(x, y);
	}

	if (!matrix.mat)
		throw NoMatrixExists();

	if(&in == &cin)
		cout << "Fill in " << matrix.mat->y << "x" << matrix.mat->x << " matrix:" << endl;

	for(int i = 0; i < matrix.mat->y; i++){
		for(int j = 0; j < matrix.mat->x; j++){
			while(true){
				if(in >> matrix.mat->data[i][j])
					break;
				else
					throw WrongInput();
			}
		}
	}
	return in;
}


Matrix::Mref Matrix::operator()(int x,int y){
	if (x - 1 > this->mat->x || y - 1 > this->mat->y){
		throw NoSuchElement();
	}
	return Mref(*this, x - 1, y - 1);
}


Matrix::Mref::operator double() const{
	return matrix.mat->data[x][y];
}


Matrix::Mref& Matrix::Mref::operator=(double n){
	matrix.detach();
	matrix.mat->data[y][x] = n;
	return *this;
}

Matrix::Mref& Matrix::Mref::operator=(const Mref& ref){
	return operator=((double)ref);
}
