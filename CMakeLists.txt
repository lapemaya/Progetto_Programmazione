cmake_minimum_required(VERSION 3.22)
project(gioco2)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio system system network window REQUIRED)
add_executable(gioco2 main.cpp StateMachine.cpp StateMachine.h State.h Game.cpp Game.h MainMenuState.cpp MainMenuState.h MainMenu.cpp MainMenu.h Menu.h InputManager.cpp InputManager.h ClassMenuState.cpp ClassMenuState.h ClassMenu.cpp ClassMenu.h Knight.cpp Knight.h Hero.cpp Hero.h Tool.cpp Tool.h Torso.cpp Torso.h Anello.cpp Anello.h Shoes.cpp Shoes.h SpecialTool.cpp SpecialTool.h Sword.cpp Sword.h Wand.cpp Wand.h Nature.cpp Nature.h AttackMenuState.cpp AttackMenuState.h AttackMenu.cpp AttackMenu.h Enemy.cpp Enemy.h Goblin.cpp Goblin.h Dragon.cpp Dragon.h Fireball.cpp Fireball.h Rat.cpp Rat.h PingState.cpp PingState.h NullMenu.cpp NullMenu.h Ping.cpp Ping.h HeroAttackState.cpp HeroAttackState.h EnemyAttackState.cpp EnemyAttackState.h DedState.cpp DedState.h DedMenu.cpp DedMenu.h LootMenu.cpp LootMenu.h LootState.cpp LootState.h)
target_link_libraries(gioco2 sfml-graphics sfml-audio  sfml-system sfml-network sfml-window)