#include <lua.hpp>
#pragma once
int cpp_return_5(lua_State* L);
int cpp_return_hello(lua_State* L);
void register_functions(lua_State* L);