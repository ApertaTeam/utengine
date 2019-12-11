#include "SaveHandler.h"

#include "Game.h"

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <filesystem>

namespace UT
{
    static SaveHandler* instance;

    SaveHandler::SaveHandler()
    {
        instance = this;

        #if defined(_WIN32) || defined(WIN32)
        basePath = (std::string)std::getenv("APPDATA") + "\\UTE\\";
        #elif defined(__linux__)
        basePath = (std::string)std::getenv("HOME") + "\\.local\\share\\UTE\\";
        #endif

        basePath += Game::GetInstance()->GetTitle() + "\\";
    }

    void SaveHandler::SaveData(std::string filepath, std::map<std::string, Datatype> datatype, FileEncryption encryption)
    {
        if (!std::filesystem::exists(instance->basePath))
        {
            std::filesystem::create_directories(instance->basePath);
        }

        std::ofstream fs;
        fs.open(instance->basePath + filepath, std::ios::trunc);

        for (auto const& [key, val] : datatype)
        {
            if (encryption == FileEncryption::Standard)
            {
                std::string value;

                switch (val.type)
                {
                case Datatype::ValueType::valtype_string:
                    value = std::get<std::string>(val.variant);
                    break;

                case Datatype::ValueType::valtype_double:
                    value = std::to_string(std::get<double>(val.variant));
                    break;

                case Datatype::ValueType::valtype_int64:
                    value = std::to_string(std::get<int64_t>(val.variant));
                    break;

                default:
                    value = std::get<std::string>(val.variant);
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