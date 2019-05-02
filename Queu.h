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
int MAX = 50000;];
struct ChunkNode
{
    int i;
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


void InitHashTable (ChunkNode HashTable[]){
    for ( int j = 0; j < MAX; j++)
        HashTable[j].i = NULL;
        //HashTable[j].next = NULL;
}

void gridInit (int grid[], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
}

void placeInHashTable (int result, int index, ChunkNode table[]){
    bool flag = false;
    if(table[result].i != NULL){
        ChunkNode *temp = &table[result];
        while(temp != NULL){
            if(temp->i == index){
                temp = NULL;
                flag = true;
            }
            else{
                temp = temp->next;
            }
        }
    }
    if(!flag) { //if the index of the file isn't already there
        ChunkNode *slot = new ChunkNode();
        slot->i = index;
        slot->next = table[result];
        table[result] = slot;
    }
}

#endif //CHEATERS_QUEU_H