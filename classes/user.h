#ifndef UZDUOTIS_2_USER_H
#define UZDUOTIS_2_USER_H

class User {
private:
    // Properties
    int id;
    std::string name;
    double balance;
    std::string publicKey;

    // Methods
    std::string generatePublicKey(int id, std::string name);
public:
    User(int id, std::string name, double balance);
    void increaseBalance(double amount);
    void decreaseBalance(double amount);
};

#endif //UZDUOTIS_2_USER_H
