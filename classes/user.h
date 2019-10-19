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
    std::string generatePublicKey(std::string name);
public:
    User(int id, std::string name, double balance);

    friend std::ostream& operator<<(std::ostream& os, User const & user);
};

#endif //UZDUOTIS_2_USER_H
