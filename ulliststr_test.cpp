/* Write your test code for the ULListStr in this file */
#include <iostream>
#include "ulliststr.h"

using namespace std;

void printList(ULListStr*);

int main(int argc, char* argv[])
{
	//ULListStr* ulist = new ULListStr();

	//Example Test Case 
	/*cout << "Example Test Case" << endl;
	cout << " Push_back 7, push_front 8, push_back 9" << endl;
	ulist->push_back("7");
	ulist->push_front("8");
	ulist->push_back("9");
	printList(ulist);
	cout << "------------------------------------------" << endl;
	cout << ulist->get(0) << "  " << ulist->get(1) << "  " << ulist->get(2) << "  " << endl;
	cout << ulist->size() << endl;
	cout <<"------------------------------------------"<< endl;
	cout << " pop_front and pop_back" << endl;
	ulist->pop_front();
	ulist->pop_back();
	printList(ulist);
	cout << "------------------------------------------" << endl;
	cout << " Push_back 10, push_front 8, push_back 11" << endl;
	ulist->push_back("10");
	ulist->push_front("8");
	ulist->push_back("11");
	printList(ulist);
	cout << "------------------------------------------" << endl;

	//Test Case 1  
	cout << "Test case 1\nPushing elements to front" << endl;
	ulist->push_front("1");
	ulist->push_front("2");
	ulist->push_front("3");
	ulist->push_front("4");
	ulist->push_front("6");
	ulist->push_front("7");
	ulist->push_front("8");
	ulist->push_front("9");
	ulist->push_front("10");
	ulist->push_front("11");
	ulist->push_front("12");
	ulist->push_front("13");
	ulist->push_front("14");
	ulist->push_front("15");
	ulist->push_front("16");
	printList(ulist);
	
	
	//Test Case 2
	cout << "Test case 2\nPushing elements to back" << endl;
	ulist->push_back("17");
	ulist->push_back("18");
	ulist->push_back("19");
	ulist->push_back("20");
	ulist->push_back("21");
	printList(ulist);
	
	
	//Test Case 3
	cout << "Test case 3\nPopping 2 elements from front" << endl;
	ulist->pop_front();
	ulist->pop_front();
	printList(ulist);
	
	
	//Test Case 4
	cout << "Test case 4\nPopping 3 elements from back" << endl;
	ulist->pop_back();
	ulist->pop_back();
	ulist->pop_back();
	printList(ulist);
	
	
	//Test Case 6
	cout << "Test case 6\nSetting some values" << endl;
	ulist->set(5, "55");
	ulist->set(8, "88");
	printList(ulist);
	
	//Test Case 7
	cout << "Test case 7\nChecking if the list has elements" << endl;
	if(ulist->empty()) {
		cout << "TC7 List is empty" << endl;
	} else {
		cout << "TC7 List is NOT empty" << endl;
	}
	
	//Test Case 8
	cout << "Test case 8\nChecking for exceptions" << endl;
//	ulist->get(20);
*/
	//Test Case 9
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	// prints: 8 7 9
	cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
}

void printList(ULListStr* ulist) {
	int size = ulist->size();
	int count;
	
	cout << "Total size " << size << endl;
	for(count=0;count<size;count++) {
		cout << "Element at " << count << " is " << ulist->get(count) << endl;
	}
}