#include "pch.h"

using namespace System;

#include <iostream>                                         // cout
#include "MyForm.h"                                         // Added form from step 3

char frl_g_serial_port[256] = "";

int main(array<System::String ^> ^args)
{
    int i=0;

    memo::MyForm form;                                      // Instantiate form
    System::Windows::Forms::Application::Run(%form);        // Starts a message loop on this thread and makes form visible

    while (1) {         
        std::cout << "Hello World! " << i++ << "\n";        // Show console output
    }
    return 0;
}
