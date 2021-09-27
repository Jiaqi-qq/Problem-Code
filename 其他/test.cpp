#include "ThreadPool.h"
#include <bits/stdc++.h>
using namespace std;

class A {
  public:
    static int a;
    A() = default;
    static void run() {
        cout << a << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
};
int A::a = 115351;
int main() {

    // create thread pool with 4 worker threads
    ThreadPool pool(4);

    // enqueue and store future
    A aa;
    auto result = pool.enqueue([aa]() { aa.run(); });

    // get result from future
    // std::cout << result.get() << std::endl;

    return 0;
}