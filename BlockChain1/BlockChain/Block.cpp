
#include "Block.h"
#include "sha256.h"
#include<bits/stdc++.h>

Block::Block(uint32_t nIndexIn, const string &from, const string &to, int amount) : _nIndex(nIndexIn), from(from),to(to), amount(amount)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';

    string str(cstr);

    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);

    cout << "Block mined: " << sHash << " " << ctime(&_tTime) << endl;
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << from << to << _nNonce;

    return sha256(ss.str());
}
