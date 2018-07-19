// ask for person's name, and greet the person
#include <iostream>
#include <string>

int main()
{
	// ask fot the person's name
	std::cout << "Please enter you first name: ";

	// read the name
	std::string name;	// define name
	std::cin >> name;	// read into name

	//write a greeting
	std::cout << "Helo, " << name << "!" << std::endl;
	return 0;
}

