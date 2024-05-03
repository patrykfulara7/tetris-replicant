#pragma once

#include "ampch.hxx"

#include "Core/Application.hxx"

int main(void) {
    auto application = Automata::CreateApplication();
    application->Run();
    delete application;

    return 0;
}
