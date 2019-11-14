
#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"
#include<bits/stdc++.h>

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);
    vector<string> users;
    //vector<int> balance;
    //vector<long long> adhar;
    map<string, int> adhar;
    map<string, int> balance;
    vector<Block> _vChain;

private:
    uint32_t _nDifficulty;


    Block _GetLastBlock() const;
};

#endif //TESTCHAIN_BLOCKCHAIN_H
