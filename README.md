# multi-search
a multi-process linear search using fork(), exec(), and wait() system calls

To use the multi-search
./multi-search 'FILE NAME' 'KEY' 'NUMBER OF PROCESSES'<br />
  
'FILE NAME' is the name of the file containing the strings<br />
'NUMBER OF PROCESSES' is the number of child processes<br />
'KEY' is the string to search for<br />

For example:
./multi-search strings.txt abcd 10 

Tells the program to split the task of searching for string 
"abcd" in file string.txt amongst 10 child processes.
