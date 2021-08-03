#pragma once

#include "Logger.h"

namespace utils
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
class ScopeLogger
{
public:
    explicit ScopeLogger(const Logger &logger, const Logger::Module module, std::string &&msg);
    explicit ScopeLogger(const Logger &logger, const Logger::Module module, const std::string &msg);
    ~ScopeLogger();
    ScopeLogger(const ScopeLogger &) = delete;
    ScopeLogger(ScopeLogger &&) = delete;
    ScopeLogger &operator=(const ScopeLogger &) = delete;
    ScopeLogger &operator=(ScopeLogger &&) = delete;

private:
    const Logger &m_logger;
    const Logger::Module m_module;
    const std::string m_msg;
};
#pragma clang diagnostic pop

} // namespace utils
