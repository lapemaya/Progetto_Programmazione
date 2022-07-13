project(test)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Game_test test_main.cpp TestHero.cpp ../Druid.cpp ../Druid.h ../Hero.cpp ../Hero.h ../Tool.cpp ../Tool.h ../SpecialTool.cpp ../SpecialTool.h TestEnemy.cpp ../Rat.cpp ../Rat.h ../Enemy.cpp ../Enemy.h)

target_link_libraries(Game_test gtest gtest_main sfml-graphics sfml-audio  sfml-system sfml-network sfml-window )


