#include <iostream>
#include <array>
#include <string>
#include <fstream>
using namespace std;

template <class T>

void mySwap(T arr[100], int pos1, int pos2) {		//swaps positions of items
	T temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

template <class T>

T myMin(T arr[100]) {		//finds minimum
	T min = arr[0];
	for (int i = 0; i < 100; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

template <class T>

T myMax(T arr[100]) {		//finds maximum
	T max = arr[0];
	for (int i = 0; i < 100; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

template <class T>

int mySearch(T arr[100], T item) {		//finds item in array
	for (int i = 0; i < 100; i++) {
		if (arr[i] == item) {
			return i;
		}
	}
	return -1;
}

int main() {
	int int_arr[100];			//declaring arrays
	double double_arr[100];
	string string_arr[100];

	ifstream int_file("integers.txt");		//opening files
	ifstream double_file("doubles.txt");
	ifstream string_file("strings.txt");
	ofstream output("output.txt");

	string str1 = "Shoes", str2 = "Pumpkin";		//declaring strings because it acted a little funky when I tried to directly insert "Shoes" or "Pumpkin" into funciton argument

	for (int i = 0; i < 100; i++) {		//stores values in array
		int_file >> int_arr[i];
		double_file >> double_arr[i];
		string_file >> string_arr[i];
	}

	output << "Integers:" << endl;		//prints out information for integers
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10] " << int_arr[10] << " [20] " << int_arr[20] << endl;
	mySwap(int_arr, 10, 20);
	output << "After: [10] " << int_arr[10] << " [20] " << int_arr[20] << endl;
	output << "Minimum: " << myMin(int_arr) << endl;
	output << "Maximum: " << myMax(int_arr) << endl;
	output << "The number 1 is at position " << mySearch(int_arr, 1) << endl;
	output << "The number 5 is at position " << mySearch(int_arr, 5) << endl << endl;

	output << "Doubles:" << endl;		//prints out information for doubles
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10] " << double_arr[10] << " [20] " << double_arr[20] << endl;
	mySwap(double_arr, 10, 20);
	output << "After: [10] " << double_arr[10] << " [20] " << double_arr[20] << endl;
	output << "Minimum: " << myMin(double_arr) << endl;
	output << "Maximum: " << myMax(double_arr) << endl;
	output << "The number 4.62557 is at position " << mySearch(double_arr, 4.62557) << endl;
	output << "The number 1.23456 is at position " << mySearch(double_arr, 1.23456) << endl << endl;

	output << "Strings:" << endl;		//prints out information for strings
	output << "Swapped items at positions 10 and 20" << endl;
	output << "Before: [10] " << string_arr[10] << " [20] " << string_arr[20] << endl;
	mySwap(string_arr, 10, 20);
	output << "After: [10] " << string_arr[10] << " [20] " << string_arr[20] << endl;
	output << "Minimum: " << myMin(string_arr) << endl;
	output << "Maximum: " << myMax(string_arr) << endl;
	output << "The word Shoes is at position " << mySearch(string_arr, str1) << endl;
	output << "The word Pumpkin is at position " << mySearch(string_arr, str2);

	int_file.close();		//closing files
	double_file.close();
	string_file.close();
	output.close();
}