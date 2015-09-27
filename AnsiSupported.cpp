/*
 * AnsiSupported.cpp
 *
 *  Created on: 26-Apr-2012
 *      Author: Alok
 */

#include <iostream>
using namespace std;

template <class T>

bool ansisupported (T x) { return true; }

int main() {
  if (ansisupported(0)) cout << "ANSI OK";
  return 0;
}
