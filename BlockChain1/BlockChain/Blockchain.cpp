

#include "Blockchain.h"

Blockchain::Blockchain()
{
    _vChain.emplace_back(Block(0, "GenesisUser", "GenesisUser", 0));
    _nDifficulty = 4;
    long long start = 0;
    for(int i=0;i<6;i++){
        string user = "user";
        user+= (char)(48+i);
        users.push_back(user);
        balance[user] = 100;
        adhar[user] = start++;
    }

}

void Blockchain::AddBlock(Block bNew)
{
    bNew.sPrevHash = _GetLastBlock().sHash;
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}
