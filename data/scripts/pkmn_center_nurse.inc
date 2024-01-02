Common_EventScript_PkmnCenterNurse::
	lock
	faceplayer
	checkitem ITEM_POKEVIAL, 1
    compare VAR_RESULT, 1
    goto_if_eq EventScript_PkmnCenterNurseHasVial
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	goto_if_eq VAR_RESULT, 4, EventScript_PkmnCenterNurse_GoldCard
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurseHasVial::
    setvar VAR_0x8004, 0
    specialvar VAR_RESULT, CountPlayerTrainerStars
    compare VAR_RESULT, 4
    goto_if_eq EventScript_PkmnCenterNurse_GoldCard
    msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_PkmnCenterNurse_HealPkmn
    compare VAR_RESULT, NO
    goto_if_eq EventScript_PkmnCenterNurse_Goodbye
    end

EventScript_PkmnCenterNurse_Goodbye::
	message gText_WeHopeToSeeYouAgain
	return

@ VAR_0x8004 is 1 when player has Gold Card; jumps are identical
EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	call_if_eq VAR_0x8004, 0, EventScript_PkmnCenterNurse_IllTakeYourPkmn
	call_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_IllTakeYourPkmn2
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	goto_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	goto EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_IllTakeYourPkmn::
	message gText_IllTakeYourPkmn
	return

EventScript_PkmnCenterNurse_IllTakeYourPkmn2::
	message gText_IllTakeYourPkmn2
	return

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	special PokevialRefill
	call EventScript_CheckReset_OptionalTrainers
	call EventScript_CheckReset_Route102
	call EventScript_CheckReset_Route104_PetalburgWoods
	call EventScript_CheckReset_RustboroGym
	call EventScript_CheckReset_Route116_RusturfTunnel
	call EventScript_CheckReset_DewfordGym
	return

EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom::
	specialvar VAR_RESULT, PlayerNotAtTrainerHillEntrance
	goto_if_eq VAR_RESULT, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

@ VAR_0x8004 is 1 when player has Gold Card
EventScript_PkmnCenterNurse_ReturnPkmn::
	goto_if_eq VAR_0x8004, 1, EventScript_PkmnCenterNurse_ReturnPkmn2
	message gText_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_ReturnPkmn2::
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message CableClub_Text_PlayerIsWaiting
	waitmessage
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	message gText_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_CheckTrainerHillAndUnionRoom
	end

EventScript_PkmnCenterNurse_ExplainPokerus::
	message gText_PokerusExplanation
	setflag FLAG_POKERUS_EXPLAINED
	return

EventScript_PkmnCenterNurse_GoldCard::
	goto_if_set FLAG_NURSE_MENTIONS_GOLD_CARD, EventScript_PkmnCenterNurse_AskForUsual
	setflag FLAG_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_WelcomeCutShort, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NoticesGoldCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_AskForUsual::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_GoldCardHealPkmn
	message gText_WeHopeToSeeYouAgain2
	return

EventScript_PkmnCenterNurse_GoldCardHealPkmn::
	setvar VAR_0x8004, 1
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

EventScript_CheckReset_OptionalTrainers:
	goto TrainerReset_OptionalTrainers
	return

EventScript_CheckReset_Route102:
	checktrainerflag TRAINER_TIANA
	goto_if 0, TrainerReset_Route102
	return

EventScript_CheckReset_Route104_PetalburgWoods:
	checktrainerflag TRAINER_WINSTON_1
	goto_if 0, TrainerReset_Route104_PetalburgWoods
	return

EventScript_CheckReset_RustboroGym:
	checktrainerflag TRAINER_ROXANNE_1
	goto_if 0, TrainerReset_RustboroGym
	return

EventScript_CheckReset_DewfordGym:
	checktrainerflag TRAINER_BRAWLY_1
	goto_if 0, TrainerReset_DewfordGym
	return	

EventScript_CheckReset_Route116_RusturfTunnel:
	checktrainerflag TRAINER_MIKE_1
	goto_if 0, TrainerReset_Route116_RusturfTunnel
	return

TrainerReset_OptionalTrainers:
	cleartrainerflag TRAINER_DARIAN
	cleartrainerflag TRAINER_IVAN
	cleartrainerflag TRAINER_RICK
	cleartrainerflag TRAINER_SARAH
	cleartrainerflag TRAINER_DAWSON
	cleartrainerflag TRAINER_LYLE
	cleartrainerflag TRAINER_JERRY_1
	cleartrainerflag TRAINER_JANICE
	cleartrainerflag TRAINER_CYNDY_1
	cleartrainerflag TRAINER_NOB_1
	cleartrainerflag TRAINER_HECTOR
	cleartrainerflag TRAINER_MARLENE
	cleartrainerflag TRAINER_ELLIOT_1
	cleartrainerflag TRAINER_HUEY
	cleartrainerflag TRAINER_HAILEY
	cleartrainerflag TRAINER_RICKY_1
	cleartrainerflag TRAINER_EDMOND
	cleartrainerflag TRAINER_LOLA_1
	cleartrainerflag TRAINER_HUEY
	cleartrainerflag TRAINER_CHANDLER
	cleartrainerflag TRAINER_EDMOND
	return


TrainerReset_Route102:
	cleartrainerflag TRAINER_CALVIN_1
	cleartrainerflag TRAINER_ALLEN
	return
	

TrainerReset_RustboroGym:
	cleartrainerflag TRAINER_MARC
	cleartrainerflag TRAINER_TOMMY
	cleartrainerflag TRAINER_JOSH
	return
	

TrainerReset_Route104_PetalburgWoods:
	cleartrainerflag TRAINER_CINDY_1
	cleartrainerflag TRAINER_BILLY
	cleartrainerflag TRAINER_JAMES_1
	cleartrainerflag TRAINER_HALEY_1
	return

TrainerReset_Route116_RusturfTunnel:
	cleartrainerflag TRAINER_JOEY
	cleartrainerflag TRAINER_KAREN_1
	cleartrainerflag TRAINER_CLARK
	cleartrainerflag TRAINER_DEVAN
	return

TrainerReset_DewfordGym:
	cleartrainerflag TRAINER_TAKAO
	cleartrainerflag TRAINER_BRENDEN
	cleartrainerflag TRAINER_JOCELYN
	cleartrainerflag TRAINER_LILITH
	cleartrainerflag TRAINER_LAURA
	cleartrainerflag TRAINER_CRISTIAN
	return
