#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int addition(int x, int y){
	// creates a function called addition taking in variables with parameters x and y
	int z = x + y;
	// creates integer 'z' and is equivalent to parameters x and y
	cout << z;
	// prints out value of z;
	return z;
	// ends application after receiving value of z
}

void quack(){
	// creates function 'quack' no parameters; only does what is inside
	cout << "Quack";
}

class Tsum {
	// creates a class called Tsum
public:
	// sets the accessibility to public
	float price;
	// creates a float called price
	string color;
	// creates a string called color
};

int main()
{
	Tsum Baymax;
	// calls in the class 'Tsum' and names it Baymax
	Baymax.price = 9.99;
	// assigns the price of new Tsum "Baymax" as 9.99
	Baymax.color = "White";
	// assigns the color of Baymax as White
	cout << Baymax.price;
	cout << "\n";
	// prints out price of Baymax
	cout << Baymax.color;
	cout << "\n";
	// prints out color of Baymax
	return 0;
}
