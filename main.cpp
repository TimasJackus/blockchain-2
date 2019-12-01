#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <bitcoin/bitcoin.hpp>
#include "classes/merkle.h"
#include "classes/transaction.h"
#include "classes/data.h"
#include "classes/block.h"
#include "classes/user.h"
#include "classes/candidate.h"

void verifyTransactions(std::vector<Transaction> &transactionPool, std::vector<User> users) {
    int initialSize = transactionPool.size();
    transactionPool[0].setId("Test");
    for (int i = 0; i < transactionPool.size(); i++) {
        Transaction transaction = transactionPool[i];
        User sender = users[transaction.getSenderId()];
        if (transaction.getId() != transaction.generateHash() || sender.getBalance() < transaction.getAmount()) {
            transactionPool.erase(transactionPool.begin() + i);
        }
    }
    std::cout << "Removed " << initialSize - transactionPool.size() << " invalid transactions." << std::endl;
}

int main() {
    std::vector<User> users = generateUsers();
    std::vector<Transaction> transactionPool = generateTransactions();
    Block genesisBlock = Block(BlockHeader(), BlockBody());
    genesisBlock.mineBlock();
    std::vector<Block> blockchain = { genesisBlock };

    verifyTransactions(transactionPool, users);

    while (transactionPool.size() > 0) {
        std::string previousBlockHash = blockchain.at(blockchain.size() - 1).getHash();
        std::vector<Candidate> candidates = Candidate::createCandidateList(previousBlockHash, transactionPool, 5);

        bool candidateFound = false;
        int maxTransactionsCount = transactionPool.size() >= 100 ? 100 : transactionPool.size();
        for (int i = 0; i < candidates.size(); i++) {
            Block nextBlock = candidates[i].getBlock();
            if (nextBlock.mineBlock()) {
                nextBlock.updateUserBalances(users);
                blockchain.push_back(nextBlock);
                int startIndex = candidates[i].getStartIndex();
                transactionPool.erase(transactionPool.begin() + startIndex, transactionPool.begin() + startIndex + maxTransactionsCount);
                candidateFound = true;
                break;
            }
        }

        if (!candidateFound) {
            std::cout << "Candidate not found!" << std::endl;
        }
    }
    return 0;
}