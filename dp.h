#include <string>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <limits>
using namespace std;
using namespace std::chrono;

class EnterExit{
    public:
        EnterExit(string functionName):_functionName(functionName){cout << "Enter " << _functionName << endl;  t1 = high_resolution_clock::now();}
        ~EnterExit(){
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
            cout << "Exit " << _functionName << " time consume:" << time_span.count() << " seconds" << endl << endl;}
    private:
        string _functionName;
        high_resolution_clock::time_point t1;
};

#define ENTER() EnterExit _enter(__FUNCTION__);

namespace DP{
    void testrun();
}
