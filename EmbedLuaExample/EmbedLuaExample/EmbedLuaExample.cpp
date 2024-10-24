#include "lua.hpp"
#include <iostream>
#include <fstream>
#include "Functions.h"

bool file_exists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    register_functions(L);

    std::string script_path = "example.lua";
    //std::string script_path = "path/to/your/luafile";

    if (!file_exists(script_path)) {
        std::cerr << "Error: Lua file not found: " << script_path << std::endl;
        lua_close(L);
        return -1;
    }

    if (luaL_dofile(L, script_path.c_str()) != 0) {
        const char* error_msg = lua_tostring(L, -1);
        std::cerr << "Error running Lua file: " << error_msg << std::endl;
        lua_pop(L, 1);
    }

    lua_close(L);
    return 0;
}
