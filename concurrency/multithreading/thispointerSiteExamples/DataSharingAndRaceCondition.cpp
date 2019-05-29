#include <iostream>
#include <thread>
#include <vector>

class Wallet
{
    public:
        Wallet() : money_(0){}
        ~Wallet(){}

        void addMoney(int amount)
        {
            for(int rs = 0; rs < amount; ++rs)
            {
                ++money_;
            }
        }

        int getMoney() const 
        {
            return money_;
        }

    private:
        int money_;
};

int testMultithreadedWallet()
{
    std::vector<std::thread> threadList;
    Wallet wallet{};

    for(int index = 0; index < 5; ++index)
    {
        threadList.push_back(std::thread(&Wallet::addMoney, &wallet, 2000));
    }

    for(int index = 0; index < 5; ++index)
    {
        threadList.at(index).join();
    }

    return wallet.getMoney();
}


int main(int argc, char const *argv[])
{
    int val = 0;

    for(int index = 0; index < 5000; index++)
    {
        if((val = testMultithreadedWallet()) != 10000)
        {
            std::cout << "Error in count: " << val << "\n";
        }
    }
    return 0;
}
