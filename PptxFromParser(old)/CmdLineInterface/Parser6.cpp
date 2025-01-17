#include "Parser6.hpp"
#include "../CmdLineInterface/CommandRegistry.hpp"
#include "../Exception.hpp"

#include <iostream>
#include <sstream>

CommandType Parser6::parseCommand (std::string input, const char& endOfLineToken) {
    MapPair<Key, Value> mapPair;
    Tokenizer tokenizer;
    std::istringstream iss(input);
    std::string endToken(1, endOfLineToken);
    
    auto commandName = tokenizer.takeToken(iss, endOfLineToken);
    std::cout << commandName << "[]" << std::endl;
    try {
        CommandRegistry cmdReg;
        auto foundCommand = cmdReg.findCommand(commandName);

        while (true) {
            auto argName = tokenizer.takeToken(iss, endOfLineToken);
            if (argName == endToken) {
                break;
            }
            if (argName.size() <= 1 && argName.at(0) != '-') {
                throw Exception("Invalid argument name syntax: " + argName);
            }

            auto argValue = tokenizer.takeToken(iss, endOfLineToken);
            if (argValue.empty() || argValue == endToken) {
                throw Exception("Empty argument value, " + argValue);
            }
            
            mapPair[argName] = defs::parseArgValue(argValue);
            std::cout << argName << "[name] " << argValue << "[val]" << std::endl;
        }
    }
    ///TODO: check this part out
    catch (const Exception& e) {
        commandName = "";
    }
    CommandType parsedCmd {commandName, mapPair};
    return parsedCmd;
}


