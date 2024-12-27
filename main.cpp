#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal Instantiate" << endl;
	}
	virtual void makeSound() {};
	virtual ~Animal() {
		cout << "Animal Destroyed !" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog Instantiate" << endl;
	}
	void makeSound() {
		cout << "Dog : meong meong !!" << endl;
	};
	~Dog() {
		cout << "Dog Destroyed" << endl;
	}
};

class Cat : public Animal {
public:
	Cat() {
		cout << "Cat Instantiate" << endl;
	}
	void makeSound() {
		cout << "Cat : nyang ! nyang !" << endl;
	}
	~Cat() {
		cout << "Cat Destroyed !" << endl;
	}
};

class Cow : public Animal {
public:
	Cow() {
		cout << "Cow Instantiate" << endl;
	}
	void makeSound() {
		cout << "Cow : mow ! mow !" << endl;
	}
	~Cow() {
		cout << "Cow Destroyed" << endl;
	}
};

int main() {
	Animal* animals[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < 3; i++) {
		delete animals[i];
	}

	return 0;
}