#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class SortingStrategy {
public:
	virtual void sort (std::vector<int>& vec) = 0;
	virtual ~SortingStrategy () = default;
};

class Bubble: public SortingStrategy {
public:
	void sort (std::vector<int>& vec)  override {
		bool swapped = false;
		for (int i = 0; i < vec.size() - 1; ++i) {
			for (int j = 0; j < vec.size() - 1 - i; ++j) {
				if (vec[j] > vec[j + 1]) {
					std::swap (vec[j], vec[j + 1]);
					swapped = true;
				}
			}
			if (!swapped) {
				break;
			}
		}
	}
};

class Selection: public SortingStrategy {
public:
	void sort (std::vector<int>& vec)  override {
		int min_index = 1;
		for (int i = 0; i < vec.size() - 1; ++i) {
			min_index = i;
			for (int j = i + 1; j < vec.size(); ++j) {
				if (vec[j] < vec[min_index]) 
					min_index = j;
			}
			if (i != min_index) 
				std::swap (vec[i], vec[min_index]);
		}
	}
};

class FileHandler {
public:
	std::vector<int> readArrayFromFile (const std::string& name) {
		std::ifstream infile (name);
		std::vector<int> vec;
		if (!infile.is_open()) {
			std::cout << "Unknown file" << std::endl;
			return vec;
		}
		int val;
		while (infile >> val) {
			vec.push_back (val);
		}
		infile.close();
		return vec;
	}
	
	void saveToFile (const std::vector<int>& vec, const std::string& name) {
		std::ofstream outfile (name);
		if (!outfile.is_open()) {
			std::cout << "Unknown file";
			return;
		}
		for (int val : vec) {
			outfile << val << " ";
		}
		outfile.close();
	}
};

class SortingApplication {
private:
	SortingStrategy* psort;
	FileHandler ob;

public:
	SortingApplication () : psort(nullptr) {}
	~SortingApplication () {
		delete psort;
	}
	
	void selectSortingStrategy () {
		if (psort) {
			delete psort;
			psort = nullptr;
		}
		std::cout << "enter 1 for bubble sort and 2 for selection sort. any other option will be considered as a bubble sort choice by default" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice) {
			case 1:
				psort = new Bubble ();
				break;
			case 2:
				psort = new Selection ();
				break;
			default:
				std::cout << "default bubble sort" << std::endl;
				psort = new Bubble ();
				break;
		}
	}

	void managingProcess () {
		if (!psort) {
			std::cout << "Choose the strategy for sorting beforhand please";
			return;
		}
		std::string infile, outfile;
		std::cout << "Enter your input file name: " << std::endl;
		std::cin >> infile;
		std::cout << "Enter your putput file name: " << std::endl;
		std::cin >> outfile;

		std::vector<int> vec = ob.readArrayFromFile(infile);
		psort -> sort (vec);
		ob.saveToFile(vec, outfile);

		std::cout << "Completed: " << outfile << std::endl;
	}

	void UserInput () {
		selectSortingStrategy ();
		managingProcess ();
	}
};

int main()
{
	SortingApplication ob;
	ob.UserInput ();
}
