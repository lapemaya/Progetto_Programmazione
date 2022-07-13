#include "gtest/gtest.h"

#include "../Enemy.h"
#include "../Rat.h"


TEST(Enemy, takeDamage){
    auto rat=new Rat(1);
    rat->takeDamage(5);
    EXPECT_EQ(rat->getHp(),25);
}

TEST(Enemy, Dead){
    auto rat=new Rat(1);
    rat->takeDamage(rat->getHp());
    EXPECT_EQ(rat->isDead(),true);
}
