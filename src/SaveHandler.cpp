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

        if (encryption == FileEncryption::Standard)
        {
            fs.open(instance->basePath + filepath, std::ios::trunc);

            for (auto const& [key, val] : datatype)
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

                fs << key << "=" << value << "," << std::endl;
            }
        }
        else if (encryption == FileEncryption::Binary)
        {
            fs.open(instance->basePath + filepath, std::ios::trunc | std::ios::binary);
            fs.seekp(0);

            for (auto const& [key, val] : datatype)
            {
                size_t keyLen = key.length();

                fs.write((char*)&keyLen, sizeof(keyLen));
                fs.write(key.data(), keyLen);

                if (val.type == Datatype::ValueType::valtype_string)
                {
                    size_t valLen = std::get<std::string>(val.variant).length();

                    fs.write((char*)&valLen, sizeof(valLen));
                    fs.write(std::get<std::string>(val.variant).data(), valLen);
                }
                else if (val.type == Datatype::ValueType::valtype_double)
                {
                    fs.write((char*)&val.variant, sizeof(double));
                }
                else if (val.type == Datatype::ValueType::valtype_int64)
                {
                    fs.write((char*)&val.variant, sizeof(int64_t));
                }
            }
        }

        fs.close();
    }

    std::map<std::string, Datatype> SaveHandler::LoadData(std::string filepath, FileEncryption encryption)
    {
        std::map<std::string, Datatype> data;

        std::ifstream fs;
        fs.open(instance->basePath + filepath);


        if (encryption == FileEncryption::Standard)
        {
            char c;
            std::string key = "";
            std::string val = "";
            bool keyFound = false;

            while (fs >> c)
            {
                if (c == '=')
                {
                    keyFound = true;
                }
                else if (c == ',')
                {
                    keyFound = false;

                    Datatype dat;
                    dat.type = Datatype::ValueType::valtype_string;
                    dat.variant = val;
                    data.insert(std::pair(key, dat));

                    key = "";
                    val = "";
                }
                else
                {
                    if (!keyFound)
                    {
                        key += c;
                    }
                    else
                    {
                        val += c;
                    }
                }
            }
        }


        fs.close();

        return data;
    }
}