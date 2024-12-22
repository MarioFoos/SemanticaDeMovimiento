#ifndef SAMPLECLASS_H_
#define SAMPLECLASS_H_

#include <iostream>
#include <list>

using namespace std;

class SampleClass
{
	private:
		int *pnum;
		float fnum;
		std::string name;
		std::list<int> numbers;
	public:
		SampleClass();
		SampleClass(int num);
		// Constructor con movimiento
		SampleClass(SampleClass&& origen) noexcept;
		// Operador con movimiento
		SampleClass& operator=(SampleClass&& SampleClass) noexcept;
		virtual ~SampleClass(){};

		void print();
};
#endif /* SAMPLECLASS_H_ */
