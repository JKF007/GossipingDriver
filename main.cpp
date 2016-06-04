#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "toolbox.h"
#include "BusDriver.h"
#include <map>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::vector;
using std::pair;

int main(){

    vector <BusDriver> driver_list;
    std::ifstream input_file;
    string line;
    vector<string> tokenized_input;
    std::map<int, vector<BusDriver*> >stops;
    int driver_count= 0 ;

    input_file.open("gossipTestInput.txt");

    while (std::getline(input_file, line)){
        tokenized_input.clear();
        string_tokenizer(line, tokenized_input);
        driver_list.push_back(BusDriver(driver_count, tokenized_input) );
        driver_count++;
    }//end of read file loop

    input_file.close();

    int max_stop = 480;
    int currentStop = 1;
    bool finished = false;

    while (currentStop <= max_stop && !finished ){
        stops.clear();

        for(auto& currentDriver : driver_list){

            int driver_current_location = currentDriver.getCurrentStop();
            auto it = stops.find(driver_current_location);

            if (it == stops.end()){
                stops.insert( std::make_pair(driver_current_location, vector<BusDriver*>() )  );
            }

            stops.at(driver_current_location).push_back(&currentDriver);
            currentDriver.nextStop();
        }//arrange drivers into separate vectors depending on current location

        for(auto& tempStop : stops){
            BusDriver* firstDriver = tempStop.second.at(0);

            for (size_t x = 1; x <tempStop.second.size(); x++){
                BusDriver* otherDriver = tempStop.second.at(x);
                firstDriver->addGossips(*otherDriver);
            }

             for (size_t x = 1; x <tempStop.second.size(); x++){
                BusDriver* otherDriver = tempStop.second.at(x);
                otherDriver->addGossips(*firstDriver);
            }
        }//loop for gossip sharing

        finished = true;

        for (auto& currentDriver : driver_list ){
            if (currentDriver.gossipCount() < driver_list.size()){
                finished = false;
            }
        }

        if (finished){
            cout<< currentStop;
        }
        currentStop++;

    }//end of main loop

    if(!finished){
        cout<< "never";
    }
};//end of main
