//
//  command line 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <sstream>

inline void usage(std::string msg)
{
    std::cout << std::endl << std::endl << msg << std::endl;
    std::cout << "Usage is \n\t:> CLA -i infile -o outfile" << std::endl;
}

int main(int argc, char* argv[])
{
    std::string inputFlag = "-i";
    std::string outputFlag = "-o";
    std::ostringstream ostr;
    std::string inFile, outFile;

    if(argc != 5)
    {
        ostr << "Needed 4 agurments, Recived <" << argc-1 << ">";
        usage(ostr.str());
        return -1;
    }
    std::cout << "\nRecieved parameters: " << argv[0];

    for(int index = 1; index < argc; index+=2)
    {
        if(argv[index] == inputFlag)
        {
            inFile = argv[index+1];
        }
        else if(argv[index] == outputFlag)
        {
            outFile = argv[index+1];
        }
        else
        {
            std::cout << ">";
            ostr << "Invalid input: " << argv[index] << ">" << std::endl;
            usage(ostr.str());
            return -1;
        }
    }

    std::cout  << ">\n" << std::endl;
    std::cout  <<  "Got input file" << inFile << "output file " <<outFile << std::endl;

    return 0;
}
