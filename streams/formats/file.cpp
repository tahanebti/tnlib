#include <bits/stdc++.h>
using namespace std;

void find(ifstream & stream, string token) {
    string line;
    while (getline(stream, line)) {
        if (line.find(token) != string::npos) {
            cout << line << endl;
        }
    }
    cout << token << " not found" << endl;
}

int main() {
	string line;

ifstream in("input.txt");
    if (in.fail()){
        cout << "File opening error. " << endl;
    }  else{
        while(getline(in,line)) {
            cout << line << endl;
        }
    }


    ofstream out("output.txt");
    for(int count = 0; count< 5; count++){
        out <<  "Hello, World" << endl;
    }
    out.close();

    
	return 0;
}



      //Constructor
      ifstream ifs("dictionary.txt");
      //Using rdbuf() - quicker
      
      if (ifs && ofs) {
        ofs << ifs.rdbuf();
      }
      //File open error

      // ios::trunc means that the output file will be
      // overwritten if exists
      
      ofstream ofs("dict.copy", ios::trunc);
      char c;
      while( ifs.get( c ) ){
        ofs.put( c );
      }
      
    }
    
    //Destructor call will close the stream
    {
      ifstream ifs;
      ifs.open("in.txt");
      //...
      ifs.close();
      //...
    }
  }