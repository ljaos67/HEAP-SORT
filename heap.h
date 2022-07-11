/*****************************************************************************************************
CSCI 340 - Assignment 09 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
Date Due: November 8th, 2020

Purpose: This is the headerfile for a program that takes input data from a file, stores that data into
a vector, and sorts the data into heap order. Defined here, is the print class that prints a generic
list that can be used for vectors and queues. In the heap.cc file is where the specific implementation
can be found for transforming the input data into a heap. 

******************************************************************************************************/
#include <assert.h>

// algorithm for make_heap, heap_sort, for_each 
// fstream for file streams, iostream for input/output, string for string class, vector for vector 
// container, iomanip for spacing, and typeinfo for defining a variable type for when strings
// are used
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <typeinfo>

using namespace std;

#ifndef HEAP_H_
#define HEAP_H_

// data files

#define D1 "heap.d1"
#define D2 "heap.d2"
#define D3 "heap.d3"

#define INT_SZ 4   // width of integer
#define FLT_SZ 7   // width of floating-pt number
#define STR_SZ 12  // width of string

#define INT_LN 15  // no of integers in single line
#define FLT_LN 9   // no of floating-pt nums in single line
#define STR_LN 5   // no of strings in single line

// function and class prototypes

// stores items from input file into vector
template <typename T>
void get_list(vector<T>&, const char*);

// construct heap from items in vector
template <typename T, typename P>
void construct_heap(vector<T>&, P);

// class to print heap items

template <typename T>
class print_list {
  unsigned sz,  // heap size
      wid,      // min num of chars written in printout
      len,      // max num of items printed in single line
      cnt;      // counter for printout
 public:
  print_list(const unsigned& = 1, const unsigned& = 1, const unsigned& = 1, const unsigned& = 0);  // constructor
  void operator()(const T&);
};

// constructor that accepts arguments for initialization of print_list<T> object
// allows for changing of print frequency per row, char space for each variable, and if the 
// user wanted to change the count
template <typename T>
print_list<T>::print_list(const unsigned &s, const unsigned &w, const unsigned &l, const unsigned &c)
{
	sz = s;
	wid = w;
	len = l;
	cnt = c;
};

// output is fixed with requirements outlined in assignment
// using the cnt member from the print class, we can manipulate the output
// depending on how how many values have been printed
// i set the parameters for the end of the first line, the end of the subsequent lines,
// and the else accounts for all other cases
// when the count reaches the heap size, it prints newlines and resets the count depending 
// on whether the type is string or not
// this is because strings print an extra new line 
template <typename T>
void print_list<T>::operator()(const T &x)
{
	cout.width(wid);
	cout.precision(2);
	cout << fixed << showpoint;
	if((cnt == (len-1)))
	{
		cout << setw(wid) << x << " " << endl;
		cnt++;
	}
	else if(((cnt + 1) % len) == 0)
	{
		cout << setw(wid) << x << " " << endl;
		cnt++;
	}
	else
	{
		cout << setw(wid) << x << " "; 
		cnt++;
	}
	if(cnt == sz)
	{
		if(typeid(x) == typeid(string))
		{
			cout << "\n";
			cnt = 0;
		}
		else
		{
			cout << "\n\n";
			cnt = 0;
		}
	}
};
#endif  // HEAP_H_
