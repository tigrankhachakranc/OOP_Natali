#include "CommandRegistry.hpp"

#include <cmath>

CommandRegistry::CommandRegistry () {
    auto nil = std::numeric_limits<double>::quiet_NaN();
    instantCmds = {
        {"add", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"add", {{"-ops", {nil}}}},
        {"sub", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"sub", {{"-ops", {nil}}}},
        {"mul", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"mul", {{"-ops", {nil}}}},
        {"div", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"div", {{"-ops", {nil}}}},
        {"mod", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"mod", {{"-ops", {nil}}}},
        {"pow", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"sqrt", {{"-op", {nil}}}},
        {"cmp", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"cmp", {{"-ops", {nil}}}},

        {"and", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"nand", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"or", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"nor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"xor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"xnor", {{"-op1", {nil}}, {"-op2", {nil}}}},
        {"not", {{"-op", {nil}}}},

        {"clear_i", {}},
    };

    conserverCmds = {
        {"create", {}}
    };
}

bool CommandRegistry::findCommand (const std::string& commandName) {  // JUST HORRIBLE, like, no
    Tokenizer token;
    auto commandName2 = commandName;

    auto currToken = token.getToken(commandName2);
    auto firstWord = currToken.first;

    std::string createCommand = "";

    if (firstWord == "create") {
        createCommand = firstWord;
        commandName2 = commandName.substr(firstWord.length() + 1);
        currToken = token.getToken(commandName2);
        firstWord = currToken.first;
    }
    
    for (const auto& cmd : instantCmds) {
        const std::string& templateName = cmd.first;
        const std::map<std::string, std::vector<double>>& templateArgs = cmd.second;

        if (templateName == firstWord) {
            commandName2 = commandName2.substr(firstWord.length() + 1); 
            currToken = token.getToken(commandName2);
            firstWord = currToken.first;

            if (firstWord == "-op1") {
                commandName2 = commandName2.substr(firstWord.length() + 1); 
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;

                commandName2 = commandName2.substr(firstWord.length() + 1); 
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                if (firstWord == "-op2") {
                    commandName2 = commandName2.substr(firstWord.length() + 1); 
                    currToken = token.getToken(commandName2);
                    firstWord = currToken.first;
                    commandName2 = commandName2.substr(firstWord.length());
                }
                return commandName2.empty();
            }
            else if (firstWord == "-op") {
                commandName2 = commandName2.substr(firstWord.length() + 1); 
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                commandName2 = commandName2.substr(firstWord.length());
                return commandName2.empty();
            }
            else if (firstWord == "-ops") {
                commandName2 = commandName2.substr(firstWord.length() + 1); 
                currToken = token.getToken(commandName2);
                firstWord = currToken.first;
                commandName2 = commandName2.substr(firstWord.length());
                return !commandName2.empty();
            }
        }
    }
    return false;
}


    /*std::string commandPart = commandName;

    for (auto i = 0; i < combCommands.size(); ++i) {
        if (commandPart.find(combCommands.at(i)) != std::string::npos) {
            auto startIndex = combCommands.at(i).size() + 1;
            commandPart = commandPart.substr(startIndex, commandPart.size() - startIndex);
            break;
        }
    }

    auto endIndex = commandPart.find("-") - 1;
    commandPart = commandPart.substr(0, endIndex);

    for (auto i = 0; i < commands.size(); ++i) {
        if (commandPart.find(commands.at(i)) != std::string::npos) {
            auto startIndex = commands.at(i).size() + 1;
            commandPart = commandPart.substr(startIndex, commandPart.size() - startIndex);
            break;
        }
    }*/