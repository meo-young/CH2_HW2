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
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int animalCount;
public:

	Zoo() {
		animalCount = 0;
	}
	// 동물을 동물원에 추가하는 함수
	// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
	// - 같은 동물이라도 여러 번 추가될 수 있습니다.
	// - 입력 매개변수: Animal* (추가할 동물 객체)
	// - 반환값: 없음
	void addAnimal(Animal* animal) {
		if (animalCount >= 10)
			return;

		animals[animalCount] = animal;
		animalCount++;
	};

	// 동물원에 있는 모든 동물의 행동을 수행하는 함수
	// - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	void performActions() {
		for (int i = 0; i < animalCount; i++) {
			animals[i]->makeSound();
		}
	};

	// Zoo 소멸자
	// - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
	// - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	~Zoo() {
		for (int i = 0; i < animalCount; i++) {
			delete animals[i];
		}
	};
};

Animal* createRandomAnimal()
{
	int randNum = (std::rand() % 3); // [0, 2] 범위의 난수

	Animal* animal;

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
		animal = new Dog();
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