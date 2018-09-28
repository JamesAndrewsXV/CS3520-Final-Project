# CS3520 Final Project

## Group Information
### Group Name
Four Right Turns
### Group Members
William Epstein, Glenna Greer, Jasmine Chapin and James Andrews

### Basic Description
Turn based combat game where the player goes through an area clearing it of enemies and using loot you “find” along the way to help clear the dungeon. The rooms, enemies, and loot will be randomly generated.
## Mechanics
### Combat Mechanic
Combat mechanics are fighting the enemy, using items, and fights are based around using the items that will be more effective against the enemies you are fighting. Other fighting mechanics include health, % chance to hit, and damage with associated type. Items have inherent stat bonuses and abilities that give the player different options in combat. For example, all characters have the punch ability, but acquiring a sword gives them a slash attack.
### Movement out of Combat
Movement will be simplistic in a snapshot format, allowing players, outside of combat, to go from scene to scene with each room being one such scene. Each time a player enters a room, they can choose to either search for loot, go to another room or if there is a monster in the room, they’re immediately thrust into combat mode. There is a percent chance that looting a room could cause the player to be attacked by a hidden monster or affected by a trap even after they’ve fought an enemy.

### Bossfight mechanics
These dungeon crawling situations end in a boss room, in which the player must use their gathered items and weapon swapping as strategically as possible. Certain items cause a boss to get in a weakened state, for example, where other items become more effective in that vulnerable state. Fighting a dragon boss for instance might require the player to use bows and arrows to weaken it first, then try to swap to and finish it with a sword in the time that it’s weak.

### Similarities to Other Games
This would be similar to games like pokemon and Final Fantasy in terms of combat, with room traversal similar to a visual novel.

## Class Organization

### Player
The player class will have private variables like health, basic stats, and a vector of Items (inventory) and a vector of items (equipped, these are the ones that give you buffs).

### Items
The items will have their own class and have their own attributes which could include buffs to health, stats, damage, etc. They also will impart abilities to the player, these will be stored in their own vector.

### Enemies
Enemies will be represented in a similar fashion to the player, however they will only have the basic combat statistics and not any item lists. The loot after combat will be randomized as treasure the player finds.
### Rooms
Rooms will be randomly generated and connected. Each room with have the option for 4 connecting rooms, encounter in the room (whether there is an enemy or not), and possible loot in that room (a loot modifier if the battle is particularly powerful).
### Map
Map is a class that contains a list of linked rooms. It will also contain the player’s location, a starting room, and an ending (boss) room. All other rooms would be randomly generated, both positionally and what they contain.

## Milestones + Schedule
### Milestone One:
- [ ] Player implementation
- [ ]  Room/Map generation
- [ ] Basic Monster placement
- [ ] Loot generation + kinds of loot (optional)
- [ ] Combat
### Milestone Two:
- [ ] Basic combat UI
- [ ] Fighting options, items, changing equipment, health, etc
- [ ] Monster mechanics (optional)
- [ ] Strengths, weaknesses, randomization, implement bosses
- [ ] Traversal UI + character UI 
- [ ] Room traversal
### Milestone Three:
- [ ] Complete combat UI
- [ ] Complete rest of UI
- [ ] Traversal, character, etc
- [ ] Going through multiple levels in the dungeon
- [ ] Losing items (getting to keep some)
- [ ] Implement difficulty settings (optional)
- [ ] Harder = keep fewer items, enemies are more difficult, etc.

