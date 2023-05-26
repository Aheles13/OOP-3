#include <iostream>
#include <vector>
#include <iterator>
#include <string>

// Студент и проффесор
class Person
{
protected:
	std::string name;
	int age;
public:
	Person(std::string name, int age)
	{
		this->name = name; // this - это 
		this->age = age;
	}
	virtual void ShowData() = 0; // virtual -  Допустим у нас одинаковые поля в других функациях мы можем поставить (virtual)

	/*void ShowData()
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age  << "\n";

	}*/

};

class Student : public Person
{
private:
	std::vector<int> _marks;

public:
	Student(std::string name, int age, std::vector<int>&marks) : Person(name, age)
	{
		_marks = marks;
	}

	void ShowData()override   // override - даёт нам право изменить функцию, то что нам нужно 
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Marks: " << '\n';
		for (const auto& it : _marks)
			std::cout << it << " " ;

	}

};

class Professor : public Person 
{
private:
	std::string _degree;
public:
	Professor(std::string name, int age, std::string degree) : Person(name, age)
	{
		_degree = degree;
	}
	void ShowData() override 
	{
		std::cout << "Name: " << name << '\n';
		std::cout << "Age: " << age << '\n';
		std::cout << "Degree: " << _degree << '\n';
	}
};

// Работяга и закуп
class Worker
{
private:
	std::string _name;
	int _age;
	float _bill;
public:
	Worker(std::string name, int age) : _name(name ), _age(age), _bill(0)
	{}
	virtual void Work() = 0; // Чистая вирутальная функция.


	void Bill(int hoursOfWork)
	{
		_bill = 250.0f * hoursOfWork;
		std::cout << "Bill: " << _bill << "\n";
	}

	std::string GetName()
	{
		return _name;
	}

	int GetAge()
	{
		return _age;
	}

	float GetBill()
	{
		return _bill;
	}
};

class Buyer : public Worker
{
public:
	Buyer(std::string name, int age) : Worker(name, age){}

	void Work() override
	{
		std::cout << GetName() << " - " << GetAge() << "year's old" << ": " << "is bying something" << '\n';
		
	}
};

class Builder : public Worker
{
public:
	Builder(std::string name, int age) : Worker(name, age){}

	void Work() override
	{
		std::cout << GetName() << " - " << GetAge() << "year's old" << ": " << "is bying something" << '\n';
		
	}
};

int main() {
	setlocale(LC_ALL, "RU");

	//Cписок студента и преподавтеля 
	/*std::vector<int>marks = { 5,3,4,2,3,2 };
	Student student ("JOhn", 20, marks);
	Professor professor ("Alisa", 18, "Dok");
	std::cout << "Student: " << '\n';
	student.ShowData();
	std::cout << "\n\nProfessor: " << '\n';
	professor.ShowData();*/

	//Работяги и Закуп

	/*Buyer buy("John", 20);
	Builder build("Alex", 35);
	buy.Work();
	buy.Bill(20);
	std::cout << "\n\n";
	build.Work();
	build.Bill(30);*/









	return 0;
}