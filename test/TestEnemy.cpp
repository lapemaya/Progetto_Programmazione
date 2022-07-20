#include "gtest/gtest.h"

#include "../Enemy.h"
#include "../Rat.h"


TEST(Enemy, takeDamage){
    auto rat=new Rat(1);
    rat->TakeDamage(5);
    EXPECT_EQ(rat->getHp(),25);
}

TEST(Enemy, Dead){
    auto rat=new Rat(1);
    rat->TakeDamage(15);
    rat->TakeDamage(10);
    rat->TakeDamage(5);
    EXPECT_EQ(rat->IsDead(),true);
}
