//============================================================================
// Name        : Strategy.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;

class ISortAlgo {
public:
	virtual void sort() = 0;
};

class ISearchAlgo {
public:
	virtual void search() = 0;
};

class Merge: public ISortAlgo {
public:
	void sort() {
		cout << "called Merge sort" << endl;
	}
};

class Quick: public ISortAlgo {
public:
	void sort() {
		cout << "called Quick sort" << endl;
	}
};

class Sequential: public ISearchAlgo {
public:
	void search() {
		cout << "called Sequential sort" << endl;
	}
};

class Binary: public ISearchAlgo {
public:
	void search() {
		cout << "called Binary sort" << endl;
	}
};

class Context {
private:
	ISortAlgo *m_sort;
	ISearchAlgo *m_search;
public:
	Context() {
	}
	void set_sort(ISortAlgo* sort) {
		this->m_sort = sort;
	}
	void set_search(ISearchAlgo* search) {
		this->m_search = search;
	}
	void sort() const{
		m_sort->sort();
	}
	void search() const {
		m_search->search();
	}
};

int main() {
	cout << "Strategy example" << endl; // prints Strategy example
	Merge m;
	Quick q;

	Sequential s;
	Binary b;

	Context context;

	context.set_sort(&m);
	context.set_search(&b);
	context.sort();
	context.search();
	return 0;
}
