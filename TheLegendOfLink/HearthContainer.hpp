#pragma one
#include "Entity.h"

class HeartContainer : public Entity {
private:
    float healAmount;
public:
    HeartContainer(float amount) : healAmount(amount) {}

    float getHealAmount() const {
        return healAmount;
    }
};