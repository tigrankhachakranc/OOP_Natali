#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "Command.hpp"

class SaveCommand : public Command {
    public:
        void execute(CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // SAVE_COMMAND_HPP