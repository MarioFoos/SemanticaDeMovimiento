#include "SampleClass.h"
#include <cstdlib>
#include <ctime>

SampleClass::SampleClass() : SampleClass(0)
{
}
SampleClass::SampleClass(int value) : pnum(new int(value))
{
	int *temp = new int;
	srand(reinterpret_cast<uintptr_t>(temp));
	delete temp;

	fnum = (float)rand()/RAND_MAX;
	char str[2] = { 0, 0 };
	for(int i = 0; i < 10; ++i)
	{
		str[0] = (char)(rand()%('z' - 'a' + 1) + 'a');
		name.append(str);
	}
	for(int i = 0; i < 10; ++i)
	{
		numbers.push_back(rand()%20);
	}
}
// Constructor con Movimiento
SampleClass::SampleClass(SampleClass&& origen) noexcept
	: pnum(origen.pnum),
	  fnum(origen.fnum),
	  name(std::move(origen.name)),			// Uso el contructor con movimiento de string
	  numbers(std::move(origen.numbers))	// Uso el contructor con movimiento de list
{
	origen.fnum = 0;
	origen.name.clear();
	origen.numbers.clear();
	origen.pnum = nullptr;	// Liberar el recurso del objeto origen
}
// Operador con movimiento
SampleClass& SampleClass::operator=(SampleClass&& origen) noexcept
{
	if(this != &origen)
	{
		this->pnum = origen.pnum;
		origen.pnum = nullptr;		// Liberar el recurso del objeto origen
		this->fnum = origen.fnum;
		this->name = std::move(origen.name);		// Uso el operador con movimiento de string
		this->numbers = std::move(origen.numbers);	// Uso el operador con movimiento de list
	}
	return *this;
}
void SampleClass::print()
{
	cout << "pnum: " << *pnum << endl;
	cout << "fnum: " << fnum << endl;
	cout << "str: " << name << endl;
	cout << "list: " << "[";
	for(int item : numbers)
	{
		cout << item << " ";
	}
	cout << "]" << endl;
}
