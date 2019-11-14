#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block {
public:
    string sHash;
    string sPrevHash;

    Block(uint32_t nIndexIn, const string &from, const string &to, int amount);

    void MineBlock(uint32_t nDifficulty);

//private:
    uint32_t _nIndex;
    uint32_t _nNonce;
    string from,to;
    time_t _tTime;
    int amount;

    string _CalculateHash() const;
};

#endif //TESTCHAIN_BLOCK_H
