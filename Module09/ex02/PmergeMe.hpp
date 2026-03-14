#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <math.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( const PmergeMe &other ) = delete;
		PmergeMe &operator=( const PmergeMe &other ) = delete;
		~PmergeMe();

		bool run( const std::vector<std::string> &args );
		bool checkInput( const std::vector<std::string> &args );
		int compare( int a, int b );
		template <typename T>
		void printDebug( const T &main, const T &pend );
		template <typename T>
		bool checkDuplicate( const T &container );
		template <typename T>
		void PrintResult( const T &container );
		template <typename T>
		void printBefore( const T &container );
		template <typename T>
		void mergeInsertSort(T& container);
		template <typename T>
		void printAfter( const T &container );
		template <typename T>
		void sort( T& container );
		template <typename T>
		void insert( T& main, T &pend );
		int Jacobsthal( int i );

		private:
		int num_comp;
		std::vector<int> input_vector;
		std::deque<int> input_deque;
		std::chrono::microseconds elapsed_vector;
		std::chrono::microseconds elapsed_deque;
};