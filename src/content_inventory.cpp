/*
Minetest-c55
Copyright (C) 2010-2011 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "content_inventory.h"
#include "inventory.h"
#include "content_mapnode.h"
//#include "serverobject.h"
#include "content_sao.h"
//#include "gamedef.h"
//#include "nodedef.h"

std::string item_craft_get_image_name(const std::string &subname,
		IGameDef *gamedef)
{
	if(subname == "Stick")
		return "stick.png";
	else if(subname == "paper")
		return "paper.png";
	else if(subname == "book")
		return "book.png";
	else if(subname == "lump_of_coal")
		return "lump_of_coal.png";
	else if(subname == "lump_of_iron")
		return "lump_of_iron.png";
	else if(subname == "lump_of_clay")
		return "lump_of_clay.png";
	else if(subname == "steel_ingot")
		return "steel_ingot.png";
	else if(subname == "clay_brick")
		return "clay_brick.png";
	else if(subname == "rat")
		return "rat.png";
	else if(subname == "cooked_rat")
		return "cooked_rat.png";
	else if(subname == "scorched_stuff")
		return "scorched_stuff.png";
	else if(subname == "firefly")
		return "firefly.png";
	else if(subname == "apple")
		return "apple.png^[forcesingle";
	else if(subname == "apple_iron")
		return "apple_iron.png";
	else if(subname == "testobject1") // test object
		return "unknown_block.png^[forcesingle";
	else
		return "cloud.png"; // just something
}

ServerActiveObject* item_craft_create_object(const std::string &subname,
		ServerEnvironment *env, v3f pos)
{
	if(subname == "rat")
	{
		ServerActiveObject *obj = new RatSAO(env, pos);
		return obj;
	}
	else if(subname == "firefly")
	{
		ServerActiveObject *obj = new FireflySAO(env, pos);
		return obj;
	}
	else if(subname == "testobject1")
	{
		ServerActiveObject *obj = new LuaEntitySAO(env, pos, "testentity", "");
		return obj;
	}

	return NULL;
}

s16 item_craft_get_drop_count(const std::string &subname, IGameDef *gamedef)
{
	if(subname == "rat" || subname == "firefly" || subname == "testobject1")
		return 1;

	return -1;
}

bool item_craft_is_cookable(const std::string &subname, IGameDef *gamedef)
{
	if(subname == "lump_of_iron" || subname == "lump_of_clay" || subname == "rat" || subname == "cooked_rat")
		return true;
		
	return false;
}

InventoryItem* item_craft_create_cook_result(const std::string &subname,
		IGameDef *gamedef)
{
	if(subname == "lump_of_iron")
		return new CraftItem(gamedef, "steel_ingot", 1);
	else if(subname == "lump_of_clay")
		return new CraftItem(gamedef, "clay_brick", 1);
	else if(subname == "rat")
		return new CraftItem(gamedef, "cooked_rat", 1);
	else if(subname == "cooked_rat")
		return new CraftItem(gamedef, "scorched_stuff", 1);

	return NULL;
}

bool item_craft_is_eatable(const std::string &subname, IGameDef *gamedef)
{
	if(subname == "cooked_rat")
		return true;
	else if(subname == "apple")
		return true;
	else if(subname == "apple_iron")
		return true;
	return false;
}

s16 item_craft_eat_hp_change(const std::string &subname, IGameDef *gamedef)
{
	if(subname == "cooked_rat")
		return 6; // 3 hearts
	else if(subname == "apple")
		return 4; // 2 hearts
	else if(subname == "apple_iron")
		return 8; // 4 hearts
	return 0;
}


