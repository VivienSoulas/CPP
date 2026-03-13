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
		bool checkDuplicate( const T &container);
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
		int Jacobsthal( int i );

		private:
		int num_comp;
		bool is_odd;
		std::vector<int> input_vector;
		std::deque<int> input_deque;
		std::chrono::microseconds elapsed_vector;
		std::chrono::microseconds elapsed_deque;
		std::vector<int> main_vector;
		std::vector<int> pend_vector;
		std::deque<int> main_deque;
		std::deque<int> pend_deque;
};