#pragma once

#include "ampch.hxx"

namespace Automata {
    class FileIO {
      public:
        static std::string ReadFile(const std::string &path);
    };
} // namespace Automata
