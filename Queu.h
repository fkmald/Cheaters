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

vector<char> Chunking(vector<char> chunk, int n){
    vector<char> newChunk;
    vector<char>::iterator it;
    for(it = chunk.begin(); it < chunk.end(); it++){
        if(*it != ('a'||'b'||'c'||'d'||'e'||'f'||'g'||'h'||'i'||'j'||'k'||'l'||'m'||'n'||'o'||'p'||'q'||'r'||'s'||'t'||'u'||'v'||'w'||'x'||'y'||'z')){
            if(*it == ('A'||'B'||'C'||'D'||'E'||'F'||'G'||'H'||'I'||'J'||'K'||'L'||'M'||'O'||'P'||'Q'||'R'||'S'||'T'||'U'||'V'||'W'||'X'||'Y'||'Z')){
                //make *it lowercase
                if(*it == 'A'){
                    newChunk.push_back('a');
                }
                else if(*it == 'B'){
                    newChunk.push_back('b');
                }
                else if(*it == 'C'){
                    newChunk.push_back('c');
                }
                else if(*it == 'D'){
                    newChunk.push_back('d');
                }
                else if(*it == 'E'){
                    newChunk.push_back('e');
                }
                else if(*it == 'F'){
                    newChunk.push_back('f');
                }
                else if(*it == 'G'){
                    newChunk.push_back('g');
                }
                else if(*it == 'H'){
                    newChunk.push_back('h');
                }
                else if(*it == 'I'){
                    newChunk.push_back('i');
                }
                else if(*it == 'J'){
                    newChunk.push_back('j');
                }
                else if(*it == 'K'){
                    newChunk.push_back('k');
                }
                else if(*it == 'L'){
                    newChunk.push_back('l');
                }
                else if(*it == 'M'){
                    newChunk.push_back('m');
                }
                else if(*it == 'N'){
                    newChunk.push_back('n');
                }
                else if(*it == 'O'){
                    newChunk.push_back('o');
                }
                else if(*it == 'P'){
                    newChunk.push_back('p');
                }
                else if(*it == 'Q'){
                    newChunk.push_back('q');
                }
                else if(*it == 'R'){
                    newChunk.push_back('r');
                }
                else if(*it == 'S'){
                    newChunk.push_back('s');
                }
                else if(*it == 'T'){
                    newChunk.push_back('t');
                }
                else if(*it == 'U'){
                    newChunk.push_back('u');
                }
                else if(*it == 'V'){
                    newChunk.push_back('v');
                }
                else if(*it == 'W'){
                    newChunk.push_back('w');
                }
                else if(*it == 'X'){
                    newChunk.push_back('x');
                }
                else if(*it == 'Y'){
                    newChunk.push_back('y');
                }
                else if(*it == 'Z'){
                    newChunk.push_back('z');
                }
            }
        }
        else{   //if *it is a normal, lowercase letter
            newChunk.push_back(*it);
        }
    }
    return newChunk;
}

#endif //CHEATERS_QUEU_H