Name: James Griffin


## Description ##
This program is an array of singly linked list. The array holds values from 
A-Z. Each node in the linked list holds one data field, a name. The list are
ordered in alphabetical order. The array only holds values from the alphabet.
Numerical values are not allowed. This data structure supports most of the 
ADT functions. This program reads in input from a txt file that is specified
at runtime. It then outputs the status of the program to an output.txt file. 

## List of Suported Commands ##

isFull: Determines if the memory is full and if another node can be inserted
MakeEmpty: Empties the contents of the list. 
PutItem [item]: Places an item into a new node that is sorted.
DeleteItem [item]: Removes the item from the list. 
GetItem [item]:Returns the item if it exists. 
GetNextItem [item]: Returns the item following the specified item. 
Quit: Quits the program. 
PrintList: Prints out the entire contents of the array and all list. 
GetLength [item]: Gets the Length of the specified list

## How to Run ##
Must run on Nike server. May not work if ran anywhere else. 

Type '$ make' to compile the program into  an executable called p1.
To the run the program, type '$ ./p1 [input_file] << [output_file]'
Where input_file is specified with relative path compared to current
working directory. Where output_file is the file that the program will
output the status to and be relative to current working directory. If no
output_file is specified, then the program will default to printing out 
to output.txt.
