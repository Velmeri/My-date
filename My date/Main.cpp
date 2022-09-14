#include <iostream>
#include "Date.h"

using namespace std;

int main() {
	Date A(2, 3, 2005);
	Date B(1, 3, 2005);
	cout << (B >= A);

	return 0;
}