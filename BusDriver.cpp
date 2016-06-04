#include "BusDriver.h"
#include "toolbox.h"

        BusDriver::BusDriver(const int &inputName, const vector<string> &inputRoute ){
            name = inputName;

            for( string routeName : inputRoute){
                int routeNum = str_toInt(routeName);
                route.push_back(routeNum);
            }

            knownGossips.insert(name);
            currentStop = 0;
        };

        int BusDriver::getName(){
            return name;
        };//end of getName()

        int BusDriver::nextStop(){
            currentStop ++;
            if (currentStop >= route.size()){
                currentStop = 0;
            }
            return route.at(currentStop);
        };//end of nextStop

        int BusDriver::getCurrentStop(){
            return route.at(currentStop);
        };

        void BusDriver::addGossips(const BusDriver &inputDriver){
            const std::set <int> &inputGossips = inputDriver.knownGossips;

            for (auto newGossip : inputGossips){
                knownGossips.insert(newGossip);
            }
        };

        size_t BusDriver::gossipCount(){
            return knownGossips.size();
        }
