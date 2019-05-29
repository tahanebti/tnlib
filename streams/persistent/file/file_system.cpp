//
//  file system library
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>
# include <filesystem> // required

/*
	C++17 introduces abstractions and facilities for performing
	operations on file systems and their components, such as paths,
	files, and directories
*/



int main()
{
	namespace fs = std::filesystem;
	fs::path p1 = "/usr/lib/sendmail.cf"; // portable format
	fs::path p2 = "C:\\users\\abcdef\\"; // native format
	std::cout << "p1: " << p1; // /usr/lib/sendmail.cf
	std::cout << "p2: " << p2; // C:\users\abcdef\
	std::cout << "p3: " << p2 + "xyz\\"; // C:\users\abcdef\xyz\

	//Decomposition (member) methods:
		// Return root-name of the path
			root_name()
		// Return path relative to the root path
			relative_path()
		// Return the path of the parent path
			parent_path()
		// Return the filename path component
			filename()
		// Return the file extension path component
			extension()
		//Check if a file or path exists
			exists(path)
		// Return the file size
			file_size(path)
		// Check if a file is a directory
			is_directory(path)
		// Check if a file (or directory) is empty
			is_empty(path)
		// Check if a file is a regular file
			is_regular_file(path)
		// Check if a file is a regular file
			current_path()	

//Example : Iterate over files of a directory (recursively/non-recursively)
	namespace fs = std::filesystem;
	for(auto& path : fs::directory_iterator("/usr/tmp/"))
		std::cout << path << '\n';
	
	for(auto& path : fs::recursive_directory_iterator("/usr/tmp/"))
		std::cout << path << '\n';

		//Copy files or directories
			copy(path1, path2)
		// Copy files
			copy_file(src path, src path, [fs::copy options::recursive])
		// Create new directory
			create_directory(path)
		// Remove a file or empty directory
			remove(path)
		// Remove a file or directory and all its contents, recursively
			remove_all(path)
		//Rename a file or directory
			rename(old path, new path)

	namespace fs = std::filesystem;
	fs::path p1 = "/usr/tmp/my_file.txt";
	std::cout << p1.exists(); // true
	std::cout << p1.parent_path(); // "/usr/tmp/"
	std::cout << p1.filename(); // "my_file"
	std::cout << p1.extension(); // "txt"
	std::cout << p1.is_directory(); // false
	std::cout << p1.is_regular_file(); // true
	fs::create_directory("/my_dir/");
	fs::copy(p1.parent_path(), "/my_dir/", fs::copy_options::recursive);
	fs::copy_file(p1, "/my_dir/my_file2.txt");
	fs::remove(p1);
	fs::remove_all(p1.parent_path());


				
	return 0;
}
