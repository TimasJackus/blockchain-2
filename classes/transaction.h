#ifndef UZDUOTIS_2_TRANSACTION_H
#define UZDUOTIS_2_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(int senderId, int recipientId, double amount);
    double getAmount();
    int getSenderId();
    int getRecipientId();
    std::string getId();
    void setId(std::string id);
    std::string generateHash(int senderId, int recipientId, double amount, long int timestamp);
    std::string generateHash();

private:
    std::string id;
    double amount;
    int senderId;
    int recipientId;
    long int timestamp;
};
#endif //UZDUOTIS_2_TRANSACTION_H
