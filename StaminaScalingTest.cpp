// ### STAMINA SCALING TEMPORARY CHANGE

// AFTER: (RESTRICTS TO INTEGERS)

float Player::GetHealthBonusFromStamina()
{
    float stamina = GetStat(STAT_STAMINA);
    int level = GetLevel(); // Assume this function exists to get the player's level

    if (stamina >= 10)
    {
        int effectiveStamina = static_cast<int>(stamina - 10); // Calculate stamina over 10 and cast to int
        int healthBonus = (effectiveStamina / 2) * level; // Each 2 stamina over 10 gives 1 health point per level
        return static_cast<float>(healthBonus); // Return as float
    }
    else
    {
        int missingStamina = static_cast<int>(10 - stamina); // Calculate stamina below 10 and cast to int
        int healthPenalty = (missingStamina / 2) * level; // Each 2 stamina below 10 loses 1 health point per level
        return static_cast<float>(-healthPenalty); // Return as float
    }
}

// BEFOREv2: (INCLUDES FLOATS, NOT FOLLOWING GAME RULING)

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

// BEFOREv1: (BASE GAME)

float Player::GetHealthBonusFromStamina()
{
    float stamina = GetStat(STAT_STAMINA);

    float baseStam = stamina < 20 ? stamina : 20;
    float moreStam = stamina - baseStam;

    return baseStam + (moreStam * 10.0f);
}
