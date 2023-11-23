# pokeemerald Expansion & emerald hope


## what's emerald hope?

hi, this is maddie. emerald hope is my first hack, and is a testing/proving ground for a larger scale hack to come. stay tuned for that c:
it's a medium-scale hack approached from the perspective of a 6v6 singles *and* VGC watcher and player, with the intent to kinda-sorta overhaul pokemon to be a more competitive-friendly and competitively-balanced game. 

since this could be interpreted a multitude of ways, let me be clear; this hack DOES NOT:
- add or remove any types
- remove any status conditions
- remove RNG from damage rolls
- remove other RNG such as secondary effects
- remove critical hits
- remove missing

instead, what it does is rein in the various stacking components of RNG each by a small amount, to create an overall healthier game while still preserving the variance that helps make pokemon unique and interesting on a game-to-game basis. i wanted to meet pokemon at its level, not create a brand new game.

massive changes have been made to ensure the viability of *all* pokemon present in the hack, both in VGC and 6v6 singles; moves, abilities, mechanics such as weather and status effects, the typechart, pokemon learnsets and stats, and certainly more that i'm forgetting right now have been adjusted to make this a reality. 

emerald hope also attempts to make the base game a new and novel experience, focused on the things that i love of pokemon's gameplay the most: battling and catching pokemon. 

level caps have been implemented, and healing items have been *removed entirely, including from enemy trainers.* in their place is the pokevial, so you must use its charges wisely in between pokecenters.
to compound on these changes, resting at a pokecenter will reset the trainers on any routes or dungeons in which you haven't beaten their designated boss. the amount of trainers and challenges presented in each route and dungeon has been reshaped to fit this new approach to progression. QoL items such as ability capsules are provided freely, *as well as providing the PKEX debug menu,* 
so you can focus on exploring the changes made to various mons in the hack, and so you can use this game to easily build teams and battle with your friends. use the debug menu with caution - it's not my fault if you break your game! 

all pokeball's catching odds have been improved to help ease the tedium of catching every single pokemon - which i should note, not *every* pokemon is present in this hack. i'm sorry if your favorites didn't make the cut, but meticulously and creatively balancing *1000* pokemon, let alone implementing all of that in the code to provide those changes in-game, is beyond a monumental task, and i'm just one person working on this hack. emerald hope has a healthy 600-ish mons, so there's still plenty to go round. this number will increase over time, as i do intend to provide more than 1 pokemon for every possible type combination; that will obviously take some time :p

on top of this, the shinies for the majority of pokemon have been changed, and as you catch pokemon, your shiny odds increase! i've done the math on the changes to the shiny calculations and the numbers can get *very* high, so if you want to shiny hunt, catch a lot of stuff! plus, if you reach 500 unique dex entries, the shiny charm provided at the beginning of the game will provide an extra shiny roll!

### emerald hope documentation

since there's so much to go round here, i've made thorough (and ORGANIZED! - i'm no drayano, but i tried to emulate his quality of docs) documentation to reference during your gameplay.

[the folder of emerald hope documentation can be found here](https://drive.google.com/drive/u/0/folders/12nrko1FW_APcU0tTR-l6LHz9aWRCUtZC)

## credits for emerald hope, and using material from it

for credits on spritework, please see the shiny spoiler log.

thank you, of course, to PRET for *decompiling and publicly providing pokemon emerald.* this in the most literal sense could not exist without their work.

thank you dearly to the communities of archie's discord and the RHH discord for both creating the fabulous pokeemerald expansion and comprehensive tutorials for working therein, but also for being so kind, patient, welcoming, and genuinely helpful. y'all are lovely and have only further stoked my passion for creating hacks!

thank you to pokemon sanfran for their incredible implementation of the [pokevial](https://github.com/PokemonSanFran/pokeemerald/wiki/pokevial)

obviously, since i've provided the source code for emerald hope, this is an open source project. if you source from my work, provide credit in your documentation or hack to me, and preferably to the specifics you've drawn from as well, although i certainly won't crucify anyone for not doing that :p

that's all from me. trans rights!

## What is the pokeemerald Expansion?

The pokeemerald Expansion is a feature branch meant to be integrated into existing Pokémon Emerald hacks based off pret's [pokeemerald](https://github.com/pret/pokeemerald) decompilation project. This is ***NOT*** a standalone romhack, and as such, most features will be unavailable and/or unbalanced if played as is.


### [Documentation on features can be found here](https://github.com/rh-hideout/pokeemerald-expansion/wiki)

## If I already have a project based on regular pokeemerald, can I use the pokeemerald Expansion
Yes! Keep in mind that we keep up with pret's documentation of pokeemerald, which means that if your project a bit old, you might get merge conflicts that you need to solve manually.
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH master`.

With this, you'll get the latest version of the Expansion, plus a couple of bugfixes that haven't been released into the next patch version :)

## **How do I update my version of the pokeemerald Expansion?**
- If you haven't set up a remote, run the command `git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion`.
- Once you have your remote set up, run the command `git pull RHH expansion/1.6.0`.

### Please consider crediting the entire [list of contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) in your project, as they have all worked hard to develop this project :)

## There's a bug in the project. How do I let you guys know?
Please submit any issues with the project [here](https://github.com/rh-hideout/pokeemerald-expansion/issues). Make sure that the issue wasn't reported by someone else by searching using the filters.

## Can I contribute even if I'm not a member of ROM Hacking Hideout?

Yes! Contributions are welcome via Pull Requests and they will be reviewed by maintainers. Don't feel discouraged if we take a bit to review your PR, we'll get to it.

## Who maintains the project?

The project was originally started by DizzyEgg alongside other contributors.

The project has now gotten larger and DizzyEgg is now maintaining the project as part of the ROM Hacking Hideout community. Some members of this community are taking on larger roles to help maintain the project.

## What is ROM Hacking Hideout?

A Discord-based ROM hacking community that has many members who hack using the disassembly and decompilation projects for Pokémon. Quite a few contributors to the original feature branches by DizzyEgg were members of ROM Hacking Hideout. You can call it RHH for short!

[Click here to join the RHH Discord Server!](https://discord.gg/6CzjAG6GZk)
