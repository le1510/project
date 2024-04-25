#pragma once // file hp

#include "../Config.hpp"
#include "../components/Damage.hpp"
#include "AnimatedObject.hpp"
#include "Gun.hpp"
#include "Bullet.hpp"
#include "../components/HP.hpp"

class Player final : public AnimatedObject, public Damage, public HP {
private:
    int m_speed;
    Gun* m_gun;
    bool m_isShotable;
    float m_elapsedTime;
    float m_scale;
    SDL_Rect m_totalHP;
    SDL_Rect m_currentHP;
    int m_totalAmmo;
    int m_currentAmmo;
    int m_maxAmmo;
    int m_shotsFired;
    std::vector<Bullet*> m_bullets;
     float m_healTime;
    float m_timeSinceLastHeal;
    int m_healAmount;

public:
    Player();
    ~Player() = default;

    void Update(float) override;
    void Render(SDL_Renderer*) override;
    void SetMaxAmmo(int maxAmmo) { m_maxAmmo = maxAmmo; }
    void UpdateAmmo(int ammo) { m_currentAmmo = ammo; }
    void UpdateShotsFired(int shotsFired) { m_shotsFired = shotsFired; }
    void DecreaseBulletDamage(int amount);
    bool IsShotable() const;
    Bullet* Shot();
    void Scale(float scaleFactor);
    float GetScale() const;
    void Heal(int amount, float delta);

};
