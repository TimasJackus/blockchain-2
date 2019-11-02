#ifndef UZDUOTIS_2_USER_H
#define UZDUOTIS_2_USER_H

class User {
private:
    int id;
    std::string name;
    double balance;
    std::string publicKey;

    std::string generatePublicKey(int id, std::string name);

public:
    User(int id, std::string name, double balance);
    void increaseBalance(double amount);
    void decreaseBalance(double amount);
    double getBalance();
};

#endif //UZDUOTIS_2_USER_H
