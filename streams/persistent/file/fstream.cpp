#include <iostream>
#include <fstream>
#include <string>




int main()
{

//ifstream , ofstream are output and input stream too

	//Open a file for reading
	 ifstream myfile("example.txt")
	
	// Open a file for writing
	ofstream myfile("example.txt")
	
	//Open a file in append mode:
	ofstream myfile("example.txt", ios::out | ios::app)
	
	//Read a line getline(myfile, string)
	//Close a file myfile.close()
	//Check the stream integrity my file.good()

	//Peek the next character
	char current char = myfile.peek()
	
	// Get the next character (and advance)
	char current char = myfile.get()
	
	// Get the position of the current character in the input stream
	int byte offset = myfile.tellg()
	
	// Set the char position in the input sequence
	myfile.seekg(byte offset) (absolute position)
	myfile.seekg(byte offset, position) (relative position)
	
	//where position can be: ios::beg (the begin), ios::end (the end),
	ios::cur (current position)

	//Ignore characters until the delimiter is found
	myfile.ignore(max stream size, <delim>)
	//e.g. skip until end of line nn
	
	// Get a pointer to the stream buffer object currently associated with the stream
	//my file.rdbuf()
	//can be used to redirect file stream


//Example : 
	//Open a file and print line by line:
	std::ifstream fin("example.txt");
	std::string str;
	while (fin.good()) {
		std::getline(fin, str);
		std::cout << str << "\n";
	}
	fin.close();


	//An alternative version with redirection:
	std::ifstream fin("example.txt");
	std::cout << fin.rdbuf();
	fin.close();


	//Check the current character
	while (fin.peek() != std::char_traits<char>::eof()) // C: EOF
		fin >> var;
	
	//• Check if the read operation fails
	while (fin >> var)
		//...
	
	//• Check if the stream past the end of the file
	while (true) {
		//fin >> var
		if (fin.eof())
			break;
		//...
	}


}
