#include "headers/JsonReader.h"
#include <jsoncpp/json/value.h>

namespace dynengines {

    JsonReader::Read() {

        std::fstream blocks_file("blocks.json", std::ifstream::binary);

        blocks_file >> blocks;
    }

}
