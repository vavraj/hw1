#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
	//Check if the list is empty
	if (empty()) {
		//Create a new item, and add it
		Item* tmpItem = new Item();
		head_ = tmpItem; //Set head and tail as same pointers
		tail_ = tmpItem;
		tmpItem->val[0] = val; //Setup the element to the front
		tmpItem->last++; //Increment last position to maintain the count consistency
	}
	else if (tail_->last == ARRSIZE) { 
		//Check if tail is full
		Item* tmpItem2 = new Item();
		tail_->next = tmpItem2; //Assign to the next element
		tmpItem2->prev = tail_; //Make previous element as tail
		tail_ = tmpItem2; //Copy this to the tmp item
		tmpItem2->val[0] = val; //Store in the initial position
		tmpItem2->last++; //Increment last position to maintain the count consistency
	}
	else { 
		//Else add the details normally
		tail_->val[tail_->last] = val; //Add to the back
		tail_->last++; //Increment last position to maintain the count consistency
	}
	size_++; //Increment internal size
}

void ULListStr::pop_back() {
	//list is empty
	if (size_ == 0) 
		return;
	if (size_ == 1) {
		//Empty list with single element
		delete tail_; 
		tail_ = NULL;
		head_ = NULL;
	}
	else if (tail_->last == 1) {
		//Empty tail
		tail_ = tail_->prev;
		delete tail_->next;
		tail_->next = NULL;
	}
	else { 
		//Reduce the index for scanning the elements
		tail_->last--;
	}
	//Reduce size
	size_--;
}
  
void ULListStr::push_front(const std::string& val) {
	if (empty()) { 
		//List is currently empty, so add item to the initial position
		Item* newItem = new Item();
		head_ = newItem;
		tail_ = newItem;
		newItem->val[0] = val;
		newItem->last++;
	}
	else if (head_->first == 0) { 
		//Create a new element
		Item* newItem2 = new Item();
		newItem2->next = head_; //Add to the next list
		head_->prev = newItem2; //Save previous item as well
		head_ = newItem2; //Make this as the new item
		newItem2->val[ARRSIZE-1] = val; //Store in the new array
		newItem2->last = ARRSIZE; //Setup bounds for new array
		newItem2->first = ARRSIZE-1;
	}
	else { 
		//Add it normally to the front by pushing the header
		head_->val[head_->first-1] = val;
		head_->first--;
	}
	size_++;
}

void ULListStr::pop_front() {
	if (size_ == 0) 
		return;
	if (size_ == 1) {
		//Only one element, repeat same as pop_back()
		Item* temp = head_;
		delete temp; 
		tail_ = NULL;
		head_ = NULL;
	}
	else if (head_->first == ARRSIZE-1) { 
		//One element at head, repeat like pop_back()
		head_ = head_->next;
		delete head_->prev;
		head_->prev = NULL;
	}
	else {
		//Pop normally by moving the head index
		head_->first++;
	}
	size_--;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	//Check for bounds
	if (loc < 0 || loc >= size_) 
		return NULL;
	
	//Else, find the location
	size_t tmpLocation1 = 0; 
	//Start from initial element
	size_t foundLocation = head_->first;
	//Check the header
	Item* tempElement = head_;
	//Loop till the element is not found
	while (tmpLocation1 != loc) {
		//Increment the locations
		tmpLocation1++;
		foundLocation++;
		//Check if the last element has reached (bounds check)
		if (foundLocation == tempElement->last) {
			//If yes, then reset the found location
			tempElement = tempElement->next;
			foundLocation = 0;
		}
	}
	//Check the location in the element and return to user
	return &tempElement->val[foundLocation];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
