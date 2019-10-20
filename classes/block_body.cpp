#include "block_body.h"

BlockBody::BlockBody() { }

BlockBody::BlockBody(std::vector<Transaction> transactions) {
    this->transactions = transactions;
};

void BlockBody::updateUserBalances(std::vector<User> &users) {
    for (int i = 0; i < this->transactions.size(); i++) {
        int senderId = this->transactions[i].getSenderId();
        int recipientId = this->transactions[i].getRecipientId();
        double amount = this->transactions[i].getAmount();
        users[senderId].increaseBalance(amount);
        users[recipientId].decreaseBalance(amount);
    }
}