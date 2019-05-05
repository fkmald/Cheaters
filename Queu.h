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
struct ChunkNode
{
    int i;
    ChunkNode *next;
};

ChunkNode *headChunk;  //the head pointer
ChunkNode *tailChunk;

string Chunking(vector<string> chunk, int n, int place){
    string newChunk;
    string word;
    for (int i=place; i<(place+n); i++){ // going through vector
        word = chunk.at(i);
        int length = word.length();
        for (int j = 0; j< length; j++){
            if (isalnum(word[j]))
                newChunk += tolower(word[j]);
        }
    }

    return newChunk;
}

unsigned int Hashing (const string & chunk){
    unsigned int result = 0;
    for (int i = 0; i < chunk.size(); i++){
        result += chunk[i] * (pow(7,i%11));
    }
    result = result % MAX;
    return result;
}


void InitHashTable (ChunkNode* HashTable[]){
    for ( int j = 0; j < MAX; j++)
        //HashTable[j].i = -1;
        HashTable[j] = NULL;
}

//void gridInit (int *grid[], int size){

//}

void placeInHashTable (int result, int index, ChunkNode* table[]){
    bool flag = false;
    if(table[result] != NULL){
        ChunkNode *temp = table[result];
        while(temp->next != NULL){
            if(temp->i == index){
                //temp = NULL;
                flag = true;
                temp->next = NULL;

            }
            else{
                temp = temp->next;
            }
        }
    }
    if(!flag) { //if the index of the file isn't already there
        ChunkNode *slot = new ChunkNode();
        ChunkNode *temp = table[result];
        slot->i = index;
        slot->next = temp;
        table[result] = slot;
    }
}

#endif //CHEATERS_QUEU_H