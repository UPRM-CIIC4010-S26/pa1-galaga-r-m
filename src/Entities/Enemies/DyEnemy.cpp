#include "DyEnemy.hpp"


void DyEnemy::draw() {
    if (HitBox::drawHitbox) this->hitBox.draw();
    float y = GetRandomValue(180, 100);// makes the enemy change every frame into new one 
<<<<<<< HEAD
    DrawTexturePro(ImageManager::SpriteSheet, Rectangle{2, y, 13, 14},  
=======
    DrawTexturePro(ImageManager::SpriteSheet, Rectangle{2, y, 13, 14}, 
>>>>>>> f2308efbf7449b34ffb4987455251952dbc5685b
                Rectangle{this->position.first + 15, this->position.second + 15, 30, 30}, 
                Vector2{15, 15}, this->aimAngle, WHITE);
}

void DyEnemy::update(std::pair<float, float> pos, HitBox target) {
    this->cooldown--;

    if (!loop) {
        this->angle += 0.25;
        this->aimAngle += 0.25;
        if (fmod(this->angle, 180) == 0) {
            loop = true;
        }
    } else {
        this->angle += 2;
        this->aimAngle += 2;
        if (fmod(this->angle, 540) == 0) {
            loop = false;
        }
    }

    this->position.first += 3 * cos(angle * M_PI / 180);
    this->position.second += 3 * sin(angle * M_PI / 180);
    this->hitBox.box.x = this->position.first;
    this->hitBox.box.y = this->position.second;

    if (this->cooldown <= 0) {
        Projectile::projectiles.push_back(Projectile(Projectile(position.first + 15, position.second, 1)));
        PlaySound(SoundManager::shoot);
        this->cooldown = GetRandomValue(90, 300);
    }
}

void DyEnemy::attack(HitBox target) { /* Not used */ }