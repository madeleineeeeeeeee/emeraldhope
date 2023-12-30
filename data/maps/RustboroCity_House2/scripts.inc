RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, RustboroCity_House2_EventScript_ExplainCut
	msgbox RustboroCity_House2_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_TM49
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_DEFAULT
	release
	end


RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Text_TrainerSchoolExcellent:
	.string "The Trainer's School is excellent.\p"
	.string "If you study there, you could even\n"
	.string "become a Gym Leader.$"
	.string "become a Gym Leader.$"

RustboroCity_House2_Text_RoxanneKnowsALot:
	.string "Roxanne, the Gym Leader, really knows\n"
	.string "a lot about Pokémon.\p"
	.string "She's really strong, too!$"
	

	
RustboroCity_House2_EventScript_ExplainCut::
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_DEFAULT
	release
	end

RustboroCity_House2_Text_YouCanPutThisHMToGoodUse:
	.string "I used to teach Roxanne, at the\n"
	.string "Trainer's School. She made great\l"
	.string "use of this TM.\p"
	.string "You seem like an up-and-coming\n"
	.string "Trainer - maybe you'll make good\l"
	.string "use of it too!$"

