/*
 *Author: James Griffin
 *ID: 811 966 037
 *email: jwg31957@uga.edu
 *
 *Description: An array of singly linked list that are sorted 
 *by alphabetical order and each node holds one name.
 */


#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstdlib>
#include <string>
#include <sstream>
#include <string.h>

#include "list.h"

using namespace std;

void executeCommand(string, string);


node *alpha[26];

int main(const int argc, const char * argv[]) {
   string filename;
   fstream file;
   string line;

   initialize(alpha);

  if(argc == 1) {
    cout << "Input relative path to input file: ";
    std::cin >> filename;
    file.open(filename.c_str());
    freopen("output.txt","w",stdout);              //default output
  }  
  else if(argc == 2) {
    file.open(argv[1]);
    freopen("output.txt","w",stdout);
  }

  while(getline(file, line)) {

    stringstream s_str(line);
    string data;
    string command, item;

    s_str >> command >> item;

    executeCommand(command, item);
   
  }// while



  file.close();
  return 0;
}



/*
 *Takes in a command and possible item to execute. Is called by the main function
 *during runtime. Executes the command.
 */
void executeCommand(string command, string item) {
  transform(command.begin(), command.end(), command.begin(), ::tolower);

  if(command.compare("putitem") == 0) {
    putItem(item, alpha);
  }

  else if(command.compare("getitem") == 0) {
    if(getItem(item, alpha)){
      cout << item << ": Is in the structure" << endl;
    }
  }

  else if(command.compare("getnextitem") == 0) {
    node *next;
    next = getNextItem(item, alpha);
    if(next == 0){
      cout << item + " Does not exist" << endl;
    }
    else 
      cout << next->data << endl;
  }

  else if(command.compare("printlist") == 0) {
    printList(alpha);
  }

  else if(command.compare("deleteitem") == 0) {
    deleteItem(item, alpha);
  }

  else if(command.compare("isfull") == 0) {
    bool status;
    status = isFull();
    if(status) {
      cout << "List is Full" << endl;
    }
    else
      cout << "List has more room" << endl;
  }

  else if(command.compare("makeempty") == 0) {
    makeEmpty(alpha);
  }

  else if(command.compare("getlength") == 0) {
    int length = getLength(alpha, item);
    cout << "The length of [" 
	 << item
	 << "] is: " 
	 << length
	 << endl;
  }

  else if(command.compare("quit") == 0) {
    quit(alpha);
  }
  
  else if(command.compare("resetlist") == 0) {
    cout << "The lists have now been reset" << endl;
  }

}

