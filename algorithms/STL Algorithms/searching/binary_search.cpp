

#include <algorithm> // lower_bound, sort, distance
#include <cassert>
#include <iostream>
#include <random>    // minstd_rand0
#include <vector>

//#define DEBUG

using namespace std;

typedef unsigned int int32u;
typedef vector < int32u > Vector;

const int32u VECTOR_SIZE = 10000000;     
const int32u ITERATION_COUNT = 10000000; 

Vector v;   
int32u key; 

minstd_rand0 rnd ( 1999993 );


void generateRandomSortedVector ( int n ) {     
  // Ãåíåðèðóåì
  v . resize ( n );
  for ( int32u & i : v )
    i = rnd ( );
  // Ñîðòèðóåì
  sort ( v . begin ( ), v . end ( ) );
}


int32u bs0Rec ( int32u left, int32u right ) {
  if ( left == right )
    return left;
  int32u center = left + ( right - left ) / 2;
  if ( v [ center ] < key )
    return bs0Rec ( center + 1, right );
  else
    return bs0Rec ( left, center );
}

int32u bs0 ( ) {
  return bs0Rec ( 0, v . size ( ) );
}


int32u bs1 ( ) {
  int32u left = 0, right = v . size ( );
  while ( left < right ) {
    int32u center = left + ( right - left ) / 2;
    if ( v [ center ] < key )
      left = center + 1;
    else
      right = center;
  }
  return left;
}


int32u bs2 ( ) {
  int32u left = 0, count = v . size ( ); 
  while ( count > 0 ) {
    int step = count / 2;   
    if ( v [ left + step ] < key ) { 
      left += step + 1;
      count -= step + 1;
    }
    else
      count = step;
  }
  return left;
}

/**
  http://eigenjoy.com/2011/01/21/worlds-fastest-binary-search/
**/
int32u bs3 ( ) {
  auto n = v . size ( );
  switch ( n ) {
    case 0 : return 0;
    case 1 : return v [ 0 ] < key ? 1 : 0;
  } 
  int32u i = 0;  
  int32u b = 1u << int32u ( log ( double ( n - 1 ) ) / log ( 2.0 ) );
  for ( ; b > 0 ; b >>= 1 ) {
    int32u j = i | b;
    if ( j < n && v [ j ] < key )
      i = j;
  }
  if ( i == 0 && ! ( v [ 0 ] < key ) )
    return 0;
  else
    return i + 1;
}


int32u bs4 ( ) {
  int32u left = 0, right = v . size ( );
  while ( right - left > 4 ) {
    int32u center = left + ( right - left ) / 2;
    if ( v [ center ] < key )
      left = center + 1;
    else
      right = center;
  }
  for ( ; left < right; left ++ )
    if ( ! ( v [ left ] < key ) )
      break;
  return left;
}


int32u bsStl ( ) {
  return distance ( 
    v . begin ( ), 
    lower_bound ( v . begin ( ), v . end ( ), key ) 
  );
}


void test ( int32u ( * f ) ( ) ) {


  generateRandomSortedVector ( 0 );
  key = rnd ( ); 
  assert ( f ( ) == bsStl ( ) );

  const int SIZE [ 4 ] = { 1, 2, 3, 1000 };
		
  for ( int k = 0; k < 4; k ++ ) {
    generateRandomSortedVector ( SIZE [ k ] );
    key = v [ 0 ] - 1; // Èñêîìàÿ ãðàíèöà ñëåâà		
    assert ( f ( ) == bsStl ( ) );
    // Ïðîâåðÿåì âñå âîçìîæíûå ïðîìåæóòî÷íûå ïîçèöèè
    for ( int i = 0; i < SIZE [ k ]; i ++ ) {			
      key = v [ i ];
      assert ( f ( ) == bsStl ( ) );
      key = v [ i ] + 1;
      assert ( f ( ) == bsStl ( ) );
    }
    key = v . back ( ) + 1; // Èñêîìàÿ ãðàíèöà ñïðàâà
    assert ( f ( ) == bsStl ( ) );
  }
}

int main ( ) {

  int32u index = 0;

#ifdef DEBUG
  test ( bs0 );
  test ( bs1 );
  test ( bs2 );
  test ( bs3 );
  test ( bs4 );
#endif

  
  generateRandomSortedVector ( VECTOR_SIZE );

  for ( int32u test = 0; test < ITERATION_COUNT; test ++ ) {
    key = v [ rnd ( ) % VECTOR_SIZE ] + ( rnd ( ) % 3 ) - 1;
    index += key;
    //index += bsStl ( );
    //index += bs0 ( );
    //index += bs1 ( );
    //index += bs2 ( );
    //index += bs3 ( );	
    //index += bs4 ( );
  }

  {    
    cout << index << endl;
  }
    
  return 0;
}
