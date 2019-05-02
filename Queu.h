#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
using namespace std;

#ifndef CHEATERS_QUEU_H
#define CHEATERS_QUEU_H
int MAX = 50000;
int HashTable[MAX];
struct ChunkNode
{
    vector <char> c;
    ChunkNode *next;
};

ChunkNode *headChunk;  //the head pointer
ChunkNode *tailChunk;

string Chunking(vector<string> chunk, int n){
    string newChunk;
    string word;
    for (int i=0; i<n; i++){ // going through vector
        word = chunk.at(i);
        int length = word.length();
        for (int j = 0; j< length; j++){
            if (isalnum(word[j]))
                newChunk += word;
        }
    }

    return newChunk;
}

unsigned int Hashing (const string & chunk){
    unsigned int result = 0;
    for (int i = 0; i < chunk.size(); i++){
        result += chunk[i] * (pow(7,i);
        result = result % MAX;
    }
    return result;
}

void InitHashTable (){
    for ( int i = 0; i < MAX; i++)
        HashTable[i]= NULL;
}

#endif //CHEATERS_QUEU_H