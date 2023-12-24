PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_RoostWoman::
	lock
	faceplayer
	goto_if_set FLAG_TM_ROOST, PetalburgCity_House1_EventScript_Woman
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_DEFAULT
	giveitem ITEM_TM84
	setflag FLAG_TM_ROOST
	msgbox PetalburgCity_House1_Text_ComingUpWithMealsIsHard, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House1_EventScript_ExplainCut::
	msgbox PetalburgCity_House1_Text_ComingUpWithMealsIsHard, MSGBOX_DEFAULT
	release
	end

PetalburgCity_House1_Text_ComingUpWithMealsIsHard:
	.string "The woman winks at you.$"

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end



PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Traveling is wonderful!\p"
	.string "When I was young, I roamed the seas\n"
	.string "and the mountains!$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some Pokémon…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "But instead, I'm roosting here in my\n"
	.string "little home.$"

