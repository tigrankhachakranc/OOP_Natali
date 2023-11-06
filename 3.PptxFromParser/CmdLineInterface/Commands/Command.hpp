#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../../Data/Document.hpp"

class Command {
    public:
        Command() : doc_(std::make_shared<Document>()) {}
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~Command() = default;

    protected:
        bool isTypeSlide(MapPair<Key, Value> pairs);
        bool isTypeItem(MapPair<Key, Value> pairs);

    protected:
        std::shared_ptr<Document> doc_;
        static int itemId_;
};

#endif // COMMAND_HPP