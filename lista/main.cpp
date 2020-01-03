#include <iostream>
#include "UList.h"
#include <list>

int main() {
	
	TList<int> mlist;

	std::list<int> lista;

	int arr[11];

	for (int i = 0; i < 11; ++i) {
		mlist.push_back(i + 10);
		lista.push_back(i + 10);
		arr[i] = i + 10;
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

	

	return 0;
}
