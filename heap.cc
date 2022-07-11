/*****************************************************************************************************
CSCI 340 - Assignment 09 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
Date Due: November 8th, 2020

Purpose: This is the driver file for a program that takes input data from a file, stores that data into
a vector, and sorts the data into heap order. Defined here, is 3 different data types for each of the
different data types of the data files. This program defines 'get_list' and 'construct_heap' which
store data into a vector from an input file and use stl algorithms to 'heapify' data. The rest of the
code showcases the functionality of heaps by usage of differrent data types/

******************************************************************************************************/
#include "heap.h"

// opens a file defined in path
// stores input into vector
// closes file
template <typename T>
void get_list(vector<T> &v, const char *path) 
{
	v.clear();
	ifstream file;
	file.open(path);
	T a;
	while(file >> a)
	{
		v.push_back(a);
	}
	file.close();
};

// builds heaps with vector data with stl function make_heap
// sorts heap data with stl function sort_heap
template <typename T, typename P>
void construct_heap(vector<T> &v, P pred) 
{
	make_heap(v.begin(),v.end(),pred);
	sort_heap(v.begin(),v.end(),pred);
};

int main() {
  vector<int>    v1;  // heap of integers
  vector<float>  v2;  // heap of floating-pt nums
  vector<string> v3;  // heap of strings

  // print header message
  cout << "\t\t\t*** Heaps and Heapsort - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list<int> print1(v1.size(), INT_SZ, INT_LN);
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list<string> print3(v3.size(), STR_SZ, STR_LN);
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "\t\t\t*** end of program execution ***\n\n";
  return 0;
}
