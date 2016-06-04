#include "toolbox.h"
#include <sstream>
#include <vector>
#include <math.h>

    string removeChar(const string& input, const char& unwanted){
        string result;

        for (size_t index = 0; index < input.size(); index++){
            char currentChar = input.at(index);
            if (currentChar != unwanted){
                result += currentChar;
            }
        }
        return result;
    };
    string int_toStr(int input){
        std::ostringstream intConverter;

        intConverter <<input;

        return intConverter.str();
    };

    int str_toInt(const string& input){
        std::istringstream stringConverter (input);

        int result;

        stringConverter >>result;

        return result;
    };

    bool isNumeric(const string& input){
        if( input.size() ==0){
            return false;
        }

        for (const char& oneChar : input){

            if (!isdigit(oneChar)){
                return false;
            }
        }
        return true;
    };

    bool checkRange(const string& input, int min, int max){

        if(isNumeric(input)){
            int inputAsInt = str_toInt(input);
            if(min <= inputAsInt && inputAsInt <=max){
                return true;
            }

        }
        return false;
    };

    int string_tokenizer (const std::string& input, std::vector <std::string> &container , const char& delimiter ){
        size_t inputIndex =0;
        size_t containerIndex = container.size();

        while (inputIndex < input.size()){
            if( input.at(inputIndex) == delimiter){
                inputIndex++;//found delimiter, skip character
            }
            else{
                container.push_back("");
                while (inputIndex < input.size() && input.at(inputIndex) != delimiter){
                    //combine the character until the code hit another delimiter or end of line
                    container.at(containerIndex) += input.at(inputIndex);
                    inputIndex ++;
                }
                    containerIndex++;
            }
        }

        return 0;
    };

    void getDivisors(const int& input, vector <int> &container ){

        if (input < 1){
            return;
        }

        for (int divider = 1; divider <= input; divider++){
            int remainder = input % divider;

            if(remainder == 0){
                container.push_back(divider);
            }

        }

    };

    bool compareVectors(const vector <int> &first, const vector <int> &second){
        if ( first.size() != second.size()){
            return false;
        }

        for (size_t index =0; index < first.size(); index ++ ){

            if ( first.at(index) != second.at(index) ){
                    return false;
            }
        }
        return true;
    };

    int vectorSearch(const string& input, std::vector <string> &container){

        for (size_t index = 0; index < container.size(); index ++){
            string item = container.at(index);
            if (input.compare(item) ==0){
                return index;
            }

        }
        return -1;
    };
