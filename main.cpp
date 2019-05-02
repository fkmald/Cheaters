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

//vector<char> Chunking
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
//int argc, char *argv[]
int main()
{
    InitHashTable ();
    int n = 6;
    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();

    getdir(dir,files);
    //files[1].erase();
  //  files[0].erase();
    for (unsigned int i = 2 ;i < files.size();i++) {
        vector<string> chunk;
        string word;
        cout << i << files[i] << endl; //
        ifstream File;
        string path = dir + "/" + files[i];
        File.open (path.c_str());  // opens file
        int index = 0;
        while (File >> word){
            if (index < n){
                chunk.push_back(word);
                index++;
            }
            else{
                string finalC = Chunking(chunk, n);
                unsigned int result = Hashing(finalC);
                //place in to table
                chunk[0].erase();
                chunk.push_back(word);
            }
        }

    }


    return 0;
}