#include <iostream>
#include "split.h"
using namespace std;


int main(int argc, char* argv[])
{
	//initialize nodes
	Node* node5 = new Node(5, nullptr);
	Node* node4 = new Node(4, node5);
	Node* node3 = new Node(3, node4);
	Node* node2 = new Node(2, node3);
	Node* head1 = new Node(1, node2);

  Node* odds = NULL;
  Node* evens = NULL;

	//call split
	split(head1, odds, evens);
  
	//print list
  print(evens);
	print(odds); 
  print(head1); //prints null since empty

	//delete memory
	delete head1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete odds;
	delete evens;

  return 0;
}
