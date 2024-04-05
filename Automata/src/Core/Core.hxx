#pragma once

#include "ampch.hxx"

#ifdef AM_DEBUG
    #define AM_ASSERT(x) assert(x)
#else
    #define AM_ASSERT(x)
#endif
