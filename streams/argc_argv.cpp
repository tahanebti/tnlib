//
//  argc_argv
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


/*
* argc and argv are the "command line arguments":
* int argc is the number of space-separated arguments, including the program name
* char *argv[] is a pointer to an array of character strings that contain the *arguments.
*
* char *argv[] : You may also see it this way, which is exactly the same: char **argv
* argv is a pointer to an array of character strings, which are each pointers to
* null-terminated character arrays. argv[i] refers to the ith array.
*/

//int int main(int argc, char const *argv[])

//int main()

//Modern C++
auto main() -> int
{
	//the following line at the beginning of the code
	// make input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


    for (int i=0; i < argc; i++) {
        cout<<"Argument : "<<i<<endl;
        cout<<argv[i]<<endl;
    }
    
	return 0;
}
