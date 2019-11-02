#include "candidate.h"
#include "data.h"

Candidate::Candidate(Block block, int startIndex) {
    this->block = block;
    this->startIndex = startIndex;
}

Block Candidate::getBlock() {
    return this->block;
}

int Candidate::getStartIndex() {
    return this->startIndex;
}

Candidate Candidate::createCandidateBlock(std::string previousBlockHash, std::vector<Transaction> transactionPool) {
    int maxTransactionsCount = transactionPool.size() >= 100 ? 100 : transactionPool.size();
    int startIndex = maxTransactionsCount == 100 ? getRandomInt(0, transactionPool.size() - maxTransactionsCount) : 0;
    std::vector transactions = std::vector<Transaction>(transactionPool.begin() + startIndex, transactionPool.begin() + startIndex + maxTransactionsCount);

    BlockHeader blockHeader = BlockHeader(previousBlockHash, 1, 1);
    BlockBody blockBody = BlockBody(transactions);
    Block block = Block(blockHeader, blockBody);

    return Candidate(block, startIndex);
};

std::vector<Candidate> Candidate::createCandidateList(std::string previousBlockHash, std::vector<Transaction> transactionPool, int count) {
    std::vector<Candidate> candidates;

    for (int i = 0; i < count; i++) {
        candidates.push_back(Candidate::createCandidateBlock(previousBlockHash, transactionPool));
    }

    return candidates;
}
