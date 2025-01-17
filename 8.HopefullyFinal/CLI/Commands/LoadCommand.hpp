#ifndef LOAD_COMMANDD_HPP
#define LOAD_COMMANDD_HPP

#include "Command.hpp"

class LoadCommand : public Command {
    public:
        LoadCommand(const Map& info);
        void execute();

    private:
        std::streamsize takeFileSize(std::ifstream& file);

    private:
        Map infoMap_;
};

#endif // LOAD_COMMANDD_HPP