#include <bits/stdc++.h>
using namespace std;

void show_mem_rep(char *start, int n)  {
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

int main() {
	unsigned int i = 1;
   char *c = (char*)&i;
   show_mem_rep( (char*)&i, sizeof(i));
   cout<<((*c)?"Little endian" : "Big endian")<<endl;
  cout<<typeid(*c).name()<<endl; //character
  cout<<typeid(*c+48).name()<<endl; //integer
	return 0;
}
