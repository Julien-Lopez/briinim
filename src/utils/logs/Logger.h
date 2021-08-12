#pragma once

#include <filesystem>

namespace utils
{

class Logger final
{
public:
    /**
     * \brief Where the information comes from.
     */
    enum class Module
    {
        Main,
        Card,
        Game,
        Player,
    };

    /**
     * \brief Type of logging information.
     */
    enum class Type
    {
        Scope, /** \brief Entering or exiting a code block. */
        Info, /** \brief Information on normal behavior. */
        VerboseInfo, /** \brief Verbose information on normal behavior. */
        Debug, /** \brief Debug information on normal behavior. */
        VerboseDebug, /** \brief Verbose debug information on normal behavior. */
        Warning, /** \brief Abnormal non-breaking behavior. */
        Error, /** \brief Abnormal breaking behavior. */
    };

    explicit Logger(const std::filesystem::path path);

    void operator()(const Module module, const Type type, const std::string &msg) const;

private:
    const std::filesystem::path m_path;
};

} // namespace briinim
