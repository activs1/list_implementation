#include <iostream>
#include "TList.h"
#include <list>

const int ARR_SIZE = 11;

int main() {
	
	TList<int> mlist;

	std::list<int> lista;

	int arr[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; ++i) {
		mlist.push_back(i + ARR_SIZE - 1);
		lista.push_back(i + ARR_SIZE - 1);
		arr[i] = i + ARR_SIZE - 1;
	}
	//mlist.push_back(10);

	std::list<int>::iterator it;

	for (it = lista.begin(); it != lista.end(); it++) {
		std::cout << "| " << *it << " |\n";
	}

	mlist.print();

	std::cout << "\n\nPierwszy element (glowa): " << mlist.getFirst();
	std::cout << "\n\nOstatni element (ogon): " << mlist.getLast();


	//comparing sizes: list implemented vs list stl vs array
	std::cout << "\n\n" << sizeof(mlist) << " |||| " << sizeof(lista) << " |||| "<< sizeof(arr);

	//checking if TList.empty() is working:
	TList<int> new_list;
	std::cout << "\n\n" << new_list.size();
	std::cout << "\n\nNowa lista jest: " << new_list.empty() << ". Stara lista jest: " << mlist.empty() << std::endl; //1 for empty, 0 for contains something

																													  
	

	TList<int>::Iterator iter;
	iter = mlist.begin();

	std::cout << "\n\n" << "Iterator: " << *(++iter) << std::endl;




	mlist.push_front(1453);

	TList<int>::Iterator begin, end;
	begin = mlist.begin();
	end = mlist.end();
	std::cout << "\nPorownanie iteratorow na poczatek i koniec:";
	std::cout << "\n-> operator ==: " << (begin == end);
	std::cout << "\n-> operator !=: " << (begin != end);
	///std::cout << "\n-> operator <=: " << (begin <= end);
	//std::cout << "\n-> operator >=: " << (begin >= end);
	std::cout << "\n-> operator <: " << (begin < end);
	//std::cout << "\n-> operator >: " << (begin > end);

	std::cout << std::endl;

	TList<int>::Iterator iterator = mlist.begin();
	for (iterator; iterator != mlist.end(); ++iterator) {
		std::cout << "| " << *iterator << " |";
	}

	std::cout << std::endl;


	std::list<int>::iterator iterl;
	for (iterl = lista.begin(); iterl != lista.end(); ++iterl) {
		std::cout << "| " << *iterl << " |";
	}





	return 0;
}
