##include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <string>
#include "FLinkedList.h"

using namespace std;

int main(void) {
	ifstream file("Text.txt");
	string line;
	while (getline(file, line)) {
		cout << line<<"\n";
	}

	float n, temp, Sxy, Sxx, Syy, Sx, Sy, Sxs, Sys, Sexy, r;
	
	cout << "How many sets of values?\n>";
	cin >> n;

	node lillyX, lillyY;

	cout << "Please input each x value one at a time.\n>";
	cin >> lillyX.data;

	for (int i = 1; i < n; i++) {
		cout << ">";
		cin >> temp;
		lillyX.append(temp);
	}

	cout << "Please input each y value one at a time.\n>";
	cin >> lillyY.data;

	for (int i = 1; i < n; i++) {
		cout << ">";
		cin >> temp;
		lillyY.append(temp);
	}

	Sx = 0;
	Sy = 0;
	Sxs = 0;
	Sys = 0;
	Sexy = 0;
	Sxy = 0;
	for (int i = 0; i < n; i++) {
		Sx += lillyX.retrieve(i);
		Sy += lillyY.retrieve(i);
		Sxs += pow(lillyX.retrieve(i),2);
		Sys += pow(lillyY.retrieve(i),2);
		Sexy += lillyX.retrieve(i) * lillyY.retrieve(i);
	}
	cout << "Sx:\t" << Sx << "\n";
	cout << "Sy:\t" << Sy << "\n";
	cout << "Sxs:\t" << Sxs << "\n";
	cout << "Sys:\t" << Sys << "\n";

	Sxx = Sxs - (pow(Sx, 2) / n);
	cout << "Sxx:\t" << Sxx << "\n";
	Syy = Sys - (pow(Sy, 2) / n);
	cout << "Syy:\t" << Syy << "\n";
	Sxy = Sexy - ((Sx * Sy) / n);
	cout << "Sxy:\t" << Sxy << "\n";

	r = Sxy / (sqrt(Sxx * Syy));

	cout << "\nPMCC:\t" << r;
	cin >> temp;
}
