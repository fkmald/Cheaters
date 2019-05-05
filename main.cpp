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
int main(int argc, char *argv[])
{

    ChunkNode* HashTable[MAX];
    InitHashTable (HashTable);
    int n = atoi(argv[2]);
    string dir = argv[1];
    int threshold = atoi(argv[3]);
    vector<string> files = vector<string>();

    getdir(dir,files);
   // files[1].erase();
  //  files[0].erase();
    for (unsigned int i = 0 ;i < files.size();i++) {
        vector<string> chunk;
        string word;
       // cout << i << files[i] << endl; //
        ifstream File;
        string path = dir + "/" + files[i];
        File.open (path.c_str());  // opens file
        int index = 0;
        int place = 0;
        while (File >> word){
            if (index < n){
                chunk.push_back(word);
                index++;
            }
            else{
                string finalC = Chunking(chunk, n, place);
                place++;
                unsigned int result = Hashing(finalC);
                placeInHashTable(result, i, HashTable);
                //chunk[place--].erase();
                chunk.push_back(word);
            }
        }

    }

    int gridCheck [files.size()][files.size()];
   // gridInit(gridCheck, (files.size()-2)); //changed to pointer
    for (int i = 0; i < (files.size()); i++) {
        for (int j = 0; j < (files.size()); j++) {
            gridCheck[i][j] = 0;
        }
    }

    for (int transverse =0; transverse < MAX; transverse++){
        if (HashTable[transverse] != NULL){
            ChunkNode *temp = HashTable[transverse];
            while (temp != NULL){
                ChunkNode *temp2 = temp->next;
                while (temp2 != NULL){
                    gridCheck[temp->i][temp2->i]++;
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }

        }

    }
    cout << "2D array" << endl;
    for (int index = 0; index < files.size(); index++) {
        for (int index2 = 0; index2 < files.size(); index2++){
            //cout << gridCheck[index][index2] << " ";
            if (gridCheck[index][index2] >= threshold)
                cout << gridCheck[index][index2] <<":" << files[index] << ", " << files[index2] << endl;
        }
        //cout << endl;
    }
    return 0;
}