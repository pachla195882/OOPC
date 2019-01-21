#pragma once
using namespace std;

class WrongInput : public exception {
public:
	const char* what () const throw () {
		return "Wrong input";
	}
};

class WrongMatrixDimensions : public exception {
public:
	const char* what () const throw () {
		return "Invalid dimensions";
	}
};

class NoSuchElement : public exception {
public:
	const char* what () const throw () {
		return "No such element";
	}
};

class NoMatrixExists : public exception {
public:
	const char* what () const throw () {
		return "No such matrix";
	}
};
