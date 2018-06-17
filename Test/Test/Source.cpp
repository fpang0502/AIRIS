#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Ball{
public:
	string color;
	int initialDistance;
	void ballThrow(int x){
		initialDistance = initialDistance + 50;
		cout << initialDistance;
		cout << "\n";
	}
	void ballRecieved(){
		cout << "Received\n";
	}
};

int main(){
	Ball Soccer;
	Soccer.color = "White";
	cout << Soccer.color;
	Soccer.initialDistance = 0;
	Soccer.ballThrow(0);
	Soccer.ballRecieved();
}