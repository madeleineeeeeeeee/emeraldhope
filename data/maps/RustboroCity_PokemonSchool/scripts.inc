RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_Confusion
	case 6, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end


RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Confusion::
	msgbox RustboroCity_PokemonSchool_Text_ExplainConfusion, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Hiker::
	msgbox RustboroCity_PokemonSchool_Text_Hiker, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_AquaMember::
	msgbox RustboroCity_PokemonSchool_Text_AquaMember, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_MagmaMember::
	msgbox RustboroCity_PokemonSchool_Text_MagmaMember, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_LEFTOVERS
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "The blackboard lists status changes\n"
	.string "that may affect Pokémon in battle.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Which topic do you want to read?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "If a Pokémon is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned Pokémon' recovers half\n"
	.string "the HP it normally would.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "If a Pokémon becomes paralyzed,\n"
	.string "its Speed drops significantly.\p"
	.string "If it tries to use priority moves\n"
	.string "such as Protect or Aerial Ace,\l"
	.string "they will fail without a doubt.\p"
	.string "Paralysis remains after battle.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "If a Pokémon falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "A Pokémon may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Only one Pokémon may be asleep\n"
	.string "at a time.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "A burn reduces Attack, and it\n"
	.string "steadily reduces the victim's HP.\p"
	.string "A burn lingers after battle.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "If a Pokémon is frostbitten, its\n"
	.string "Special Attack is reduced.\p"
	.string "It steadily takes damage each turn\n"
	.string "and takes even more in Snow.\p"
	.string "Frostbite lingers after battle.$"

	RustboroCity_PokemonSchool_Text_ExplainConfusion:
	.string "When a Pokémon is confused, it\n"
	.string "will hurt itself each time it\l"
	.string "attacks, but at least the attack\l"
	.string "doesn't fail when this happens!\p"
	.string "Confusion goes away once the\n"
	.string "affected Pokémon is no longer in\l"
	.string "in battle.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Students who don't study get a little\n"
	.string "taste of my Leftovers Snorlax.\p"
	.string "Whether or not you are a good student \n"
	.string "will be evident from the way you use\l"
	.string "this item.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "A Pokémon holding Leftovers will\n"
	.string "heal a small amount at the end of\l"
	.string "every turn.\p"
	.string "There are many other items that are\n"
	.string "meant to be held by Pokémon.\p"
	.string "meant to be held by Pokémon.\p"
	.string "Just those alone will give you many\n"
	.string "topics to study!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "I'm trading Pokémon with my friend\n"
	.string "right now.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "I always wanted a SEEDOT, and\n"
	.string "I'm finally getting one!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Pokémon will grow more if you put\n"
	.string "in extra effort with them!\p"
	.string "My textbook has the number 636\n"
	.string "in it on that page, but someone\l"
	.string "scribbled all over the pages\l"
	.string "so I don't know what it means!$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "You know how some Pokémon moves can\n"
	.string "land a critical hit?\p"
	.string "Critical hits do extra damage, but\n"
	.string "they seem to happen very rarely.\p"
	.string "But some moves will always land a\n"
	.string "critical hit!\l"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "A Pokémon holding a Berry will heal\n"
	.string "itself…\p"
	.string "There are many kinds of items that\n"
	.string "Pokémon can hold…\p"
	.string "Boy, it sure is hard taking notes\n"
	.string "down…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "It's a student's notebook…\p"
	.string "Pokémon are to be caught using\n"
	.string "Poké Balls.\p"
	.string "Up to six Pokémon can accompany\n"
	.string "a Trainer.\p"
	.string "A Trainer is someone who catches\n"
	.string "Pokémon, raises them, and battles\l"
	.string "with them.\p"
	.string "A Trainer's mission is to defeat\n"
	.string "the strong Trainers who await\l"
	.string "challengers in Pokémon Gyms.\p"
	.string "If you leave a Gym to heal at\n"
	.string "a Pokémon Center, the trainers\l"
	.string "will heal too!$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hello? Didn't we meet before?\n"
	.string "I think back in Petalburg City.\p"
	.string "Let me introduce myself.\n"
	.string "My name's Scott.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding Trainers.\p"
	.string "More specifically, I'm looking for\n"
	.string "Pokémon battle experts.\p"
	.string "So, what brings you to this School?\n"
	.string "Are you a Trainer, too?\p"
	.string "The first thing you should do is to\n"
	.string "get the Cut HM.\p"
	.string "So long as you have the appropriate\n"
	.string "Badge, you can use HMs outside of\l"
	.string "battle, even if none of the Pokémon\l"
	.string "in your party know the move.\p"
	.string "If I remember correctly, someone in\n"
	.string "this town has Cut.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "Scott: Hmm…\p"
	.string "The talent levels of the students here\n"
	.string "are unknown. The potential's there.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "Scott: Oh, what's that?\p"
	.string "It's a Stone Badge, isn't it?\n"
	.string "That's pretty impressive, I'd say.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a Trainer from a League Badge.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hello? Didn't we meet before?\n"
	.string "I think back in Petalburg City.\p"
	.string "Let me introduce myself.\n"
	.string "My name's Scott.\p"
	.string "I've been traveling everywhere in\n"
	.string "search of outstanding Trainers.\p"
	.string "More specifically, I'm looking for\n"
	.string "Pokémon battle experts.\p"
	.string "Oh, what's that?\n"
	.string "It's a Stone Badge, isn't it?\p"
	.string "That's pretty impressive, I'd say, for\n"
	.string "a starting Trainer like yourself.\p"
	.string "But, you know, I would've loved to see\n"
	.string "you in battle.\p"
	.string "It's hard to tell what you're like as\n"
	.string "a Trainer from a League Badge.$"

RustboroCity_PokemonSchool_Text_AquaMember:
	.string "Grunt: My boss sent me to\n"
	.string "study because I can't win any\l"
	.string "Pokémon battles…\p"
	.string "How was I supposed to know that\n"
	.string "my attacks weren't boosted by\l"
	.string "weather anymore!$"

RustboroCity_PokemonSchool_Text_MagmaMember:
	.string "Grunt: My boss sent me to\n"
	.string "study because I keep losing\l"
	.string "Pokémon battles…\p"
	.string "It says here that weather lasts\n"
	.string "forever, but when I was trying to\l"
	.string "steal that guy's Pokémon, he sent\l"
	.string "out his Pokémon and it completely\l"
	.string "cleared away my weather!$"


RustboroCity_PokemonSchool_Text_Hiker:
	.string "Hiker: I came to tell the teacher\n"
	.string "about a new kind of weather I saw\l"
	.string "up in the mountains.\p"
	.string "It stopped hailing up there, and now\n"
	.string "it's started snowing!\p"
	.string "It was healing my Ice Type Pokémon\n"
	.string "and hurting my Pokémon weak to Ice.\p"
	.string "My poor Cranidos got Frostbite\n"
	.string "and was taking double the damage\l"
	.string "from the Frostbite!$"
