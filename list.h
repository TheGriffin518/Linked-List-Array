/*
 *Author: James Griffin
 *ID: 811 966 037
 *email: jwg31957@uga.edu
 *
 *Description: An array of singly linked list that are sorted 
 *by alphabetical order and each node holds one name.
 */



#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>


using std::cout;
using std::endl;


  struct node {
    char first_letter;
    std::string data;
    node *next;
    int length;
  };

class list {
 public:



  node *alpha[26];

  list(node *[]);
  
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
};

#endif
