#include "block.h"
#include "user.h"

Block::Block(BlockHeader header, BlockBody body) {
    this->header = header;
    this->body = body;
}

void Block::mineBlock() {
    int difficultyTarget = this->header.getDifficultyTarget();
    int nonce = 0;
    this->header.updateNonce(nonce);
    std::string zeros = std::string(difficultyTarget, '0');
    std::string currentHash = this->header.generateHash();
    while (currentHash.compare(0, zeros.length(), zeros) != 0) {
        nonce++;
        this->header.updateNonce(nonce);
        currentHash = this->header.generateHash();
    }
    this->hash = currentHash;
}

void Block::updateUserBalances(std::vector<User> &users) {
    this->body.updateUserBalances(users);
}

std::string Block::getHash() {
    return this->hash;
}

Block Block::createCandidateBlock(std::string previousBlockHash, std::vector<Transaction> transactions) {
    BlockHeader blockHeader = BlockHeader(previousBlockHash, 1, 1);
    BlockBody blockBody = BlockBody(transactions);
    Block candidateBlock = Block(blockHeader, blockBody);

    return candidateBlock;
};