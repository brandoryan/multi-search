# multi-search
a multi-process linear search using fork(), exec(), and wait() system calls

To use the multi-search
./multi-search '<FILE NAME'> '<'KEY'>' '<'NUMBER OF PROCESSES'>'
  
Where '<'FILE NAME'>' is the name of the file containing the strings, '<'NUMBER OF PROCESSES> is
the number of child processes, and '<KEY'> is the string to search for. For example, ./multi-search
strings.txt abcd 10 tells the program to split the task of searching for string "abcd" in file string.txt amongst 10 child processes.
You may create your test file string.txt with random words.
