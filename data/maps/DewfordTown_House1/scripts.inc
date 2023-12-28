DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_Mart_EventScript_ExpandedItems
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_DEFAULT
	pokemart DewfordTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
DewfordTown_Mart_Pokemart_Basic:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_REPEL
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_NONE
	release
	end

DewfordTown_Mart_EventScript_ExpandedItems::
	msgbox DewfordTown_House1_Text_StevenLeftThese, MSGBOX_DEFAULT
	pokemart DewfordTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end	

	.align 2
DewfordTown_Mart_Pokemart_Expanded:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_REPEL
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_NONE
	release
	end

DewfordTown_Mart_EventScript_NotMyRoom::
	msgbox DewfordTown_House1_Text_NotMyRoom, MSGBOX_NPC
	end


DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Welcome to our cozy little shop!$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "I left the major port of Slateport\n"
	.string "City when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island, so we opened up a shop to\l"
	.string "keep ourselves occupied.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "Zigzagoon: Guguuh!$"

DewfordTown_House1_Text_NotMyRoom:
	.string "This is the door to their living\n"
	.string "quarters. I have no business there.$"

DewfordTown_House1_Text_StevenLeftThese:
	.string "Steven Stone just passed through!\p"
	.string "He showed us how to get these rare\n"
	.string "stones from Granite Cave!\p"
	.string "Care to buy some?$"
