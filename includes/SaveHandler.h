#ifndef UT_SAVE_HANDLER_H
#define UT_SAVE_HANDLER_H
#include <string>
#include <map>
#include <variant>

namespace UT
{
    struct Datatype
    {
        enum class ValueType
        {
            valtype_string,
            valtype_double,
            valtype_int64
        };

        ValueType type;
        std::variant<std::string, double, int64_t> variant;
        
        Datatype() : type(Datatype::ValueType::valtype_string) {}
        Datatype(std::string variant) : type(Datatype::ValueType::valtype_string), variant(variant) {}
        Datatype(double variant) : type(Datatype::ValueType::valtype_double), variant(variant) {}
        Datatype(int64_t variant) : type(Datatype::ValueType::valtype_int64), variant(variant) {}
    };

    enum class FileEncryption
    {
        Standard,
        Binary
    };

    // Class used for saving and loading data
    class SaveHandler
    {
    public:
        SaveHandler();
        static void SaveData(std::string filepath, std::map<std::string, Datatype> data, FileEncryption encryption = FileEncryption::Standard);
        static bool DeleteFile(std::string filepath);
        static std::map<std::string, Datatype> LoadData(std::string filepath, FileEncryption encryption = FileEncryption::Standard);

    private:
        std::string basePath;
    };
}
#endif