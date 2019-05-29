#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Wallet
{
    public:
        Wallet() : money_(0){}
        ~Wallet(){}

        void addMoney(unsigned amount)
        {
            for(unsigned index = 0; index < amount; ++index)
            {
                //lock the variable
                mutex_.lock();
                ++money_;
                //unlock the variable
                mutex_.unlock();
            }
        }

        unsigned getMoney() const
        {
            return money_;
        }

    private:

        unsigned money_;
        std::mutex mutex_;
};

unsigned testMultithreadedWallet()
{
    Wallet wallet;
    std::vector<std::thread> threadList_;
    unsigned noOfThreads = 5;

    for(unsigned index = 0; index < noOfThreads; index++)
    {
        threadList_.push_back(std::thread(&Wallet::addMoney, &wallet, 1000));
    }

    for(auto iter = threadList_.begin(); iter != threadList_.end(); ++iter)
    {
        iter->join();
    }

    return wallet.getMoney();
}

int main(int argc, char const *argv[])
{
    unsigned val = 0;

    for(unsigned index = 0; index < 1000; index++)
    {
        if((val = testMultithreadedWallet()) != 5000)
        {
            std::cout << "Error in count: " << val << "\n";
        }
    }

    return 0;
}

