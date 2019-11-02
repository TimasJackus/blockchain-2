#ifndef UZDUOTIS_2_BLOCK_H
#define UZDUOTIS_2_BLOCK_H

#include "block_header.h"
#include "block_body.h"

class Block {
    std::string hash;
    BlockHeader header;
    BlockBody body;

public:
    Block();
    Block(BlockHeader header, BlockBody body);
    bool mineBlock();
    void updateUserBalances(std::vector<User> &users);
    std::string getHash();
};

#endif //UZDUOTIS_2_BLOCK_H
