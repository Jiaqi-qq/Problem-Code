#include <bits/stdc++.h>
using namespace std;
const int BUFFER_MAX_NUM = 10;
queue<int> buffer;
mutex mtx;
condition_variable cv;
int data;

void productor() {
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(100));
        unique_lock<mutex> lk(mtx);
        while (buffer.size() > BUFFER_MAX_NUM) {
            cv.wait(lk);
        }
        cout << "productor data:" << data << " buffer size:" << buffer.size()
             << endl;
        buffer.push(data++);
        cv.notify_all();
    }
}

void consumer() {
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(500));
        unique_lock<mutex> lk(mtx);
        while (buffer.empty()) {
            cv.wait(lk);
        }
        cout << "\tcosume data:" << buffer.front()
             << " buffer size:" << buffer.size() << endl;
        buffer.pop();
        cv.notify_all();
    }
}

int main() {
    vector<thread> threads;
    threads.push_back(thread(&productor));
    threads.push_back(thread(&productor));
    threads.push_back(thread(&productor));
    threads.push_back(thread(&consumer));
    threads.push_back(thread(&consumer));
    for (auto &t : threads) {
        t.join();
    }
}