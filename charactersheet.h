#ifndef CHARACTERSHEET_H
#define CHARACTERSHEET_H

#include <QString>
#include <Qmap>
#include <QVector>

class CharacterSheet
{

public:
    CharacterSheet();

    QString concatPlus(QString text);
    QString concatPlus(int text);
    QString calculateAbilityModifier(QString abilityScore);
    QString calculateProficiency(QString charLevel);
    QString calculateSave(QString modifier);
    void updateSkillsSaves(QString save);
    void initializeModifierTable();
    void initializeProficiencyTable();
    void initializeSkillTypesTable();

private:
    std::map<int, int> mModifierTable;
    std::map<int, int> mProficiencyTable;
    std::map<QString, QString>mSkillsTable;

public:
    //Getters and Setters for CharacterSheet
    //Getters
    QString getCharName();
    QString getCharClass();
    QString getLevel();
    QString getCharBackground();
    QString getPlayerName();
    QString getCharRace();
    QString getCharAlignment();
    QString getCharSize();

    QString getArmorClass();
    QString getInitiative();
    QString getSpeed();
    QString getExperience();
    QString getMaximumHP();
    QString getCurrentHP();
    QString getHitDiceType();
    QString getHitDiceNumber();
    QString getSpellAttackBonus();
    QString getSpellSaveDC();

    QString getProficiency();
    QString getStrength();
    QString getDexterity();
    QString getConstitution();
    QString getIntelligence();
    QString getWisdom();
    QString getCharisma();

    QString getStrMod();
    QString getDexMod();
    QString getConMod();
    QString getIntMod();
    QString getWisMod();
    QString getChaMod();

    QString getStrSave();
    QString getDexSave();
    QString getConSave();
    QString getIntSave();
    QString getWisSave();
    QString getChaSave();

    QString getAcrobatics();
    QString getAnimalHandling();
    QString getArcana();
    QString getAthletics();
    QString getDeception();
    QString getHistory();
    QString getInsight();
    QString getIntimidation();
    QString getInvestigation();
    QString getMedicine();
    QString getNature();
    QString getPerception();
    QString getPerformance();
    QString getPersuasion();
    QString getReligion();
    QString getSleightOfHand();
    QString getStealth();
    QString getSurvival();

    // Setters
    void setCharName(QString cName);
    void setCharClass(QString cClass);
    void setLevel(QString level);
    void setCharBackground(QString background);
    void setPlayerName(QString pName);
    void setCharRace(QString race);
    void setCharAlignment(QString alignment);
    void setCharSize(QString size);

    void setArmorClass(QString armor);
    void setInitiative(QString initiative);
    void setSpeed(QString speed);
    void setExperience(QString experience);
    void setMaximumHP(QString maximumHP);
    void setCurrentHP(QString currentHP);
    void setHitDiceType(QString hitDiceType);
    void setHitDiceNumber(QString hitDiceNumber);
    void setSpellAttackBonus(QString spellAttackBonus);
    void setSpellSaveDC(QString spellSaveDC);

    void setProficiency(QString proficiency);
    void setStrength(QString strength);
    void setDexterity(QString dexterity);
    void setConstitution(QString constitution);
    void setIntelligence(QString intelligence);
    void setWisdom(QString wisdom);
    void setCharisma(QString charisma);

    void setStrMod(QString strSave);
    void setDexMod(QString dexSave);
    void setConMod(QString conSave);
    void setIntMod(QString intSave);
    void setWisMod(QString wisSave);
    void setChaMod(QString chaSave);

    void setStrSave(QString strSave);
    void setDexSave(QString dexSave);
    void setConSave(QString conSave);
    void setIntSave(QString intSave);
    void setWisSave(QString wisSave);
    void setChaSave(QString chaSave);

    void setAcrobatics(QString acrobatics);
    void setAnimalHandling(QString animalHandling);
    void setArcana(QString arcana);
    void setAthletics(QString athletics);
    void setDeception(QString deception);
    void setHistory(QString history);
    void setInsight(QString insight);
    void setIntimidation(QString intimidation);
    void setInvestigation(QString investigation);
    void setMedicine(QString medicine);
    void setNature(QString nature);
    void setPerception(QString perception);
    void setPerformance(QString performance);
    void setPersuasion(QString persuasion);
    void setReligion(QString religion);
    void setSleightOfHand(QString sleightOfHand);
    void setStealth(QString stealth);
    void setSurvival(QString survival);

private:

    QString mCharName = "Character Name";
    QString mCharClass = "Unassigned";
    QString mCharLevel = "1";
    QString mCharBackground = "Unassigned";
    QString mPlayerName = "Player Name";
    QString mCharRace = "Unassigned";
    QString mCharAlignment = "Unassigned";
    QString mCharSize = "Medium";

    QString mArmorClass = "10";
    QString mInitiative = "0";
    QString mSpeed = "30";
    QString mExperience = "0";
    QString mMaximumHP = "";
    QString mCurrentHP = "";
    QString mHitDiceType = "1dX";
    QString mHitDiceNumber = "1";
    QString mSpellAttackBonus = "0";
    QString mSpellSaveDC = "9";

    QString mProficiency = "+2";
    QString mStrength = "10";
    QString mDexterity = "10";
    QString mConstitution = "10";
    QString mIntelligence = "10";
    QString mWisdom = "10";
    QString mCharisma = "10";

    QString mStrMod = "+0";
    QString mDexMod = "+0";
    QString mConMod = "+0";
    QString mIntMod = "+0";
    QString mWisMod = "+0";
    QString mChaMod = "+0";

    QString mStrSave = "+0";
    QString mDexSave = "+0";
    QString mConSave = "+0";
    QString mIntSave = "+0";
    QString mWisSave = "+0";
    QString mChaSave = "+0";

    QString mAcrobatics = "+0";
    QString mAnimalHandling = "+0";
    QString mArcana = "+0";
    QString mAthletics = "+0";
    QString mDeception = "+0";
    QString mHistory = "+0";
    QString mInsight = "+0";
    QString mIntimidation = "+0";
    QString mInvestigation = "+0";
    QString mMedicine = "+0";
    QString mNature = "+0";
    QString mPerception = "+0";
    QString mPerformance = "+0";
    QString mPersuasion = "+0";
    QString mReligion = "+0";
    QString mSleightOfHand = "+0";
    QString mStealth = "+0";
    QString mSurvival = "+0";
};

#endif // CHARACTERSHEET_H
