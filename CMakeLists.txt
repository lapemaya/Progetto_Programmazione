cmake_minimum_required(VERSION 3.22)
project(gioco2)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio system system network window REQUIRED)

add_executable(gioco2 main.cpp StateMachine.cpp StateMachine.h State.h Game.cpp Game.h MainMenuState.cpp MainMenuState.h InputManager.cpp InputManager.h ClassMenuState.cpp ClassMenuState.h Knight.cpp Knight.h Hero.cpp Hero.h Tool.cpp Tool.h SpecialTool.cpp SpecialTool.h AttackMenuState.cpp AttackMenuState.h Enemy.cpp Enemy.h Goblin.cpp Goblin.h Dragon.cpp Dragon.h Fireball.cpp Fireball.h Rat.cpp Rat.h PingState.cpp PingState.h Ping.cpp Ping.h HeroAttackState.cpp HeroAttackState.h EnemyAttackState.cpp EnemyAttackState.h DedState.cpp DedState.h LootState.cpp LootState.h  ShopState.cpp ShopState.h  StatState.cpp StatState.h HeroCheckState.cpp HeroCheckState.h HowMenu.cpp HowMenu.h HowState.cpp HowState.h ToolFactory.cpp ToolFactory.h ToolInterface.cpp ToolInterface.h Mage.cpp Mage.h Druid.cpp Druid.h Menu.cpp Menu.h )

target_link_libraries(gioco2 sfml-graphics sfml-audio  sfml-system sfml-network sfml-window)

add_subdirectory(test)
