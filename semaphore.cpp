#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;

counting_semaphore<10> semaphore(3);

void worker(int id) {
    semaphore.acquire();
    cout << "Thread" << id << "acquire the thread"
        << endl;
    
    semaphore.release();
    cout << "Thread" << id << "release the thread" << endl;
}


//driver code
int main(){
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join()l
    return 0;
}