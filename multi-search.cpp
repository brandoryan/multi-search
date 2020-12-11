#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <fstream>
#include <vector>

using namespace std;

// Returns a vector of strings split into vectors of size n
vector<vector<string> > split_vec(vector<string> strings_to_search, int num_children) {
    
    // Number of elements to search through per child process
    int num_per_child_process = strings_to_search.size() / num_children;
    vector<vector<string> > split_string_vec;

    for(vector<string>::iterator it = strings_to_search.begin(); it <= strings_to_search.end(); it+=num_per_child_process) {
        vector<string> addThis = vector<string>(it, it+num_per_child_process);
        split_string_vec.push_back(addThis);
    }

    return split_string_vec;
}

// Returns 0 if found and 1 if not found
int search(vector<string> search_section, string key) {
    for(vector<string>::iterator it = search_section.begin(); it != search_section.end(); ++it) {
        if(*it == key) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv) {
    ifstream infile(argv[1]);
    string key = argv[2];
    int num_children = stoi(argv[3]);

    string a;
    vector<string> strings_to_search;

    while(!infile.eof()) {
        infile >> a;
        strings_to_search.push_back(a);
    }

    vector<vector<string> > split_string_vec = split_vec(strings_to_search, num_children);

    /* 
    Checking the split array
    for(vector<vector<string> >::iterator it = split_string_vec.begin(); it != split_string_vec.end(); ++it) {
        for(int i = 0; i < strings_to_search.size() / num_children; ++i) {
            cout << (*it)[i] << " ";
        }
        cout << endl;
    }
    */

    int pid;
    int exit_status;
    int found;
    vector<int> pids_list;

    cout << endl;

    for(int i = 0; i < num_children; ++i) {
        pid = fork();

        // Error handling for failure to create child
        if(pid < 0) {
            return -1;
        }
        // Parent process
        if(pid > 0) {
            pids_list.push_back(pid);
            wait(&exit_status);
            if(WEXITSTATUS(exit_status) == 0) {
                found = 0;
            }
        }
        // Child process
        else {            
            // Exits with 0 or 1 depending on if string is found in segment
            exit(search(split_string_vec[i], key));
        }
    }

    if(found == 0) {
        cout << "String was found" << endl << endl;
    }
    else {
        cout << "No string was found." << endl << endl;
        // Terminating child processes
        for(int i = 0; i < pids_list.size(); ++i) {
            kill(pids_list[i], SIGKILL);
        }
    }

    return 0;
}
