#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <istream>
#include <string>

class Tokenizer {
    public: 
        std::string takeToken (std::istringstream& iss, const char& endOfLineToken);
};

#endif // TOKENIZER_HPP