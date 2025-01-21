/*
 ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
 ▀▀▀▀█░█▀▀▀▀ ▐░▌░▌     ▐░▌ ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌           ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀
	 ▐░▌     ▐░▌▐░▌    ▐░▌     ▐░▌          ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌               ▐░▌               ▐░▌▐░▌
	 ▐░▌     ▐░▌ ▐░▌   ▐░▌     ▐░▌          ▐░▌          ▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░▌               ▐░▌      ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄
	 ▐░▌     ▐░▌  ▐░▌  ▐░▌     ▐░▌          ▐░▌          ▐░▌     ▐░░░░░░░░░░░▌▐░▌               ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
	 ▐░▌     ▐░▌   ▐░▌ ▐░▌     ▐░▌          ▐░▌          ▐░▌     ▐░█▀▀▀▀▀▀▀█░▌▐░▌               ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀▀▀
	 ▐░▌     ▐░▌    ▐░▌▐░▌     ▐░▌          ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌               ▐░▌     ▐░▌          ▐░▌
 ▄▄▄▄█░█▄▄▄▄ ▐░▌     ▐░▐░▌ ▄▄▄▄█░█▄▄▄▄      ▐░▌      ▄▄▄▄█░█▄▄▄▄ ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌
 ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀

*/

#include <iostream>
#include <fstream>
#include <string>

struct myWork {
	int n;

	// OFSTREAM
	std::fstream textfile;

	myWork(); // CONSTRUCTOR
	bool textFile(const char* filename); // for the textfile
	// INITIALIZE THE FUNCTION FOR RECUTSION
	int Factorial(int);
	void vivod();

	// DESTRUCTOR FOR CLOSE THE FILE
	~myWork() {
		if (textfile.is_open()) { // For the open File
			textfile.close(); // just close the file
		}
	}
};

// CONSTRUCTOR
myWork::myWork() {
	std::cout << "Write the n: "; std::cin >> n;
}

// FOR TEXTFILE
bool myWork::textFile(const char* filename) {
	textfile.open(filename, std::ios::in | std::ios::out | std::ios::trunc); // for write and read
	if (!textfile.is_open()) {
		std::cerr << "ERROR TO CREATE FILES!";
		return false;
	}
	return true;
}

// LINEAR RECURSION
int myWork::Factorial(int n) {
	// THE BASE FOR NULL
	if (n == 0) {
		return 0;
	}

	// FOR THE NEGATIVE NUMBERS
	if (n < 0)
		Factorial(-n);
	// recursive case
	return Factorial(n - 1) + 2 * (n - 1) + 1;
}

// THE conclusion
void myWork::vivod() {

	// JUST FOR 
	int commone = Factorial(n);

	std::cout << "Result: " << commone;
	textfile << "Result: " << commone; // the conclusion textfile

	textfile.seekg(0); // 

	// Read and display file contents
	std::string line;
	std::cout << "\nThe file:\n";
	while (std::getline(textfile, line)) {
		std::cout << line << std::endl;
	}
}

int main() {
	myWork work; // initialize for structure

	// examination
	if (!work.textFile("RQ.txt")) {
		std::cerr << "ERROR TO CREATE THE FILE!";
		return 1;
	}

	// conclusion function
	work.vivod();

	return 0;
}