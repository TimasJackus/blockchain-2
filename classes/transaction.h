#ifndef UZDUOTIS_2_TRANSACTION_H
#define UZDUOTIS_2_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(int senderId, int recipientId, double amount);
    double getAmount();
    int getSenderId();
    int getRecipientId();

private:
    std::string id;
    double amount;
    int senderId;
    int recipientId;

    std::string generateHash(int senderId, int recipientId, double amount);
};
#endif //UZDUOTIS_2_TRANSACTION_H
