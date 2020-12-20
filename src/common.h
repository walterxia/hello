#include <string>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <limits>
#include <random>
using namespace std;
using namespace std::chrono;
using std::default_random_engine;
using std::uniform_real_distribution;

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

inline vector<int> genRandomArray(int number)
{
    vector<int> ret;
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, number*10); //随机数分布对象
    for (int i = 0; i < number; ++i)  //生成范围为0-9的随机数序列
        ret.push_back(u(e));
    return ret;
}

template <typename T>
T middle (vector<T>& v, T a, T b, T c)
{
    if((v[b]<=v[a]&&v[c]>=v[a]) ||(v[c]<=v[a]&&v[b]>=v[a]))
        return a;
    else if((v[a]<=v[b]&&v[c]>=v[b]) ||(v[c]<=v[b]&&v[a]>=v[b]))
        return b;
    else if((v[a]<=v[c]&&v[b]>=v[c]) ||(v[b]<=v[c]&&v[a]>=v[c]))
        return c;
    else
    {
        cout <<"FATAL!" << endl;
        return 0;
    }
}


