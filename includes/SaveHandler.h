#ifndef UT_SAVE_HANDLER_H
#define UT_SAVE_HANDLER_H
#include <string>
#include <map>

namespace UT
{
    struct Datatype
    {
        union {
            std::string s;
            double d;
            int64_t i_64;
        };
    };

    enum class FileEncryption
    {
        INI,
        Binary
    };

    // Class used for saving and loading data
    class SaveHandler
    {
    public:
        static void SaveData(std::string filename, std::map<std::string, Datatype> data, FileEncryption encryption);
        static std::map<std::string, Datatype> LoadData(std::string filename, FileEncryption encryption);
    };
}
#endif