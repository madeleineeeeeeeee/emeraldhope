Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVEDROPE, Route106_EventScript_ExplainEscapeRope
	msgbox Route106_Text_GiveEscapeRope, MSGBOX_DEFAULT
	setflag FLAG_RECEIVEDROPE
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_ESCAPE_ROPE
	waitfanfare
	msgbox Route106_Text_ExplainEscapeRope, MSGBOX_AUTOCLOSE
	waitmessage
	releaseall
	end

Route106_EventScript_ExplainEscapeRope::
	msgbox Route106_Text_ExplainEscapeRope, MSGBOX_DEFAULT
	releaseall
	end


Route106_Text_TrainerTips:
	.string "Trainer Tips\p"
	.string "Advice on catching Pokémon with a Rod:\n"
	.string "Press the A Button if you get a bite.$"

Route106_Text_ExplainEscapeRope:
	.string "That's an Escape Rope; using it will\n"
	.string "immediately return you to the entrace\l"
	.string "of a dungeon.\p"
	.string "You can use it as many times as you need.\n"
	.string "Always make sure to be prepared!$"

Route106_Text_GiveEscapeRope:
	.string "Woah there trainer!\p"
	.string "Something about you tells me you're\n"
	.string "new to caving.\p"
	.string "Well if that's the case, then please,\n"
	.string "take one of these.$"
