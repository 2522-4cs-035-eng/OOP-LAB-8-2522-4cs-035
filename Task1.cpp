#include <iostream>
using namespace std;

class Payment {
public:
    virtual double calculateFee() const = 0;
    virtual ~Payment() = default;
};

class BankTransfer : public Payment {
    double amount;
public:
    explicit BankTransfer(double a) : amount(a) {}

    double calculateFee() const override {
        return (amount * 2) / 100;
    }
};

class DigitalWallet : public Payment {
    double amount;
public:
    explicit DigitalWallet(double a) : amount(a) {}

    double calculateFee() const override {
        return amount / 100;
    }
};

int main() {
    BankTransfer b(10000);
    DigitalWallet d(10000);

    cout << "Bank Transfer Fee: " << b.calculateFee() << endl;
    cout << "Digital Wallet Fee: " << d.calculateFee() << endl;

    return 0;
}
