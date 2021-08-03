#include "Logger.h"

#include <fstream>

namespace utils
{

inline const std::string to_string(const Logger::Module module)
{
    return module == Logger::Module::Main ? "Main"
        : module == Logger::Module::Card ? "Card"
        : module == Logger::Module::Game ? "Game"
        : module == Logger::Module::Player ? "Card"
        : "UnknownModule";
}

inline std::ostream &operator<<(std::ostream &stream, const Logger::Module module)
{
    return stream << to_string(module);
}

inline const std::string to_string(const Logger::Type module)
{
    return module == Logger::Type::Info ? "Info"
        : module == Logger::Type::VerboseInfo ? "VerboseInfo"
        : module == Logger::Type::Debug ? "Debug"
        : module == Logger::Type::VerboseDebug ? "VerboseDebug"
        : module == Logger::Type::Warning ? "Warning"
        : module == Logger::Type::Error ? "Error"
        : "UnknownType";
}

inline std::ostream &operator<<(std::ostream &stream, const Logger::Type type)
{
    return stream << to_string(type);
}

Logger::Logger(const std::filesystem::path path)
    : m_path(std::move(path))
{
}

void Logger::log(const Module module, const Type type, const std::string &msg) const
{
    std::ofstream stream(m_path, std::ios_base::app);

    stream << module << "    " << type << "    " << msg;
}

void Logger::log(const Module module, const Type type, std::string &&msg) const
{
    log(module, type, msg);
}

} // namespace briinim
