#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int x;
	x=1;
	while (x!= 911){
		printf("Please provide an input.\n");
		cin >> x;
		printf("\n");
		cout << x*x;
		printf("\n");
	}
}