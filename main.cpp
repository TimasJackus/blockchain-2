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
    std::vector<Block> blockchain = { };
    Block candidateBlock = Block(BlockHeader(), BlockBody());
    candidateBlock.mineBlock();
    blockchain.push_back(candidateBlock);


    // Select random transactions
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::vector<int> cards_ = { 1, 2, 3, 4, 5, 6, 7 };
    std::shuffle(std::begin(cards_), std::end(cards_), e);

    std::vector v2 = std::vector<int>(cards_.begin(), cards_.begin() + 4);
    cards_.erase(cards_.begin(), cards_.begin() + 4);

    for (int i = 0; i < cards_.size(); i++) {
        std::cout << cards_[i];
    }

    return 0;
}