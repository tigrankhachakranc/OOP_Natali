#ifndef COMMAND_EXECUTOR_FACTORY_HPP
#define COMMAND_EXECUTOR_FACTORY_HPP

#include "CommandExecutor.hpp"
#include "AddCommandExecutor.hpp"
#include "ChangeCommandExecutor.hpp"
#include "DisplayCommandExecutor.hpp"
#include "RemoveCommandExecutor.hpp"
#include "ListCommandExecutor.hpp"
#include "ExitCommandExecutor.hpp"
#include "SaveCommandExecutor.hpp"
#include "LoadCommandExecutor.hpp"

class CommandExecutorFactory {
    public:
        static std::unique_ptr<CommandExecutor> createCommandExecutor (const std::string& cmdName);
};

#endif // COMMAND_EXECUTOR_FACTORY_HPP