
#include "gtest/gtest.h"

#include "../Druid.h"


TEST(Hero, takeDamage){
    auto druid=new Druid();
    druid->TakeDamage(5);
    EXPECT_EQ(druid->getHp(),5);
}

TEST(Hero, Dead){
    auto druid=new Druid();
    druid->TakeDamage(druid->getHp());
    EXPECT_EQ(druid->IsDead(),true);
}
TEST(Hero, UpgradeWithTool){
    auto druid=new Druid();
    auto torso=new Tool(0);
    torso->setRarity(1);
    druid->Upgrade(torso);
    druid->setTorso(torso);
    EXPECT_EQ(druid->getMaxHp(),25);
}

TEST(Hero, UpgradeWithTool2){
    auto druid=new Druid();
    auto shoes=new Tool(1);
    shoes->setRarity(1);
    druid->Upgrade(shoes);
    druid->setShoes(shoes);
    EXPECT_EQ(druid->getStamina(),7);
}

TEST(Hero, UpgradeWithTool3){
    auto druid=new Druid();
    auto ring=new Tool(2);
    ring->setRarity(1);
    druid->Upgrade(ring);
    druid->setRing(ring);
    EXPECT_EQ(druid->getRing(),ring);
}

TEST(Hero, AttackAnimation){
    auto druid=new Druid();
    druid->AttackAnimation();
    EXPECT_EQ(druid->getCountAttack(),1);
}

TEST(Hero, StatUp){
    auto druid=new Druid();
    druid->UpgradeStat(0);
    EXPECT_EQ(druid->getMaxHp(),25);
}

TEST(Hero, DamageCalculation){
    auto druid=new Druid();
    druid->setAttack(0);
    druid->setPingHit(10);
    EXPECT_EQ(druid->Attack(),30);
}