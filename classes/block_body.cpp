#include "block_body.h"

BlockBody::BlockBody() { }

BlockBody::BlockBody(std::vector<Transaction> transactions) {
    this->transactions = transactions;
};