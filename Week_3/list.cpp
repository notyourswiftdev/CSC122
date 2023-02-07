#include <exception>
#include <iostream>

#include "input.h"
#include "list.h"

void List::Clear()
{
	if (size > 0) {
		delete[] data;
		size=0;
		data=nullptr;
	}
}

void List::Resize(long numValues)
{
	try {
		if (numValues < 1 || numValues > MAX_SIZE) {
			throw "Error! Invalid list size specified.";
		}
		Clear();
		data=new double[numValues];
		if (data==nullptr) {
			throw "Error! Could not allocate memory for list.";
		}
		size=numValues;
	}
	catch (std::exception& e) {
		throw "Error! Could not allocate memory for list.";
	}
}

void List::SetValue(double value, long pos)
{
	if (pos < 0 || pos >= size) {
		throw "Error! Invalid position in list specified.";
	}
	data[pos]=value;
}

double List::GetValue(long pos)
{
	if (pos < 0 || pos >= size) {
		throw "Error! Invalid position in list specified.";
	}
	return data[pos];
}

void List::Input()
{
	try {
		if (size==0) {
			long x=ReadValue<long>("Number of values? ");
			Resize(x);
		}
	
		for (double *ptr=data; ptr<data+size; ptr++) {
			*ptr=ReadValue<double>("Value? ");
		}
	}
	catch (const char* s) {
		throw s;
	}

	
}

void List::Display() 
{
	if (size > 0) {
		std::cout << "List values:\n";
		for (double *ptr=data; ptr<data+size; ptr++) {
			std::cout << *ptr << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "List is emptry.\n";
	}
}


List::List()
{
	data=nullptr;
	size=0;
}

List::~List()
{
	Clear();
}
