//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SampleClass.h"

using namespace std;

int main()
{
	cout << "--- sample1 ---" << endl;
	SampleClass sample1 { 7 };
	sample1.print();

	cout << "--- sample2 (copia por asignación) ---" << endl;
	SampleClass sample2 = std::move(sample1);
	sample2.print();

	cout << "--- sample3 (copia por constructor) ---" << endl;
	SampleClass sample3(std::move(sample2));
	sample3.print();

	return 0;
}
