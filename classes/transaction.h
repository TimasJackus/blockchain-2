#ifndef UZDUOTIS_2_TRANSACTION_H
#define UZDUOTIS_2_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(int senderId, int recipientId, double amount);

private:
    std::string hashValue;
    double amount;
    int senderId;
    int recipientId;

    std::string generateHash(int senderId, int recipientId, double amount);
    friend std::ostream& operator<<(std::ostream& os, Transaction const & transaction);
};
#endif //UZDUOTIS_2_TRANSACTION_H
