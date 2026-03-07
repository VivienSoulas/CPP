#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <chrono>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe( const PmergeMe &other ) = delete;
		PmergeMe &operator=( const PmergeMe &other ) = delete;
		~PmergeMe();

		bool run( const std::vector<std::string> &args );
		bool checkInput( const std::vector<std::string> &args );
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

		private:
		std::vector<int> input_vector;
		std::deque<int> input_deque;
		std::chrono::microseconds elapsed_vector;
		std::chrono::microseconds elapsed_deque;
		int a; // biggest
		int b; // smallest
		std::vector<int> S_vector; // main
		std::vector<int> pend_vector;
		std::deque<int> S_deque; //main
		std::deque<int> pend_deque;
};