#include "CLIController.hpp"

CLIController::CLIController(std::istream& inputStream, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir) :
    inputStream_(inputStream),
    doc_(doc),
    dir_(dir)
{}

void CLIController::execCLI() {
    const char eolToken = '\n';
    InputReader::readInputLine(inputStream_, eolToken);

    Parser8 parser(inputStream_, eolToken);
    if (parser.isCommandValid()) {
        CommandHistory::append(parser.constructCommandAssInfo());
        Command parsedCmd = parser.constructCommand(doc_, dir_);
        parsedCmd.execute();
    }
}

    /*try {
        parsedCmd = parser.constructCommand();
    }
    catch (const Exception& e) {
        ///TODO: handle exception
    }*/

// docPtr_ = std::make_shared<Document>(); 
    /*while (!exit) {
        InputReader inputReader;
        const char eolToken = '\n';
        auto inputStr = inputReader.readInputLine(input, eolToken);

        // CommandHistory history;
        // history.append(inputStr);
        CommandHistory::append(inputStr);

        Parser7 parser;
        auto parsedCmd = parser.parseCommand(inputStr, eolToken);

        CommandValidator validator;
        if (validator.isCommandValid(parsedCmd)) {
            if (parsedCmd.get<0>() == "exit")
                break;
            Command cmd->execute();  // creates what needs to be created in it
            // ActionTaker action; //call from GUI, CLI 
            // action.execute(parsedCmd, docPtr_);
            
        } 
    }*/