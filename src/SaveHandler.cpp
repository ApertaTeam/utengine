#include "SaveHandler.h"

#include "Game.h"
#include "Logger.h"
#include "BinaryReader.h"

#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <filesystem>

namespace UT
{
    static SaveHandler* instance;

    SaveHandler::SaveHandler()
    {
        basePath = "";

        instance = this;
    }

    void SaveHandler::Reset()
    {
        // ACTUAL CODE
        #if defined(_WIN32) || defined(WIN32)
            instance->basePath = (std::string)std::getenv("APPDATA") + "\\UTE\\";
            instance->basePath += Game::GetInstance()->GetTitle() + "\\";
        #elif defined(__linux__)
            instance->basePath = (std::string)std::getenv("HOME") + "/.local/share/UTE/";
            instance->basePath += Game::GetInstance()->GetTitle() + "/";
        #endif
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
                fs.write(key.c_str(), (unsigned char)(key.length() + 1));
                fs.write((char*)&val.type, sizeof(unsigned char));

                if (val.type == Datatype::ValueType::valtype_string)
                {
                    fs.write(std::get<std::string>(val.variant).c_str(), std::get<std::string>(val.variant).length() + 1);
                }
                else if (val.type == Datatype::ValueType::valtype_double)
                {
                    fs.write((char*)&std::get<double>(val.variant), sizeof(double));
                }
                else if (val.type == Datatype::ValueType::valtype_int64)
                {
                    fs.write((char*)&std::get<int64_t>(val.variant), sizeof(int64_t));
                }
            }
        }
        fs.close();

        if (errno != 0)
        {
            GlobalLogger->Log(Logger::Error, strerror(errno));
            errno = 0;
        }
    }

    bool SaveHandler::DeleteFile(std::string filepath)
    {
        if (std::remove((instance->basePath + filepath).c_str()) == 0)
        {
            return true;
        }
        else
        {
            if (errno != 0)
            {
                GlobalLogger->Log(Logger::Error, strerror(errno));
                errno = 0;
            }
            return false;
        }
    }

    std::map<std::string, Datatype> SaveHandler::LoadData(std::string filepath, FileEncryption encryption)
    {
        std::map<std::string, Datatype> data;
        std::ifstream fs;

        if (encryption == FileEncryption::Standard)
        {
            fs.open(instance->basePath + filepath);
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

            fs.close();
        }
        else if (encryption == FileEncryption::Binary)
        {
            BinaryFileReader bfr = BinaryFileReader(instance->basePath + filepath);

            while (!bfr.IsAtEOF())
            {
                Datatype dat;
                std::string key = "";
                key = bfr.ReadString();

                dat.type = (Datatype::ValueType)bfr.ReadUInt8();

                if (dat.type == Datatype::ValueType::valtype_string)
                {
                    dat.variant = bfr.ReadString();
                }
                else if (dat.type == Datatype::ValueType::valtype_double)
                {
                    dat.variant = bfr.ReadDouble();

                }
                else if (dat.type == Datatype::ValueType::valtype_int64)
                {
                    dat.variant = bfr.ReadInt64();

                }


                data.insert(std::pair(key, dat));
            }
        }

        if (errno != 0)
        {
            GlobalLogger->Log(Logger::Error, strerror(errno));
            errno = 0;
        }

        return data;
    }
}
