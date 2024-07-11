### STAMINA SCALING TEMPORARY CHANGE
AFTER

float Player::GetHealthBonusFromStamina()
{
    float stamina = GetStat(STAT_STAMINA);
    int level = GetLevel(); // Assume this function exists to get the player's level

    if (stamina >= 10)
    {
        float effectiveStamina = stamina - 10; // Calculate stamina over 10
        float healthBonus = (effectiveStamina / 2.0f) * level; // Each 2 stamina over 10 gives 1 health point per level
        return healthBonus;
    }
    else
    {
        float missingStamina = 10 - stamina; // Calculate stamina below 10
        float healthPenalty = (missingStamina / 2.0f) * level; // Each 2 stamina below 10 loses 1 health point per level
        return -healthPenalty;
    }
}


BEFORE:

float Player::GetHealthBonusFromStamina()
{
    float stamina = GetStat(STAT_STAMINA);

    float baseStam = stamina < 20 ? stamina : 20;
    float moreStam = stamina - baseStam;

    return baseStam + (moreStam * 10.0f);
}
