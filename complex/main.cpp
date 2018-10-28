/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: radek
 *
 * Created on 19 października 2016, 17:51
 */

#include <iostream>
#include "complex.h"
using namespace std;

/*
 * 
 */
int main() {
  Complex a(0.0,15),b(0,13),c;
  c = 10;
  cout << c <<endl;
  c = -a;
  cout << c <<endl;  
  c = a + b;
  c = c - Complex(10);
  cout << c <<endl;  
  c = 10 - a;
  (c -=b) -=10;
  cout << c <<endl;
    
  return 0;
}

