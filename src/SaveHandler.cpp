#include "SaveHandler.h"

#include <fstream>
#include <stdlib.h>
#include <iostream>

namespace UT
{
    static SaveHandler* instance;

    SaveHandler::SaveHandler()
    {
        instance = this;

        #if defined(_WIN32) || defined(WIN32)
        basePath = std::getenv("APPDATA");
        #elif defined(__linux__)
        basePath = "$HOME/.local/share";
        #endif

        std::cout << basePath << std::endl;
    }

    void SaveHandler::SaveData(std::string filepath, std::map<std::string, Datatype> datatype, FileEncryption encryption)
    {
        std::ofstream fs;
        fs.open(instance->basePath + filepath);
        
        for (auto const& [key, val] : datatype)
        {
            if (encryption == FileEncryption::Standard)
            {
                std::string value;

                switch (val.type)
                {
                case val.valtype_string:
                    value = std::get<std::string>(val.variant);
                    break;

                case val.valtype_double:
                    value = std::get<double>(val.variant);
                    break;

                case val.valtype_int64:
                    value = std::get<int64_t>(val.variant);
                    break;
                }

                fs << key << "=" << value << std::endl;
            }
        }

        fs.close();
    }

    std::map<std::string, Datatype> SaveHandler::LoadData(std::string filepath, FileEncryption encryption)
    {
        return {};
    }
}