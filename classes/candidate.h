#ifndef UZDUOTIS_2_CANDIDATE_H
#define UZDUOTIS_2_CANDIDATE_H

#include "block.h"

class Candidate {
    Block block;
    int startIndex;

public:
    Candidate(Block block, int startIndex);
    Block getBlock();
    int getStartIndex();
    static Candidate createCandidateBlock(std::string previousBlockHash, std::vector<Transaction> transactions);
    static std::vector<Candidate> createCandidateList(std::string previousBlockHash, std::vector<Transaction> transactionPool, int count);
};

#endif //UZDUOTIS_2_CANDIDATE_H
