RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	lockall
	faceplayer
	goto_if_unset FLAG_UPGRADE_MAN, RustboroCity_Flat2_3F_EventScript_GiveUpgrade
	msgbox RustboroCity_Flat2_3F_UpgradeMan, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_3F_EventScript_GiveUpgrade::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_DEFAULT
	giveitem ITEM_UPGRADE
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	setflag FLAG_UPGRADE_MAN
	return
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones: @ 8216129
	.string "I was tasked with reverse engineering\n"
	.string "this interesting disc.\p"
	.string "Unfortunately, I'm completely stumped.\p"
	.string "I'm too embarrassed to tell them,\n"
	.string "please take it off my hands!$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones: @ 8216159
	.string "Devon's President likes to collect\n"
	.string "rare stones.\p"
	.string "I think the President's son also\n"
	.string "collects rare stones.$"

RustboroCity_Flat2_3F_UpgradeMan:
	.string "This exchange never happened.$"
