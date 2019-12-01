#ifndef UZDUOTIS_2_BLOCK_HEADER_H
#define UZDUOTIS_2_BLOCK_HEADER_H

#include <string>
#include <bitcoin/bitcoin.hpp>

class BlockHeader {
public:
    BlockHeader();
    BlockHeader(std::string prevBlockHash, std::string merkleRoot, int version, int nonce);
    std::string generateHash();
    int getDifficultyTarget();
    void updateNonce(int nonce);
private:
    std::string prevBlockHash;
    long int timestamp;
    int version;
    int nonce;
    int difficultyTarget;
    std::string merkleRoot;
};


#endif //UZDUOTIS_2_BLOCK_HEADER_H
