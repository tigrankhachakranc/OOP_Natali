#ifndef DISPLAY_COMMAND_HPP
#define DISPLAY_COMMAND_HPP

#include "Command.hpp"

class DisplayCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc);
};

#endif // DISPLAY_COMMAND_HPP