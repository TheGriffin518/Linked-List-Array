#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>

typedef unsigned int uint;

using std::cout;
using std::endl;

struct node {
  char first_letter;
  std::string data;
  node *next;
  int length;
};

void initialize (node *[]);
node *iterate (node *[], int);
void putItem(std::string, node *[]);
void printList(node *[]);
int lexo_order(std::string, node*[]);
bool getItem(std::string, node*[]);
int getLength(node *[], std::string);
void deleteItem(std::string, node*[]);
void makeEmpty(node *[]);
bool isFull();
void quit(node *[]);
void clearMemory(node *[]);
bool isEmpty(node *[]);
void errorCheck(int);
node *getNextItem(std::string, node*[]);
void insert_sort(node *[], int index, std::string);

int error = 0;
node *alpha[26];
/*Initializes the array of pointers to a node struct. It sets the
 *next pointer within the struc to 0 (NULL) to indicate the end of the 
 *list. 
 */
void initialize(node *alpha[]) {
  char letter = 'a';
  for(uint i = 0; i<26;i++){
    alpha[i] = new node;              // Creates a new node at that specific Index
    alpha[i]->first_letter = letter;  // Sets the first letter to that of a letter. Helps determine alphabetic order
    alpha[i]->next = 0;               // Make the next pointer null
    alpha[i]->data = "";              // Initializes the data
    alpha[i]->length = 0;             // Sets the length to 0
    letter++;                         // Used for setting the first letter 
  }
}


/*Iterates through the array of pointers to a node struct. 
 *Does not return a value, but can set a value to something
 *specific. Will be used in conjunction with other commands. 
 */
node *iterate(node *alpha[], int index) {

  node *iterator;    

    iterator = alpha[index];
    if(iterator != 0) {
      while(iterator->next != 0) {
	iterator = iterator->next;
      }//while
    }//if

   return iterator;
}

/*Places an item within the node struct at the end of the list. 
 *Then moves nullptr to the end of the list.
 *
 */
void putItem(std::string item,node *alpha[]) {
  //node *tmp;
  node *temp;
  int index = lexo_order(item, alpha);   //Returns which list to insert info into
  std::string data;

  if(index == -1) {
    errorCheck(error);
  }
  
  node *prev = alpha[index];
  temp = alpha[index]->next;
  
  if(temp != 0){
    while(temp->next != 0){
      std::string data = temp->data;
      
      if(item.compare(data) < 0) {
	//item goes before data
	node * sort = new node;
	sort->next = temp;
	prev->next = sort;
      }
      
      else if(item.compare(data) > 0) {
	//item goes after data
      }
      
      else if(item.compare(data) == 0) {
	//item goes after. 
	node *sort = new node;
	sort->next = temp->next;
	temp->next = sort;
	sort->data = item;
	sort->first_letter = temp->first_letter;
      }
      prev = temp;
      temp = temp->next;
    }
    
    if(temp->next == 0){
      item = temp->data;
      if(((item.compare(data)) > 0) || ((item.compare(data)) == 0)) {
	node *sort = new node;
	sort->next = temp->next;
	temp->next = sort;
      }
    }
  } //if(temp != 0)
  /*
  node *end = iterate(alpha, index);     //Grabs the last node of the list

  end->next = new node;                  //Has last node point to a new node
  tmp = end->next;                       //Then tmp becomes the node that is being pointed to
  tmp->next = 0;                         //and then points to a nullptr
  tmp->data = info;                      //sets the data equal to the info passed in as a param
  tmp->length = end->length + 1;                      //increases the length of the list 
  tmp->first_letter = end->first_letter; //Used for determining lexographic order. 
  */
}// putItem

/*Goes through and prints each node's data located within
 *each list and array index. 
 *
 */
void printList(node *alpha[]) {
  node *temp;
  char letter = 'a';
  char label = 0;
  for(uint i = 0; i < 26; i++){
    temp = alpha[i];
    label = toupper(letter);
    cout << "["
	 << label
	 << "]"
	 << endl;
    if(temp != 0){
      while(temp->next != 0) {       //checks to see if node points to another node. 
	if(temp->data != ""){
	  cout << "\t"
	       << temp->data 
	       << endl;                //prints the data stored within the node
	}
	temp = temp->next;           //makes the temporary node equal to the next node in the list, if there is one. 
      }//while
      if (temp->next == 0){
	cout << "\t"                 //tab character is for formatting
	     << temp->data
	     << endl;                //prints out the data for the last node in the list has a nullptr
      }
    }//if
    letter++;
  }//for
}// printList

/*
 *Determines which index of the array that the item belongs to. 
 *It returns an int that is the index of the array that it fits into. 
 */
int lexo_order(std::string data, node *alpha[]) {
  char first;
  int index = -1;

  first = tolower(data.at(0));
  if(!((first >= 97) || (first <= 122))){
    error = -2;
    return index;
  }
  for(int i=0;i<26;i++){
    if(first == alpha[i]->first_letter)
      index = i;
  }//for
  return index;
}

/*
 *Returns a pointer to a node that is the item that is requestd. 
 *If the item is not found, then it returns a nullptr. That return value 
 *will be handled by the caller. 
 */
bool getItem(std::string item, node *alpha[]) {
  int index;
  bool found = false;
  //  std::transform(item.begin(), item.end(), item.begin(), ::tolower);
  index = lexo_order(item, alpha);
  if(index == -1) {
    errorCheck(error);
    return found;
  }

  node *iter = alpha[index]->next;
  
  if(iter->next != 0) {
    while(iter->next !=0) {
      if(item.compare(iter->data) == 0) {
	found = true;
      }//if
      else 
	iter = iter->next;
    }//while
  }//if

  else if(iter->next == 0) {
    if(item.compare(iter->data) == 0)
      found = true;
  }//else if

  else
    found = false;

  return found;
}// getItem

/*
 *Gets the length value that is stored within each node and returns that value. 
 */
int getLength(node *alpha[], std::string letter) {

  int length = 0;
  int index = lexo_order(letter, alpha);
  node *tmp = alpha[index]->next;
  while(tmp->next != 0){
    length++;
  }
  if(length > 0)
    length++;

  return length;

} //get Length

/*Finds the item located within the array of linked lists 
 *and deletes it from the list and memory. 
 *
 */
void deleteItem(std::string item, node *alpha[]) {

  node *iterator; //points to the next node in the list
  node *current;  //points to the current node. Want to stay ahead by one node. 
  
  int index  = lexo_order(item, alpha);    //gets which index of the array needed to be modified. 
  if(index == -1) {
    errorCheck(error);
  }
  iterator = alpha[index];                 //starts to iterate at this start point 
  current = iterator;
  while(iterator->next != 0) {
    if(item.compare(iterator->data) == 0) {      //compares the data stored in the node to the data that is trying to 
      current->next = iterator->next;            //be deleted. If they are equal to each other, then the node will be deleted
      delete iterator;                           //The current node then has it's next pointed equal to that of the next pointer
    }                                            //of the node about to be deleted. 
    current = iterator;
    iterator = iterator->next;
  } // while
  if(iterator->next == 0) {
    current->next = iterator->next;
    delete iterator;
  }
  
} // deleteItem


/*
 *Calls the system exit function with an exit status of 0.
 */
void quit(node *alpha[]) {

  clearMemory(alpha);
  exit(0);
}

/*Goes through and deletes every node within each linked list. 
 *It iterates through each index of the array of alpha and traverses
 *down the list. 
 */
void makeEmpty(node *alpha[]) {
  node *current;
  node *next;
  if(!isEmpty(alpha)) {
    for(int i = 0; i < 26; i++){
      current = alpha[i];
      next = current;
      if(current->next != 0){
	while(current->next != 0) {
	  next = current->next;
	  delete current;
	  current = next;
	}//while
	if(current->next == 0) {
	  current = current->next;
	  delete current;
	}//if
      }//if current->next != 0
      alpha[i]->next = 0;        //resets the next pointer at the head node to have a nullptr
    }//for
  } //if
} // makeEmpty

/*Checks to see if there is enough memory to add a new node. Does so by
 *newing a new node and if it has a nullptr value, then there is not enough memory
 *else, there is enough memory and it return false. 
 */
bool isFull() {
  node *ptr = new node;
  if(ptr == 0)      //checks to see if the node pointer, ptr, points to an address 
    return true;          //in memory. If it doesn't, then there is not enough memory. 
  else 
    {
      delete ptr;
      return false;
    } //else

}
/*
 *Goes through and deallocates the memory when program is done running. 
 */
void clearMemory(node *alpha[]) {

  makeEmpty(alpha);
  for(int i = 0; i < 26; i++){
    delete alpha[i];
  }//for

} //clearMemory

/*
 *Checks to see if the array is empty or not. Returns a bool value based on that status. 
 */
bool isEmpty(node *alpha[]) {
  bool contents = true;

  for(int i=26;i<26;i++){
    if(alpha[i]->next != 0)
      contents = false;
  }
  return contents;
}

/*
 *Own error handling function. GLobal variable error is set whenever error arises
 *and then errorCheck handles each error and displays a message. 
 */
void errorCheck(int err) {

  switch (err) {
  case -1:
    //    cout << "The array is already empty" << endl;
    break;
  case -2:
    cout << "That is illegal input. Input must begin with \"a-z\"" << endl;
    break;
  case -3:
    cout << "The item already exists within the array. It was not entered in." << endl;
    break;
  case -4:
    cout << "The item does not exist." << endl;
    break;

  }//switch
}

/*
 *Returns a node pointer to the next item within the array. 
 */
node *getNextItem(std::string data, node *alpha[]) {

  int index = lexo_order(data, alpha);
  if(index == -1) {
    errorCheck(error);
  }

  node *next = alpha[index]->next;
  return next;

} //getNextItem

void insert_sort(node *alpha[], int index, std::string item) {


}

#endif
