#include "ScopeLogger.h"

namespace utils
{

ScopeLogger::ScopeLogger(const Logger &logger, const Logger::Module module, std::string &&msg)
    : m_logger(logger),
      m_module(module),
      m_msg(std::move(msg))
{
    m_logger(m_module, Logger::Type::Scope, "BEGIN: " + m_msg);
}

ScopeLogger::ScopeLogger(const Logger &logger, const Logger::Module module, const std::string &msg)
    : ScopeLogger(logger, module, std::string(msg))
{
}

ScopeLogger::~ScopeLogger()
{
    m_logger(m_module, Logger::Type::Scope, "END: " + m_msg);
}

} // namespace utils
