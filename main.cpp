#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <cstdio>
#include <string>
//#include <fstream>
//#include <cstdlib>
//#include <iostream>
#include "Queu.h"

using namespace std;

vector<char> Chunking
/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[])
{
    int n = argv[2];
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0 ;i < files.size();i++) {
        cout << i << files[i] << endl; //
        ofstream File;
        File.open (files[i]);
        while (fgets)

    }
    return 0;
}