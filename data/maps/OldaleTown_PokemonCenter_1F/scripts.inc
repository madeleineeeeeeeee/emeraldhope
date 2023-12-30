.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_NameRater::
	lock
	faceplayer
	msgbox OldaleTown_PokemonCenter_1F_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_PokemonCenter_1F_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_DeclineNameRate
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMonToRate::
	msgbox OldaleTown_PokemonCenter_1F_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_PokemonCenter_1F_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_PokemonCenter_1F_EventScript_DeclineNameRate
	end

OldaleTown_PokemonCenter_1F_EventScript_DeclineNameRate::
	msgbox OldaleTown_PokemonCenter_1F_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, OldaleTown_PokemonCenter_1F_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_PlayerNotMonsOT
	msgbox OldaleTown_PokemonCenter_1F_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OldaleTown_PokemonCenter_1F_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_DeclineNameRate
	end

OldaleTown_PokemonCenter_1F_EventScript_CantRateEgg::
	msgbox OldaleTown_PokemonCenter_1F_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_PlayerNotMonsOT::
	msgbox OldaleTown_PokemonCenter_1F_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_ChangeNickname::
	msgbox OldaleTown_PokemonCenter_1F_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_NewNameDifferent
	msgbox OldaleTown_PokemonCenter_1F_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_NewNameDifferent::
	msgbox OldaleTown_PokemonCenter_1F_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_PleasedToRateMonNickname:
	.string "This Porygon provides Name Rating\n"
	.string "services!\l"
	.string "It beeps happily at your greeting.\p"
	.string "Will you rename a Pokémon?$"


OldaleTown_PokemonCenter_1F_Text_CritiqueWhichMonNickname:
	.string "Which Pokémon's nickname should\n"
	.string "Porygon critique?$"

OldaleTown_PokemonCenter_1F_Text_FineNameSuggestBetterOne:
	.string "Porygon whirrs contemplatively… \n"
	.string "{STR_VAR_1}…\p"
	.string "It beeps to inquire if you wish to\n"
	.string "change this name.$"

OldaleTown_PokemonCenter_1F_Text_WhatShallNewNameBe:
	.string "Porygon gives a dutiful chime as it\n"
	.string "prepares to rate the name.$"

OldaleTown_PokemonCenter_1F_Text_MonShallBeKnownAsName:
	.string "Porygon blips with satisfaction!\n"
	.string "Your Pokémon is now {STR_VAR_1}!$"

OldaleTown_PokemonCenter_1F_Text_DoVisitAgain:
	.string "Porygon beeps a cordial farewell.$"

OldaleTown_PokemonCenter_1F_Text_NameNoDifferentYetSuperior:
	.string "Porygon chimes in perplexion\n"
	.string "at your indecisiveness.\p"
	.string "{STR_VAR_1}'s name is unchanged.$"

OldaleTown_PokemonCenter_1F_Text_MagnificentName:
	.string "Porygon beeps with bemusement.\n"
	.string "{STR_VAR_1}'s name cannot be changed.$"

OldaleTown_PokemonCenter_1F_Text_ThatIsMerelyAnEgg:
	.string "Porygon beeps with apparent confusion\n"
	.string "at your attempt to name an Egg.$"


OldaleTown_PokemonCenter_1F_EventScript_MoveRelearner::
	lockall
	faceplayer
	goto_if_set FLAG_TEMP_1, OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	msgbox OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	end

OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove::
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMon::
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMove
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMove::
	msgbox OldaleTown_PokemonCenter_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale
	end

OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon::
	msgbox OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg::
	msgbox OldaleTown_PokemonCenter_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ComeBackWithHeartScale::
	msgbox OldaleTown_PokemonCenter_1F_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor:
	.string "I'm a traveling Move Tutor!\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn--every one of them--and I can\l"
	.string "teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.$"

OldaleTown_PokemonCenter_1F_Text_TutorWhichMon:
	.string "Which Pokémon needs tutoring?$"

OldaleTown_PokemonCenter_1F_Text_TeachWhichMove:
	.string "Which move should I teach?$"

OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "I don't have any moves that I can\n"
	.string "teach that Pokémon.$"

OldaleTown_PokemonCenter_1F_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an Egg.$"

OldaleTown_PokemonCenter_1F_Text_ComeBackWithHeartScale:
	.string "If your Pokémon need to learn a move,\n"
	.string "come see me any time!$"

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 81FC0CD
	.string "Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 81FC148
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 81FC1B9
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "I traded Pokémon right away.$"

