#include <iostream>
#include <string>

using namespace std;

int Square(int x){
	//function 'Square' with integer parameter with return type int
	x = x*x;
	//input value of x will be multiplied by itself and becomes the new value of x
	cout << x;
	//prints out the value of x
	return x;
	//returns the value of x and ends program
}

class DualBlade{
	//creates a class called 'DualBlade'
public:
	//allows DualBlade to beused in the main
	int mp;
	//gives an integer value to DualBlade called mp
	string name;
	//gives a string value to DualBlade called name
	void talk(string input);
	//creates a function called 'talk' that takes in a string input that does not require a return value
	DualBlade(int dmp, string dname){
		mp = dmp;
		name = dname;
	}
	//allows creation of object with type DualBlade a dmp and dname
	DualBlade(){

	}
	//allows creation of DualBlade object with no parameters
}; 

void DualBlade::talk(string input){
	//constructer function that allows DualBlade to have a function named 'talk' that takes in a desired string input
	cout << input;
	//prints the desired string input
}

void Timeskip(DualBlade Leo){
	//function 'Timeskip' in reference to DualBlade
	if (Leo.mp >= 50){
	//condition statement: if Leo's mp is greater than or equal to 50...
	cout << "Woosh";
	//print out "Woosh"
	}
}

int main(){

	DualBlade B(500, "Jon");
	//creates a DualBlade object called B with mp = 500 and name 'Jon'
	DualBlade A;
	//creates DualBlade object called A
	A.name = "sdfee";
	//sets A's name to 'sdfee'
	cout << A.name;
	//prints out A's name
	cout << "\n";
	cout << B.name;
	cout << "\n";
	cout << B.mp;
	cout << "\n";
	//prints out B's name
	A.talk("Hello World\n");
}