#include "lua.hpp"

int cpp_return_5(lua_State* L)
{
	lua_pushnumber(L, 5);

	return 1;
}

int cpp_return_hello(lua_State* L)
{
	lua_pushlstring(L, "hello", 5);

	return 1;
}

void register_functions(lua_State* L)
{
	lua_register(L, "cpp_return_5", cpp_return_5);
	lua_register(L, "cpp_return_hello", cpp_return_hello);
}