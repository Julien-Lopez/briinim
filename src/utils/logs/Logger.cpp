#include "Logger.h"

#include <fstream>
#include <chrono>
#include <thread>

namespace utils
{

inline const std::string to_string(const Logger::Module module)
{
    switch (module)
    {
        case Logger::Module::Main: return "Main";
        case Logger::Module::Card: return "Card";
        case Logger::Module::Game: return "Game";
        case Logger::Module::Player: return "Player";
    }
}

inline std::ostream &operator<<(std::ostream &stream, const Logger::Module module)
{
    return stream << to_string(module);
}

inline const std::string to_string(const Logger::Type type)
{
    switch (type)
    {
        case Logger::Type::Scope: return "Scope";
        case Logger::Type::Info: return "Info";
        case Logger::Type::VerboseInfo: return "VerboseInfo";
        case Logger::Type::Debug: return "Debug";
        case Logger::Type::VerboseDebug: return "VerboseDebug";
        case Logger::Type::Warning: return "Warning";
        case Logger::Type::Error: return "Error";
    }
}

inline std::ostream &operator<<(std::ostream &stream, const Logger::Type type)
{
    return stream << to_string(type);
}

Logger::Logger(const std::filesystem::path path)
    : m_path(std::move(path))
{
}

void Logger::operator()(const Module module, const Type type, const std::string &msg) const
{
    // TODO: Use c++20 chrono when it has been implemented by compilers.
    std::ofstream stream(m_path, std::ios_base::app);
    auto now = std::time(nullptr);
    auto *now_tm = std::gmtime(&now);
    char time[50];

    std::strftime(time, 50, "%Y%m%d %X", now_tm);
    stream << time << " " << std::this_thread::get_id() << " " << module << "    " << type << "    " << msg << '\n';
}

} // namespace briinim
