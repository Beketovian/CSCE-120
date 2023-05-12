#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
	int a, b;
	cin >> a >> b;
	bool input = is_valid_range(a,b);
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	while(!input){
		cout << "Invalid Input" << endl << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a >> b;
		input = is_valid_range(a,b);
	}
	count_valid_mv_numbers(a,b);
	return 0;
}