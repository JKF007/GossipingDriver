#ifndef BUS_DRIVER
#define BUS_DRIVER

#include <vector>
#include <set>
#include <string>

using std::vector;
using std::string;

class BusDriver{
    private:
        int name;
        vector<int> route;
        std::set<int> knownGossips;
        size_t currentStop;//refer to indices in the route vector

    public:
        BusDriver(const int &inputName, const vector<string> &inputRoute );
        int getName();
        int nextStop();
        int getCurrentStop();
        void addGossips(const BusDriver &inputDriver);
        size_t gossipCount();


};//end of class BusDriver
#endif
