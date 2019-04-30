//
// Created by Maldo on 4/28/2019.
//
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef CHEATERS_QUEU_H
#define CHEATERS_QUEU_H

struct ChunkNode
{
    vector <char> c;
    ChunkNode *next;
};

ChunkNode *headChunk;  //the head pointer
ChunkNode *tailChunk;


#endif //CHEATERS_QUEU_H
