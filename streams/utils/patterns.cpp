//
//  pattern
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
void print(int number){
    cout << setw(2) << setfill('0')
         << number << "  ";
}

int print_sequence_forward(int end){
	for (int i = 0; i <= end; ++i){
		cout<<i<<" ";
	}
	cout<<'\n';
}

int print_sequence_backward(int end){
	while(end >= 0){
		cout<<end<<" ";
		--end;
	}
	cout<<'\n';
}
//1 -1 1 -1 1 -1 1 -1 1 -1 1
int print_sequence_pow(int end){
	for (int i = 0; i <= end; ++i){
		cout<<pow(-1,i)<<" ";
	}
	cout<<'\n';
}

//0 -1 2 -3 4 -5 6 -7 8 -9 10
int print_sequence_pow2(int end){
	for (int i = 0; i <= end; ++i){
		cout<<pow(-1,i)*i<<" ";
	}
	cout<<'\n';
}

//-0 1 -2 3 -4 5 -6 7 -8 9 -10
int print_sequence_pow3(int end){
	for (int i = 0; i <= end; ++i){
		cout<<pow(-1,i+1)*i<<" ";
	}
	cout<<'\n';
}

// X 0 1 2  X 3 4 5  X 6 7 8  X 9 10
int print_sequence_cyle_rotation(int end){
	for (int i = 0; i <= end; ++i){
		if(i % 3 == 0) cout<<" X ";
        cout<<i<<" ";
	}
	cout<<'\n';
}

//(0) 1 (2) 3 (4) 5 (6) 7 (8) 9
int print_sequence_cyle_rotation2(int n){
	bool open = false;
    for(int i = 0; i<n; ++i){
        if(i % 2 == 0 && !open){
            cout<<"("; open = true;
        }
        cout<<i;
        if(open){
          cout<<")"; open = false;
        }
        cout<<" ";
    }
	cout<<'\n';
}

// 0(n * n) = O(n^2)
void print_matrix_forward(int n){
	for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            cout<<" * ";
        }
    cout<<'\n';
	}
}

/**
 *  *  *  *  *  *  *
 *  *  *  *  *  *
 *  *  *  *  *
 *  *  *  *
 *  *  *
 *  *
 *
**/
// 0(n * n/2) = O(n^2)
void print_matrix_forward2(int n){
	for (int i = 0; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            cout<<" * ";
        }
    cout<<'\n';
	}
}
/**

*
**
***
****
*****
******
*******

**/
// 0(n * n/2) = O(n^2)
void print_matrix_forward3(int n){
	for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= i; ++j){
            cout<<" * ";
        }
    cout<<'\n';
	}
}
/**
     *
    **
   ***
  ****
 *****

*/
// 0(n * n/2) = O(n^2)
void print_matrix_forward4(int n){
	for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            cout<<" ";
        }
        for (int k = 0; k < i; ++k){
            cout<<"*";
        }
    cout<<'\n';
	}
}
/**

******
 *****
  ****
   ***
    **
     *

**/

// 0(n * n/2) = O(n^2)
void print_matrix_forward5(int n){
	for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            cout<<" ";
        }
        for (int k = i; k < n; ++k){
            cout<<"*";
        }
    cout<<'\n';
	}
}
/**

*******
**   **
* * * *
*  *  *
* * * *
**   **
*******

**/
void print_matrix_forward6(int n){
	for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            //   --        --         |        |          \        /
            if(i == 0 || i == n || j == 0 || j == n || j == i || i + j == n)
                cout<<"*";
            else
                cout<<" ";
        }
	cout<<'\n';
}
}
/**

*******
     *
    *
   *
  *
 *
*******

**/
void print_matrix_forward8(int n){
	for (int i = 0; i <= n; ++i){
        for (int j = 0; j <= n; ++j){
            //   --        --       /
            if(i == 0 || i == n ||i + j == n)
                cout<<"*";
            else
                cout<<" ";
        }
	cout<<'\n';
	}

}


auto main() -> int
{
	//the following line at the beginning of the code
	// make input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    
	return 0;
}
