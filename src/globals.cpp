#include "globals.h"

#include "utils/logs/Logger.h"

namespace briinim
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
const utils::Logger g_logger("log.txt");
#pragma clang diagnostic pop

} // namespace briinim
