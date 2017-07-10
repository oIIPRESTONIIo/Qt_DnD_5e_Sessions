#include "charactersheet.h"

CharacterSheet::CharacterSheet()
{
    initializeModifierTable();
    initializeProficiencyTable();
}

QString CharacterSheet::concatPlus(QString text) {

    QString concat = "+" + text;

    return concat;
}

QString CharacterSheet::concatPlus(int text) {

    QString concat = "+" + QString::number(text);

    return concat;
}

void CharacterSheet::initializeProficiencyTable() {

    for(int x = 1; x <= 30; x++){
        if (x < 5) {
            mProficiencyTable.emplace(x, 2);
        }
        else if (x < 9) {
            mProficiencyTable.emplace(x, 3);
        }
        else if (x < 13) {
            mProficiencyTable.emplace(x, 4);
        }
        else if (x < 17) {
            mProficiencyTable.emplace(x, 5);
        }
        else {
            mProficiencyTable.emplace(x, 6);
        }
    }
}

void CharacterSheet::initializeModifierTable() {

    int y = -5;

    for(int x = 0; x <= 20; x++){
        if (x == 0) {
            mModifierTable.emplace(x, -5);
        }
        else if ((x % 2) == 0) {
            mModifierTable.emplace(x, ++y);
        }
        else {
            mModifierTable.emplace(x, y);
        }
    }
}

void CharacterSheet::initializeSkillTypesTable() {
    std::vector<QString> skills {"Acrobatics", "AnimalHandling", "Arcana", "Athletics", "Deception",
          "History", "Insight", "Investigation", "Medicine", "Nature", "Perception",
          "Performance", "Persuasion", "Religion", "SleightOfHand", "Stealth", "Survival"};

    std::vector<QString> types {"Str", "Dex", "Con", "Int", "Wis", "Cha"};

    mSkillsTable.emplace(skills[0], types[1]);
    mSkillsTable.emplace(skills[1], types[4]);
    mSkillsTable.emplace(skills[2], types[3]);
    mSkillsTable.emplace(skills[3], types[0]);
    mSkillsTable.emplace(skills[4], types[5]);
    mSkillsTable.emplace(skills[5], types[3]);
    mSkillsTable.emplace(skills[6], types[4]);
    mSkillsTable.emplace(skills[7], types[5]);
    mSkillsTable.emplace(skills[8], types[3]);
    mSkillsTable.emplace(skills[9], types[4]);
    mSkillsTable.emplace(skills[10], types[3]);
    mSkillsTable.emplace(skills[11], types[4]);
    mSkillsTable.emplace(skills[12], types[5]);
    mSkillsTable.emplace(skills[13], types[5]);
    mSkillsTable.emplace(skills[14], types[3]);
    mSkillsTable.emplace(skills[15], types[1]);
    mSkillsTable.emplace(skills[16], types[1]);
    mSkillsTable.emplace(skills[17], types[4]);
}


QString CharacterSheet::calculateAbilityModifier(QString abilityScore) {

    int modifier = mModifierTable[abilityScore.toInt()];

    if (modifier >= 10) {
        return concatPlus(QString::number(modifier));
    }
    else {
        return QString::number(modifier);
    }
}

 QString CharacterSheet::calculateProficiency(QString charLevel) {

     int proficiency = mProficiencyTable[charLevel.toInt()];

     return concatPlus(QString::number(proficiency));
 }

QString CharacterSheet::calculateSave(QString modifier) {

     int Save = modifier.toInt() + getProficiency().toInt();

     return QString::number(Save);
 }

void CharacterSheet::updateSkillsSaves(QString save){

    int proficiency = getProficiency().toInt();

    int strMod = proficiency + getStrMod().toInt();
    int dexMod = proficiency + getDexMod().toInt();
    int conMod = proficiency + getConMod().toInt();
    int intMod = proficiency + getIntMod().toInt();
    int wisMod = proficiency + getWisMod().toInt();
    int chaMod = proficiency + getChaMod().toInt();
}

// CharacterSheet Getters and Setters

QString CharacterSheet::getCharName(){
    return mCharName;
}

QString CharacterSheet::getCharClass(){
    return mCharClass;
}

QString CharacterSheet::getLevel(){
    return mCharLevel;
}

QString CharacterSheet::getCharBackground(){
    return mCharBackground;
}

QString CharacterSheet::getPlayerName(){
    return mPlayerName;
}

QString CharacterSheet::getCharRace(){
    return mCharRace;
}

QString CharacterSheet::getCharAlignment(){
    return mCharAlignment;
}

QString CharacterSheet::getCharSize(){
    return mCharSize;
}

QString CharacterSheet::getArmorClass(){
    return mArmorClass;
}

QString CharacterSheet::getInitiative(){
    return mInitiative;
}

QString CharacterSheet::getSpeed(){
    return mSpeed;
}

QString CharacterSheet::getExperience(){
    return mExperience;
}

QString CharacterSheet::getMaximumHP(){
    return mMaximumHP;
}

QString CharacterSheet::getCurrentHP(){
    return mCurrentHP;
}

QString CharacterSheet::getHitDiceType(){
    return mHitDiceType;
}

QString CharacterSheet::getHitDiceNumber(){
    return mHitDiceNumber;
}

QString CharacterSheet::getSpellAttackBonus(){
    return mSpellAttackBonus;
}

QString CharacterSheet::getSpellSaveDC(){
    return mSpellSaveDC;
}

QString CharacterSheet::getProficiency(){
    return mProficiency;
}

QString CharacterSheet::getStrength(){
    return mStrength;
}

QString CharacterSheet::getDexterity(){
    return mDexterity;
}

QString CharacterSheet::getConstitution(){
    return mConstitution;
}

QString CharacterSheet::getIntelligence(){
    return mIntelligence;
}

QString CharacterSheet::getWisdom(){
    return mWisdom;
}

QString CharacterSheet::getCharisma(){
    return mCharisma;
}

QString CharacterSheet::getStrMod(){
    return mStrMod;
}

QString CharacterSheet::getDexMod(){
    return mDexMod;
}

QString CharacterSheet::getConMod(){
    return mConMod;
}

QString CharacterSheet::getIntMod(){
    return mIntMod;
}

QString CharacterSheet::getWisMod(){
    return mWisMod;
}

QString CharacterSheet::getChaMod(){
    return mChaMod;
}

QString CharacterSheet::getStrSave(){
    return mStrSave;
}

QString CharacterSheet::getDexSave(){
    return mDexSave;
}

QString CharacterSheet::getConSave(){
    return mConSave;
}

QString CharacterSheet::getIntSave(){
    return mIntSave;
}

QString CharacterSheet::getWisSave(){
    return mWisSave;
}

QString CharacterSheet::getChaSave(){
    return mChaSave;
}

QString CharacterSheet::getAcrobatics(){
    return mAcrobatics;
}

QString CharacterSheet::getAnimalHandling(){
    return mAnimalHandling;
}

QString CharacterSheet::getArcana(){
    return mArcana;
}

QString CharacterSheet::getAthletics(){
    return mAthletics;
}

QString CharacterSheet::getDeception(){
    return mDeception;
}

QString CharacterSheet::getHistory(){
    return mHistory;
}

QString CharacterSheet::getInsight(){
    return mInsight;
}

QString CharacterSheet::getIntimidation(){
  return mIntimidation;
}

QString CharacterSheet::getInvestigation(){
    return mInvestigation;
}

QString CharacterSheet::getMedicine(){
    return mMedicine;
}

QString CharacterSheet::getNature(){
    return mNature;
}

QString CharacterSheet::getPerception(){
    return mPerception;
}

QString CharacterSheet::getPerformance(){
    return mPerformance;
}

QString CharacterSheet::getPersuasion(){
    return mPersuasion;
}

QString CharacterSheet::getReligion(){
    return mReligion;
}

QString CharacterSheet::getSleightOfHand(){
    return mSleightOfHand;
}

QString CharacterSheet::getStealth(){
    return mStealth;
}

QString CharacterSheet::getSurvival(){
    return mSurvival;
}

// Setters
void CharacterSheet::setCharName(QString cName){
    mCharName = cName;
}

void CharacterSheet::setCharClass(QString cClass) {
    mCharClass = cClass;
}

void CharacterSheet::setLevel(QString level){
    mCharLevel = level;
}

void CharacterSheet::setCharBackground(QString background){
    mCharBackground = background;
}

void CharacterSheet::setPlayerName(QString pName){
    mPlayerName = pName;
}

void CharacterSheet::setCharRace(QString race){
    mCharRace = race;
}

void CharacterSheet::setCharAlignment(QString alignment){
    mCharAlignment = alignment;
}

void CharacterSheet::setCharSize(QString size){
    mCharSize = size;
}

void CharacterSheet::setArmorClass(QString armor){
    mArmorClass = armor;
}

void CharacterSheet::setInitiative(QString initiavtive){
    mInitiative = initiavtive;
}

void CharacterSheet::setSpeed(QString speed){
    mSpeed = speed;
}

void CharacterSheet::setExperience(QString experience){
    mExperience = experience;
}

void CharacterSheet::setMaximumHP(QString maximumHP){
    mMaximumHP = maximumHP;
}

void CharacterSheet::setCurrentHP(QString currentHP){
    mCurrentHP = currentHP;
}

void CharacterSheet::setHitDiceType(QString hitDiceType){
    mHitDiceType = hitDiceType;
}

void CharacterSheet::setHitDiceNumber(QString hitDiceNumber){
    mHitDiceNumber = hitDiceNumber;
}

void CharacterSheet::setSpellAttackBonus(QString spellAttackBonus){
    mSpellAttackBonus = spellAttackBonus;
}

void CharacterSheet::setSpellSaveDC(QString spellSaveDC){
    mSpellSaveDC = spellSaveDC;
}

void CharacterSheet::setProficiency(QString proficiency){
    mProficiency = proficiency;
}

// Ability score setters
void CharacterSheet::setStrength(QString strength){
    mStrength = strength;
}

void CharacterSheet::setDexterity(QString dexterity){
    mDexterity = dexterity;
}

void CharacterSheet::setConstitution(QString constitution){
    mConstitution = constitution;
}

void CharacterSheet::setIntelligence(QString intelligence){
    mIntelligence = intelligence;
}

void CharacterSheet::setWisdom(QString wisdom){
    mWisdom = wisdom;
}

void CharacterSheet::setCharisma(QString charisma){
    mCharisma = charisma;
}

void CharacterSheet::setStrMod(QString strMod){
    mStrMod = strMod;
}

void CharacterSheet::setDexMod(QString dexMod){
    mDexMod = dexMod;
}

void CharacterSheet::setConMod(QString conMod){
    mConMod = conMod;
}

void CharacterSheet::setIntMod(QString intMod){
    mIntMod = intMod;
}

void CharacterSheet::setWisMod(QString wisMod){
    mWisMod = wisMod;
}

void CharacterSheet::setChaMod(QString chaMod){
    mChaMod = chaMod;
}

void CharacterSheet::setStrSave(QString strSave){
    mStrSave = strSave;
}

void CharacterSheet::setDexSave(QString dexSave){
    mDexSave = dexSave;
}

void CharacterSheet::setConSave(QString conSave){
    mConSave = conSave;
}

void CharacterSheet::setIntSave(QString intSave){
    mIntSave = intSave;
}

void CharacterSheet::setWisSave(QString wisSave){
    mWisSave = wisSave;
}

void CharacterSheet::setChaSave(QString chaSave){
    mChaSave = chaSave;
}

// Skill Setters
void CharacterSheet::setAcrobatics(QString acrobatics){
    mAcrobatics = acrobatics;
}

void CharacterSheet::setAnimalHandling(QString animalHandling){
    mAnimalHandling = animalHandling;
}

void CharacterSheet::setArcana(QString arcana){
    mArcana = arcana;
}

void CharacterSheet::setAthletics(QString athletics){
    mAthletics = athletics;
}

void CharacterSheet::setDeception(QString deception){
    mDeception = deception;
}

void CharacterSheet::setHistory(QString history){
    mHistory = history;
}

void CharacterSheet::setInsight(QString insight){
    mInsight = insight;
}

void CharacterSheet::setIntimidation(QString intimidation){
  mIntimidation = intimidation;
}

void CharacterSheet::setInvestigation(QString investigation){
    mInvestigation = investigation;
}

void CharacterSheet::setMedicine(QString medicine){
    mMedicine = medicine;
}

void CharacterSheet::setNature(QString nature){
    mNature = nature;
}

void CharacterSheet::setPerception(QString perception){
    mPerception = perception;
}

void CharacterSheet::setPerformance(QString performance){
    mPerformance = performance;
}

void CharacterSheet::setPersuasion(QString persuasion){
    mPersuasion = persuasion;
}

void CharacterSheet::setReligion(QString religion){
    mReligion = religion;
}

void CharacterSheet::setSleightOfHand(QString sleightOfHand){
    mSleightOfHand = sleightOfHand;
}

void CharacterSheet::setStealth(QString stealth){
    mStealth = stealth;
}


void CharacterSheet::setSurvival(QString survival){
    mSurvival = survival;
}
