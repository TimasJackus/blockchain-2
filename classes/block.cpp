#include <iostream>
#include "block.h"
#include "user.h"

int const TIME_LIMIT_SECS = 2.5;

Block::Block() { }

Block::Block(BlockHeader header, BlockBody body) {
    this->header = header;
    this->body = body;
}

bool Block::mineBlock() {
    int difficultyTarget = this->header.getDifficultyTarget();
    int nonce = 0;
    this->header.updateNonce(nonce);
    std::string zeros = std::string(difficultyTarget, '0');
    std::string currentHash = this->header.generateHash();
    double start = clock();
    while (currentHash.compare(0, zeros.length(), zeros) != 0 && ((clock() - start) / CLOCKS_PER_SEC) < TIME_LIMIT_SECS) {
        nonce++;
        this->header.updateNonce(nonce);
        currentHash = this->header.generateHash();
    }
    if (currentHash.compare(0, zeros.length(), zeros) == 0) {
        this->hash = currentHash;
        return true;
    }
    return false;
}

void Block::updateUserBalances(std::vector<User> &users) {
    this->body.updateUserBalances(users);
}

std::string Block::getHash() {
    return this->hash;
}