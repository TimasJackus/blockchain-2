#ifndef UZDUOTIS_2_BLOCK_BODY_H
#define UZDUOTIS_2_BLOCK_BODY_H

#include <vector>
#include "transaction.h"
#include "user.h"

class BlockBody {
public:
    BlockBody();
    BlockBody(std::vector<Transaction> transactions);
    void updateUserBalances(std::vector<User> &users);
private:
    std::vector<Transaction> transactions;
};

#endif //UZDUOTIS_2_BLOCK_BODY_H
