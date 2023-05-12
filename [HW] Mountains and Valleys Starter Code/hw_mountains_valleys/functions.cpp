
#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	return (a<=b)&&(a>=10)&&(b>=0)&&(b<10000);//check if number in range between 10 and 9999
	return false;
}
char classify_mv_range_type(int number) {
	int num1 = 0;
	int num2 = 0;
	bool increasing = false;
	bool decreasing = false;
	while (number > 0 && (number / 10) != 0)
	{
		num1 = number % 10; //first digit
		number /= 10;  //second digit
		num2 = number % 10; // third digit
		if (num2 > num1) {
			if (!increasing && decreasing){return 'N'; }
			increasing = false;
			decreasing = true;
			if (number / 10 == 0){return 'V'; }
		}
		else if (num1 > num2){
			if (!decreasing && increasing) {return 'N';}
			increasing = true;
			decreasing = false;
			if (number / 10 == 0){return 'M';}
		}
		else {return 'N';}
	}
	return 'N';
}
void count_valid_mv_numbers(int a, int b) {
	int mountains = 0;
	int valleys = 0;
	for(int i = a; i <= b; i++) {//go through range of numbers
		if(classify_mv_range_type(i) == 'M'){mountains++;}
		else if (classify_mv_range_type(i) == 'V'){valleys++;}
	}
	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "."<< std::endl;
}