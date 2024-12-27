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

class Zoo {
private:
	Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
	int animalCount;
public:

	Zoo() {
		animalCount = 0;
	}
	// ������ �������� �߰��ϴ� �Լ�
	// - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
	// - ���� �����̶� ���� �� �߰��� �� �ֽ��ϴ�.
	// - �Է� �Ű�����: Animal* (�߰��� ���� ��ü)
	// - ��ȯ��: ����
	void addAnimal(Animal* animal) {
		if (animalCount >= 10)
			return;

		animals[animalCount] = animal;
		animalCount++;
	};

	// �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
	// - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: ����
	void performActions() {
		for (int i = 0; i < animalCount; i++) {
			animals[i]->makeSound();
		}
	};

	// Zoo �Ҹ���
	// - Zoo ��ü�� �Ҹ�� ��, ���� ���Ϳ� ����� ��� ���� ��ü�� �޸𸮸� �����մϴ�.
	// - �޸� ������ �����ϱ� ���� ���� �Ҵ�� Animal ��ü�� `delete` �մϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: ����
	~Zoo() {
		for (int i = 0; i < animalCount; i++) {
			delete animals[i];
		}
	};
};

Animal* createRandomAnimal()
{
	std::srand(std::time(nullptr)); // ���� �ð��� �õ�� ����
	int randNum = (std::rand() % 3); // [0, 2] ������ ����

	Animal* animal{};

	switch (randNum)
	{
	case 0:
		animal = new Dog();
		break;
	case 1:
		animal = new Cat();
		break;
	case 2:
		animal = new Cow();
		break;
	default:
		break;
	}

	return animal;
}

int main() {
	/*Animal* animals[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < 3; i++) {
		delete animals[i];
	}*/

	Animal* animal[10];

	for (int i = 0; i < 10; i++) {
		animal[i] = createRandomAnimal();
	}

	Zoo* zoo = new Zoo();

	for (int i = 0; i < 10; i++) {
		zoo->addAnimal(animal[i]);
	}

	zoo->performActions();

	delete zoo;
	return 0;
}