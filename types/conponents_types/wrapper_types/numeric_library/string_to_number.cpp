//
//  string_to_number
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

//C Style

/*  Function to get numeral for a value. */
char getNumeral(int val) {
    if(val >= 0 && val <= 9) return (val + '0');
    if(val >= 10 && val <= BASE) return (val + 'A' - 10);

}

/*  Function to get value of a numeral. */
int getNumeralValue(char num) {
    if(num >= '0' && num <= '9') return (num - '0');
    if(num >= 'A' && num <= 'D') return (num - 'A' + 10);
}

// Translation of the character "numbers" in its value.
int get_digit_value ( char d ) { 
    if ( '0' <= d && d <= '9' ) {    
        return d - '0' ; 
    } else {  
        return d - 'A' + 10 ;   
    }
}

int get_number_value ( string num ) { 
    int result = 0 ; 
 
    int len = num.length ();
    // Handle the "numbers" from right to left
    // each describes the coefficient before the next base degree (12).
    for ( int i = len - 1 ; i >= 0 ; --i) {    
        // recommend using your own pow implementation
        result += get_digit_value ( num [ i ]) * pow ( 12 , len - 1 - i );   
    }

    return result ;
}

//C++
int t_toInt(string str){
  int number =0;
  for (int i = 0; i < str.size(); i++)
    number = number * 10 + (str[i] - '0');
  return number;
}

int t_toInt2(string str){
  int number;
  stringstream ss;
  ss << str;
  ss >> number;
  return number;
}

//c++11
int t_toInt3(string str){
  return std::stoi(str);
}

//I assume the value in the string is all values 0-9
int t_toInt4( const string& str)
{
    int number = 0;
    std::for_each(str.begin(), str.end(), [&number] (const char& ch){
     number = (number * 10) + (int)(ch-'0'); 
    });
    return number;
}