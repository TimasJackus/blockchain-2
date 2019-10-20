#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include "classes/transaction.h"
#include "classes/data.h"
#include "classes/block.h"
#include "classes/user.h"

int main() {
    std::vector<User> users = generateUsers();
    std::vector<Transaction> pendingTransactions = generateTransactions();
    Block genesisBlock = Block(BlockHeader(), BlockBody());
    genesisBlock.mineBlock();
    std::vector<Block> blockchain = { genesisBlock };

    while (pendingTransactions.size() >= 100) {
        std::string previousBlockHash = blockchain.at(blockchain.size() - 1).getHash();
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(std::begin(pendingTransactions), std::end(pendingTransactions), e);

        std::vector transactions = std::vector<Transaction>(pendingTransactions.begin(), pendingTransactions.begin() + 100);
        Block nextBlock = Block::createCandidateBlock(previousBlockHash, transactions);
        nextBlock.mineBlock();
        nextBlock.updateUserBalances(users);
        blockchain.push_back(nextBlock);
        pendingTransactions.erase(pendingTransactions.begin(), pendingTransactions.begin() + 100);
    }

    return 0;
}