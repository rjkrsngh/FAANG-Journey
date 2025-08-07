#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

class ThreadSafeSingleton
{
private:
    static std::mutex m_mutex;
    static ThreadSafeSingleton *threadSafeSingletonObj;
    ThreadSafeSingleton() {}
    ~ThreadSafeSingleton() {}

public:
    ThreadSafeSingleton(const ThreadSafeSingleton &tss) = delete;
    ThreadSafeSingleton &operator=(const ThreadSafeSingleton &tss) = delete;

    static ThreadSafeSingleton *getInstance()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (threadSafeSingletonObj == nullptr)
        {
            std::cout << "obj created by thread -> " << std::this_thread::get_id() << std::endl;
            threadSafeSingletonObj = new ThreadSafeSingleton();
        }
        else
        {
            std::cout << "obj not created by thread -> " << std::this_thread::get_id() << std::endl;
        }

        return threadSafeSingletonObj;
    }
};

std::mutex ThreadSafeSingleton::m_mutex;
ThreadSafeSingleton *ThreadSafeSingleton::threadSafeSingletonObj = nullptr;

void func1()
{
    ThreadSafeSingleton *obj = ThreadSafeSingleton::getInstance();
    if (obj)
    {
        std::cout << "TSS object exists\n";
    }
}

void func2()
{
    ThreadSafeSingleton *obj = ThreadSafeSingleton::getInstance();
    if (obj)
    {
        std::cout << "TSS object exists\n";
    }
}

int main()
{
    std::thread th1(func1);
    std::thread th2(func2);

    th1.join();
    th2.join();

    return 0;
}