//
//  number_to_string
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

// Translate the value of the "digit" into its symbol.
int get_digit_char ( int d ) { 
    if ( d < 10 ) {   
        return '0' + d ;  
    } else {  
        return 'A' + ( d - 10 );    
    }
}
 
string convert_to_32 ( int num ) { 
    string result = "" ; 
 
    while ( num ) {  
        int last_digit = num % 32 ; 
        result += get_digit_char ( last_digit ); // When adding numbers to the beginning   
                                                // would have to shift everybody else every time.
                                                // To avoid this, we add numbers to the end,
                                                // and at the end just expand the line.
        num /= 32 ; 
    }
    reverse ( result . begin (), result . end ());
    return result ;
}

string t_toString(int number){
    string str = "";
    while(number> 0){
        int rem = number % 10;
        char c = rem + '0';
        number /= 10;
        str += c; //append new character at the front of the string!
    }
    return str;
}

string t_toString2(int number){
    string s=" ";
    stringstream out;
    out << number;
 return out.str();
}
