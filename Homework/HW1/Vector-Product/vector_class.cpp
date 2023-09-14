// Name: Aidan Cowan
// Date: 8/26/23
// Program: ECGR 3180 - Homework 1 Vector Class
// Description:
// 
// Write a C++ class that implements your version of the std::vector. 
// Write appropriate tests that tests all public methods.

#include <iostream>

class MyVector {
public:
	MyVector();							 // Default Constructor
	MyVector(int size);					 // Constructor that takes a size input
	MyVector(MyVector& vec);	         // Copy Constructor
	~MyVector();						 // Deconstructor

	// Mutators
	void pushBack(int ele);		         // Appends to the end of the array
	void insert(int i, int ele);         // Insert in the i-eth position in the array
	int operator[](int i);		 		 // Overloads the operator that reads the i-th element
	void erase(int i);					 // Deletes the i-th element


	// Accessors
	int at(int i);
	void getElements();
	int getCapacity();
	int getSize();
	bool empty();

private:
	int* elements;						// Elements in Array
	int capacity;						// Allocated capacity
	int size;							// Number of elements
};
// Constructors & Deconstructor
MyVector::MyVector() {
	capacity = 1;
	size = 0;
	elements = new int[capacity];
}
MyVector::MyVector(int size) {
	capacity = size;
	size = 0;
	elements = new int[capacity];
}
MyVector::MyVector(MyVector& vec) {
	capacity = vec.capacity;
	size = vec.size;
	elements = new int[capacity];

	for (int i = 0; i < size; i++) {
		elements[i] = vec.elements[i];
	}
}
MyVector::~MyVector() {
	delete[] elements;

	std::cout << "Deconstructor called" << std::endl;
}

// Mutators
void MyVector::pushBack(int ele) {
	if (size == capacity) {
		capacity *= 2;
		int* newElements = new int[capacity];

		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}

		delete[] elements;
		elements = newElements;
	}
	elements[size++] = ele;
}
void MyVector::insert(int i, int ele) {
	if (i > size) {
		std::cout << "Out of Range" << std::endl;
		return;
	}
	if (size == capacity) {
		capacity *= 2;
		int* newElements = new int[capacity];

		for (int j = 0; j < i; ++j) {
			newElements[j] = elements[j];
		}
		newElements[i] = ele;

		for (int j = 1; j < size; j++) {
			newElements[j + 1] = elements[j];
		}

		delete[] elements;
		elements = newElements;
	}
	else {
		for (int j = size; j > i; j--) {
			elements[j] = elements[j - 1];
		}
		elements[i] = ele;
	}
	size++;
}
void MyVector::erase(int i) {
	if (i > size) {
		std::cout << "Out of Range" << std::endl;
		return;
	}
	if (i == size) {
		size--;
	}
	else {
		for (int j = i; j < size - 1; ++j) {
			elements[j] = elements[j + 1];
		}
		size--;
	}
}

// Accessors
int MyVector::at(int i) {
	if (i > size) {
		std::cout << "Out of Range" << std::endl;
		return 0;
	}
	return elements[i];
}
int MyVector::getSize() {
	return size;
}
int MyVector::getCapacity() {
	return capacity;
}
bool MyVector::empty() {
	if (size > 0) {
		return false;
	}
	else {
		return true;
	}
}
void MyVector::getElements() {
	for (int i = 0; i < size; ++i) {
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;
}

// Operator[] Overload
int MyVector::operator[](int i) {
	return MyVector::at(i);
}



int main()
{
	MyVector vec1;
	MyVector vec2(5);

	std::cout << std::endl << "Vector v2 size: " << vec2.getCapacity() << std::endl;

	vec1.pushBack(2);
	vec1.pushBack(4);
	vec1.pushBack(6);

	MyVector vec3(vec1);

	std::cout << "Pushback Test" << std::endl;
	vec1.getElements();

	std::cout << std::endl;

	std::cout << "Insert Test" << std::endl;
	vec1.insert(2, 10);
	vec1.getElements();

	std::cout << std::endl;

	std::cout << "Element at index 1 using at(): " << vec1.at(1) << std::endl;
	std::cout << "Element at index 2 using []: " << vec1[2] << std::endl << std::endl;

	std::cout << "Element at index 0 has been deleted " << std::endl;
	vec1.erase(0);

	std::cout << std::endl << "Updated Vector" << std::endl;
	vec1.getElements();

	std::cout << std::endl << "Vector size: " << vec1.getSize() << std::endl;

	std::cout << "Vector is empty? ";

	if (vec1.empty() == 0) {
		std::cout << "False" << std::endl;
	}
	else {
		std::cout << "True" << std::endl;
	}

	std::cout << std::endl << "Copy Constructor Test: " << std::endl;
	vec3.getElements();


}