#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactersheet.h"

CharacterSheet Braum;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    editableBoxFormatting();

    platformSetup();

    this->showMaximized();

    saveCharacterSheet(false);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::platformSetup() {

    QSysInfo hostOS;

    int screenHeight = QGuiApplication::primaryScreen()->geometry().height();

    int screenWidth = (screenHeight / 1.777777777777778);

    QString operatingSystem = hostOS.productType();

    if (operatingSystem == "windows") {

        this->setFixedSize(screenWidth, screenHeight - 63);

    }

    else if (operatingSystem == "android") {

        this->setFixedSize(screenWidth, screenHeight * 0.92);

    }

    else if (operatingSystem == "ios") {

        ui->tabWidget_CharacterSheet->setFixedSize(screenWidth, screenHeight * 0.92);

    } else {

        int screenHeight = 1080;

        int screenWidth = (screenHeight / 1.777777777777778);

        this->setFixedSize(screenWidth, screenHeight - 63);

    }
}

void MainWindow::editableBoxFormatting() {

  ui->lineEdit_Proficiency->setValidator(new QIntValidator(2, 6, this));
  ui->lineEdit_StrScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_DexScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_ConScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_IntScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_WisScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_ChaScore->setValidator(new QIntValidator(1, 20, this));
  ui->lineEdit_CharLevel->setValidator(new QIntValidator(1, 30, this));

}

void MainWindow::setLevelBasedBonuses(QString level){

  if (level == QString("")) {
      ui->lineEdit_Proficiency->setText(QString("+2"));
      Braum.setProficiency(QString("+2"));
      setSkillBonuses();
    }
  else {
      QString proficiency = Braum.calculateProficiency(level);
      ui->lineEdit_Proficiency->setText(proficiency);
      Braum.setProficiency(proficiency);
      setSkillBonuses();
    }

  ui->lineEdit_HitDiceMaximum->setText(level);
}

void MainWindow::setSkillBonuses(){

  setStrBonuses();
  setDexBonuses();
  setConBonuses();
  setIntBonuses();
  setWisBonuses();
  setChaBonuses();
  setAttackBonuses();

}

void MainWindow::setAttackBonuses(){

    int proficiency = Braum.getProficiency().toInt();
    int modifier = 0;

    QList<QComboBox*>comboBoxList;

    comboBoxList.append(ui->comboBox_Gov1);
    comboBoxList.append(ui->comboBox_Gov2);
    comboBoxList.append(ui->comboBox_Gov3);
    comboBoxList.append(ui->comboBox_Gov4);
    comboBoxList.append(ui->comboBox_Gov5);
    comboBoxList.append(ui->comboBox_Gov6);
    comboBoxList.append(ui->comboBox_Gov7);
    comboBoxList.append(ui->comboBox_Gov8);
    comboBoxList.append(ui->comboBox_Gov9);
    comboBoxList.append(ui->comboBox_Gov10);

    QList<QLineEdit*>lineEditList;

    lineEditList.append(ui->lineEdit_AttackBonus1);
    lineEditList.append(ui->lineEdit_AttackBonus2);
    lineEditList.append(ui->lineEdit_AttackBonus3);
    lineEditList.append(ui->lineEdit_AttackBonus4);
    lineEditList.append(ui->lineEdit_AttackBonus5);
    lineEditList.append(ui->lineEdit_AttackBonus6);
    lineEditList.append(ui->lineEdit_AttackBonus7);
    lineEditList.append(ui->lineEdit_AttackBonus8);
    lineEditList.append(ui->lineEdit_AttackBonus9);
    lineEditList.append(ui->lineEdit_AttackBonus10);

    QList<QComboBox*>comboBoxAttackProficiency;

    comboBoxAttackProficiency.append(ui->comboBox_Attack1);
    comboBoxAttackProficiency.append(ui->comboBox_Attack2);
    comboBoxAttackProficiency.append(ui->comboBox_Attack3);
    comboBoxAttackProficiency.append(ui->comboBox_Attack4);
    comboBoxAttackProficiency.append(ui->comboBox_Attack5);
    comboBoxAttackProficiency.append(ui->comboBox_Attack6);
    comboBoxAttackProficiency.append(ui->comboBox_Attack7);
    comboBoxAttackProficiency.append(ui->comboBox_Attack8);
    comboBoxAttackProficiency.append(ui->comboBox_Attack9);
    comboBoxAttackProficiency.append(ui->comboBox_Attack10);

    int index = 0;

    foreach (QComboBox *comboBox, comboBoxList) {

        switch(comboBox->currentIndex()) {

        //Blank
        case 0:
            modifier = 0;

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;
        //Strength
        case 1:
            modifier = Braum.getStrMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;

            //Dexterity
        case 2:
            modifier = Braum.getDexMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;

            //Constitution
        case 3:
            modifier = Braum.getConMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;

            //Intelligence
        case 4:
            modifier = Braum.getIntMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;

            //Wisdom
        case 5:
            modifier = Braum.getWisMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;

            //Charisma
        case 6:
            modifier = Braum.getChaMod().toInt();

            if (comboBoxAttackProficiency[index]->currentIndex() == 1){
                int bonus = proficiency + modifier;

                if (bonus >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(bonus));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(bonus));
                    saveItem(comboBox);
                }
            }
            else {
                if (modifier >= 0) {
                    lineEditList[index]->setText(Braum.concatPlus(modifier));
                    saveItem(comboBox);
                }
                else {
                    lineEditList[index]->setText(QString::number(modifier));
                    saveItem(comboBox);
                }
            }
            index++;
            break;
        }
    }
}

void MainWindow::setStrBonuses(){

  //Set Strength Saving Throw Bonus
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getStrMod().toInt();

  if (ui->comboBox_StrSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_StrSave->setText(Braum.concatPlus(bonus));
          Braum.setStrSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_StrSave->setText(QString::number(bonus));
          Braum.setStrSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_StrSave->setText(Braum.concatPlus(modifier));
          Braum.setStrSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_StrSave->setText(QString::number(modifier));
          Braum.setStrSave(QString::number(modifier));
        }
    }

  // Set Athletics Bonus
  if (ui->comboBox_Athletics->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Athletics->setText(Braum.concatPlus(bonus));
          Braum.setStrSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Athletics->setText(QString::number(bonus));
          Braum.setStrSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Athletics->setText(Braum.concatPlus(modifier));
          Braum.setStrSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Athletics->setText(QString::number(modifier));
          Braum.setStrSave(QString::number(modifier));
        }
    }
}

void MainWindow::setDexBonuses(){

  //Set Initiative
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getDexMod().toInt();

  if (modifier >= 0) {
      ui->lineEdit_Initiative->setText(Braum.concatPlus(modifier));
      Braum.setInitiative(Braum.concatPlus(modifier));
    }
  else {
      ui->lineEdit_Initiative->setText(QString::number(modifier));
      Braum.setInitiative(QString::number(modifier));
    }


  //Set Dexterity Saving Throw Bonus
  if (ui->comboBox_DexSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_DexSave->setText(Braum.concatPlus(bonus));
          Braum.setDexSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_DexSave->setText(QString::number(bonus));
          Braum.setDexSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_DexSave->setText(Braum.concatPlus(modifier));
          Braum.setDexSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_DexSave->setText(QString::number(modifier));
          Braum.setDexSave(QString::number(modifier));
        }
    }

  // Set Acrobatics Bonus
  if (ui->comboBox_Acrobatics->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Acrobatics->setText(Braum.concatPlus(bonus));
          Braum.setAcrobatics(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Acrobatics->setText(QString::number(bonus));
          Braum.setAcrobatics(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Acrobatics->setText(Braum.concatPlus(modifier));
          Braum.setAcrobatics(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Acrobatics->setText(QString::number(modifier));
          Braum.setAcrobatics(QString::number(modifier));
        }
    }

  // Set Sleight of Hand Bonus
  if (ui->comboBox_SleightOfHand->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_SleightOfHand->setText(Braum.concatPlus(bonus));
          Braum.setSleightOfHand(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_SleightOfHand->setText(QString::number(bonus));
          Braum.setSleightOfHand(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_SleightOfHand->setText(Braum.concatPlus(modifier));
          Braum.setSleightOfHand(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_SleightOfHand->setText(QString::number(modifier));
          Braum.setSleightOfHand(QString::number(modifier));
        }
    }

  // Set Stealth Bonus
  if (ui->comboBox_Stealth->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Stealth->setText(Braum.concatPlus(bonus));
          Braum.setStealth(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Stealth->setText(QString::number(bonus));
          Braum.setStealth(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Stealth->setText(Braum.concatPlus(modifier));
          Braum.setStealth(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Stealth->setText(QString::number(modifier));
          Braum.setStealth(QString::number(modifier));
        }
    }
}

void MainWindow::setConBonuses() {

  // Constitution Save
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getConMod().toInt();

  if (ui->comboBox_ConSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_ConSave->setText(Braum.concatPlus(bonus));
          Braum.setConSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_ConSave->setText(QString::number(bonus));
          Braum.setConSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_ConSave->setText(Braum.concatPlus(modifier));
          Braum.setConSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_ConSave->setText(QString::number(modifier));
          Braum.setConSave(QString::number(modifier));
        }
    }
}

void MainWindow::setIntBonuses() {

  // Intelligence Save
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getIntMod().toInt();

  if (ui->comboBox_IntSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_IntSave->setText(Braum.concatPlus(bonus));
          Braum.setIntSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_IntSave->setText(QString::number(bonus));
          Braum.setIntSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_IntSave->setText(Braum.concatPlus(modifier));
          Braum.setIntSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_IntSave->setText(QString::number(modifier));
          Braum.setIntSave(QString::number(modifier));
        }
    }

    // Spell Attack Bonus

  if ((modifier + proficiency) >= 0) {
      ui->lineEdit_SpellAttackBonus->setText(Braum.concatPlus(modifier + proficiency));
      Braum.setIntSave(Braum.concatPlus(modifier + proficiency));
    }
  else {

      ui->lineEdit_SpellAttackBonus->setText(QString::number(modifier + proficiency));
      Braum.setSpellAttackBonus(QString::number(modifier + proficiency));
    }



    // Spell Save DC

    ui->lineEdit_SpellSaveDC->setText(QString::number((8 + proficiency) + ui->lineEdit_IntMod->text().toInt()));
    Braum.setSpellSaveDC(QString::number((8 + proficiency) + ui->lineEdit_IntMod->text().toInt()));


  // Arcana Bonus
  if (ui->comboBox_Arcana->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Arcana->setText(Braum.concatPlus(bonus));
          Braum.setArcana(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Arcana->setText(QString::number(bonus));
          Braum.setArcana(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Arcana->setText(Braum.concatPlus(modifier));
          Braum.setArcana(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Arcana->setText(QString::number(modifier));
          Braum.setArcana(QString::number(modifier));
        }
    }

  // History Bonus
  if (ui->comboBox_History->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_History->setText(Braum.concatPlus(bonus));
          Braum.setHistory(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_History->setText(QString::number(bonus));
          Braum.setHistory(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_History->setText(Braum.concatPlus(modifier));
          Braum.setHistory(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_History->setText(QString::number(modifier));
          Braum.setHistory(QString::number(modifier));
        }
    }

  // Investigation Bonus
  if (ui->comboBox_Investigation->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Investigation->setText(Braum.concatPlus(bonus));
          Braum.setInvestigation(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Investigation->setText(QString::number(bonus));
          Braum.setInvestigation(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Investigation->setText(Braum.concatPlus(modifier));
          Braum.setInvestigation(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Investigation->setText(QString::number(modifier));
          Braum.setInvestigation(QString::number(modifier));
        }
    }

  // Nature Bonus
  if (ui->comboBox_Nature->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Nature->setText(Braum.concatPlus(bonus));
          Braum.setNature(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Nature->setText(QString::number(bonus));
          Braum.setNature(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Nature->setText(Braum.concatPlus(modifier));
          Braum.setNature(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Nature->setText(QString::number(modifier));
          Braum.setNature(QString::number(modifier));
        }
    }

  // Religion Bonus
  if (ui->comboBox_Religion->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Religion->setText(Braum.concatPlus(bonus));
          Braum.setReligion(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Religion->setText(QString::number(bonus));
          Braum.setReligion(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Religion->setText(Braum.concatPlus(modifier));
          Braum.setReligion(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Religion->setText(QString::number(modifier));
          Braum.setReligion(QString::number(modifier));
        }
    }
}

void MainWindow::setWisBonuses() {

  // Wisdom Save Bonus
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getWisMod().toInt();

  if (ui->comboBox_WisSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_WisSave->setText(Braum.concatPlus(bonus));
          Braum.setWisSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_WisSave->setText(QString::number(bonus));
          Braum.setWisSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_WisSave->setText(Braum.concatPlus(modifier));
          Braum.setWisSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_WisSave->setText(QString::number(modifier));
          Braum.setWisSave(QString::number(modifier));
        }
    }

  // Animal Handling Bonus
  if (ui->comboBox_AnimalHandling->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_AnimalHandling->setText(Braum.concatPlus(bonus));
          Braum.setReligion(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_AnimalHandling->setText(QString::number(bonus));
          Braum.setAnimalHandling(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_AnimalHandling->setText(Braum.concatPlus(modifier));
          Braum.setAnimalHandling(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_AnimalHandling->setText(QString::number(modifier));
          Braum.setAnimalHandling(QString::number(modifier));
        }
    }

  // Insight Bonus
  if (ui->comboBox_Insight->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Insight->setText(Braum.concatPlus(bonus));
          Braum.setInsight(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Insight->setText(QString::number(bonus));
          Braum.setInsight(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Insight->setText(Braum.concatPlus(modifier));
          Braum.setInsight(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Insight->setText(QString::number(modifier));
          Braum.setInsight(QString::number(modifier));
        }
    }

  // Medicine Bonus
  if (ui->comboBox_Medicine->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Medicine->setText(Braum.concatPlus(bonus));
          Braum.setMedicine(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Medicine->setText(QString::number(bonus));
          Braum.setMedicine(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Medicine->setText(Braum.concatPlus(modifier));
          Braum.setMedicine(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Medicine->setText(QString::number(modifier));
          Braum.setMedicine(QString::number(modifier));
        }
    }

  // Perception Bonus
  if (ui->comboBox_Perception->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Perception->setText(Braum.concatPlus(bonus));
          Braum.setPerception(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Perception->setText(QString::number(bonus));
          Braum.setPerception(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Perception->setText(Braum.concatPlus(modifier));
          Braum.setPerception(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Perception->setText(QString::number(modifier));
          Braum.setPerception(QString::number(modifier));
        }
    }

  // Survival Bonus
  if (ui->comboBox_Survival->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Survival->setText(Braum.concatPlus(bonus));
          Braum.setSurvival(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Survival->setText(QString::number(bonus));
          Braum.setSurvival(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Survival->setText(Braum.concatPlus(modifier));
          Braum.setSurvival(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Survival->setText(QString::number(modifier));
          Braum.setSurvival(QString::number(modifier));
        }
    }
}

void MainWindow::setChaBonuses() {

  // Charisma Save Bonus
  int proficiency = Braum.getProficiency().toInt();
  int modifier = Braum.getChaMod().toInt();

  if (ui->comboBox_ChaSave->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_ChaSave->setText(Braum.concatPlus(bonus));
          Braum.setChaSave(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_ChaSave->setText(QString::number(bonus));
          Braum.setChaSave(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_ChaSave->setText(Braum.concatPlus(modifier));
          Braum.setChaSave(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_ChaSave->setText(QString::number(modifier));
          Braum.setChaSave(QString::number(modifier));
        }
    }

  // Deception Bonus
  if (ui->comboBox_Deception->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Deception->setText(Braum.concatPlus(bonus));
          Braum.setDeception(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Deception->setText(QString::number(bonus));
          Braum.setDeception(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Deception->setText(Braum.concatPlus(modifier));
          Braum.setDeception(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Deception->setText(QString::number(modifier));
          Braum.setDeception(QString::number(modifier));
        }
    }

  // Intimidation Bonus
  if (ui->comboBox_Intimidation->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Intimidation->setText(Braum.concatPlus(bonus));
          Braum.setIntimidation(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Intimidation->setText(QString::number(bonus));
          Braum.setIntimidation(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Intimidation->setText(Braum.concatPlus(modifier));
          Braum.setIntimidation(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Intimidation->setText(QString::number(modifier));
          Braum.setIntimidation(QString::number(modifier));
        }
    }

  // Performance Bonus
  if (ui->comboBox_Performance->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Performance->setText(Braum.concatPlus(bonus));
          Braum.setPerformance(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Performance->setText(QString::number(bonus));
          Braum.setPerformance(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Performance->setText(Braum.concatPlus(modifier));
          Braum.setPerformance(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Performance->setText(QString::number(modifier));
          Braum.setPerformance(QString::number(modifier));
        }
    }

  // Persuasion Bonus
  if (ui->comboBox_Persuasion->currentIndex() == 1){
      int bonus = proficiency + modifier;

      if (bonus >= 0) {
          ui->lineEdit_Persuasion->setText(Braum.concatPlus(bonus));
          Braum.setPersuasion(Braum.concatPlus(bonus));
        }
      else {
          ui->lineEdit_Persuasion->setText(QString::number(bonus));
          Braum.setPersuasion(QString::number(bonus));
        }
    }
  else {
      if (modifier >= 0) {
          ui->lineEdit_Persuasion->setText(Braum.concatPlus(modifier));
          Braum.setPersuasion(Braum.concatPlus(modifier));
        }
      else {
          ui->lineEdit_Persuasion->setText(QString::number(modifier));
          Braum.setPersuasion(QString::number(modifier));
        }
    }
}

// Save and load functions

void MainWindow::saveItem(QLineEdit *item){

    QString name = Braum.getCharName()+".ini";
    QSettings characterSave(name, QSettings::IniFormat);

    characterSave.setValue(item->objectName(), item->text());
}

void MainWindow::saveItem(QPlainTextEdit *item){

    QString name = Braum.getCharName()+".ini";
    QSettings characterSave(name, QSettings::IniFormat);

    characterSave.setValue(item->objectName(), item->toPlainText());
}

void MainWindow::saveItem(QComboBox *item){

    QString name = Braum.getCharName()+".ini";
    QSettings characterSave(name, QSettings::IniFormat);

    characterSave.setValue(item->objectName(), item->currentIndex());
}


void MainWindow::saveCharacterSheet(bool initialSaveComplete){

    if (initialSaveComplete) {

        QString name = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Character File (*.ini)"));
        //        QString name = Braum.getCharName()+".ini";
        QSettings characterSave(name, QSettings::IniFormat);

        QList<QLineEdit*>lineEditList = this->findChildren<QLineEdit*>();
        foreach (QLineEdit* object, lineEditList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->text());
        }

        QList<QTextEdit*>textEditList = this->findChildren<QTextEdit*>();
        foreach (QTextEdit* object, textEditList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->toPlainText());
        }

        QList<QComboBox*>comboBoxList = this->findChildren<QComboBox*>();
        foreach (QComboBox* object, comboBoxList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->currentIndex());
        }

        QList<QCheckBox*>checkBoxList = this->findChildren<QCheckBox*>();
        foreach (QCheckBox* object, checkBoxList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->isChecked());
        }
    } else {

        QSettings characterSave("default.ini", QSettings::IniFormat);

        QList<QLineEdit*>lineEditList = this->findChildren<QLineEdit*>();
        foreach (QLineEdit* object, lineEditList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->text());
        }

        QList<QTextEdit*>textEditList = this->findChildren<QTextEdit*>();
        foreach (QTextEdit* object, textEditList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->toPlainText());
        }

        QList<QComboBox*>comboBoxList = this->findChildren<QComboBox*>();
        foreach (QComboBox* object, comboBoxList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->currentIndex());
        }

        QList<QCheckBox*>checkBoxList = this->findChildren<QCheckBox*>();
        foreach (QCheckBox* object, checkBoxList) {
            QString objectName = object->objectName();
            characterSave.setValue(objectName, object->isChecked());

        }
    }
}


void MainWindow::resetCharacterSheet(){

    QString name = "default.ini";
    QSettings characterLoad(name, QSettings::IniFormat);

    QList<QLineEdit*>lineEditList = this->findChildren<QLineEdit*>();
    foreach (QLineEdit* object, lineEditList) {
        QString objectName = object->objectName();
        object->setText(characterLoad.value(objectName).toString());

    }

    QList<QTextEdit*>textEditList = this->findChildren<QTextEdit*>();
    foreach (QTextEdit* object, textEditList) {
        QString objectName = object->objectName();
        object->setPlainText(characterLoad.value(objectName).toString());
    }

    QList<QComboBox*>comboBoxList = this->findChildren<QComboBox*>();
    foreach (QComboBox* object, comboBoxList) {
        QString objectName = object->objectName();
        object->setCurrentIndex(characterLoad.value(objectName).toInt());
    }
    QList<QCheckBox*>checkBoxList = this->findChildren<QCheckBox*>();
    foreach (QCheckBox* object, checkBoxList) {
        QString objectName = object->objectName();
        object->setChecked(characterLoad.value(objectName).toBool());
    }
}

void MainWindow::loadCharacterSheet(){

    QFileDialog openCharacterDialog(this);
    openCharacterDialog.setFileMode(QFileDialog::ExistingFile);
    openCharacterDialog.setNameFilter(tr("Character File (*.ini)"));
    openCharacterDialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if (openCharacterDialog.exec()) {
        fileNames = openCharacterDialog.selectedFiles();

        QString name = fileNames[0];
        //QString name = Braum.getCharName()+".ini";
        QSettings characterLoad(name, QSettings::IniFormat);

        QList<QLineEdit*>lineEditList = this->findChildren<QLineEdit*>();
        foreach (QLineEdit* object, lineEditList) {
            QString objectName = object->objectName();
            object->setText(characterLoad.value(objectName).toString());

        }

        QList<QTextEdit*>textEditList = this->findChildren<QTextEdit*>();
        foreach (QTextEdit* object, textEditList) {
            QString objectName = object->objectName();
            object->setPlainText(characterLoad.value(objectName).toString());
        }

        QList<QComboBox*>comboBoxList = this->findChildren<QComboBox*>();
        foreach (QComboBox* object, comboBoxList) {
            QString objectName = object->objectName();
            object->setCurrentIndex(characterLoad.value(objectName).toInt());
        }

        QList<QCheckBox*>checkBoxList = this->findChildren<QCheckBox*>();
        foreach (QCheckBox* object, checkBoxList) {
            QString objectName = object->objectName();
            object->setChecked(characterLoad.value(objectName).toBool());
        }
    }
}


// Slots for UI elements
//Ability Scores Changed
void MainWindow::on_lineEdit_StrScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setStrength(score);
  Braum.setStrMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_StrMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_StrMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_StrMod->setText(mod);
    }
}

void MainWindow::on_lineEdit_DexScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setDexterity(score);
  Braum.setDexMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_DexMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_DexMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_DexMod->setText(mod);
    }
}

void MainWindow::on_lineEdit_ConScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setConstitution(score);
  Braum.setConMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_ConMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_ConMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_ConMod->setText(mod);
    }
}

void MainWindow::on_lineEdit_IntScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setIntelligence(score);
  Braum.setIntMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_IntMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_IntMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_IntMod->setText(mod);
    }
}

void MainWindow::on_lineEdit_WisScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setWisdom(score);
  Braum.setWisMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_WisMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_WisMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_WisMod->setText(mod);
    }
}

void MainWindow::on_lineEdit_ChaScore_textChanged(const QString &arg1)
{
  QString score = arg1;
  QString mod = Braum.calculateAbilityModifier(arg1);
  Braum.setCharisma(score);
  Braum.setChaMod(mod);

  if (&arg1 == QString("")) {
      ui->lineEdit_ChaMod->setText("-5");
    }
  else if (score.toInt() >= 10) {
      ui->lineEdit_ChaMod->setText(Braum.concatPlus(mod));
    }
  else{
      ui->lineEdit_ChaMod->setText(mod);
    }
}

// Ability Modifier Changed
void MainWindow::on_lineEdit_StrMod_textChanged(const QString &arg1)
{
  setStrBonuses();
  setAttackBonuses();
}

void MainWindow::on_lineEdit_DexMod_textChanged(const QString &arg1)
{
  setDexBonuses();
  setAttackBonuses();
}

void MainWindow::on_lineEdit_ConMod_textChanged(const QString &arg1)
{
  setConBonuses();
  setAttackBonuses();
}

void MainWindow::on_lineEdit_IntMod_textChanged(const QString &arg1)
{
  setIntBonuses();
  setAttackBonuses();
}

void MainWindow::on_lineEdit_WisMod_textChanged(const QString &arg1)
{
  setWisBonuses();
  setAttackBonuses();
}

void MainWindow::on_lineEdit_ChaMod_textChanged(const QString &arg1)
{
  setChaBonuses();
  setAttackBonuses();
}

// Combo Box Slots //ACTIVATED//

// Saving Throws
void MainWindow::on_comboBox_StrSave_activated(const QString &arg1)
{
  setStrBonuses();
}

void MainWindow::on_comboBox_DexSave_activated(const QString &arg1)
{
  setDexBonuses();
}

void MainWindow::on_comboBox_ConSave_activated(const QString &arg1)
{
  setConBonuses();
}

void MainWindow::on_comboBox_IntSave_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_WisSave_activated(const QString &arg1)
{
  setWisBonuses();
}

void MainWindow::on_comboBox_ChaSave_activated(const QString &arg1)
{
  setChaBonuses();
}

// Skills
void MainWindow::on_comboBox_Acrobatics_activated(const QString &arg1)
{
  setDexBonuses();
}

void MainWindow::on_comboBox_AnimalHandling_activated(const QString &arg1)
{
  setWisBonuses();
}

void MainWindow::on_comboBox_Arcana_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_Athletics_activated(const QString &arg1)
{
  setStrBonuses();
}

void MainWindow::on_comboBox_Deception_activated(const QString &arg1)
{
  setChaBonuses();
}

void MainWindow::on_comboBox_History_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_Insight_activated(const QString &arg1)
{
  setWisBonuses();
}

void MainWindow::on_comboBox_Intimidation_activated(const QString &arg1)
{
  setChaBonuses();
}

void MainWindow::on_comboBox_Investigation_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_Medicine_activated(const QString &arg1)
{
  setWisBonuses();
}

void MainWindow::on_comboBox_Nature_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_Perception_activated(const QString &arg1)
{
  setWisBonuses();
}

void MainWindow::on_comboBox_Performance_activated(const QString &arg1)
{
  setChaBonuses();
}

void MainWindow::on_comboBox_Persuasion_activated(const QString &arg1)
{
  setChaBonuses();
}

void MainWindow::on_comboBox_Religion_activated(const QString &arg1)
{
  setIntBonuses();
}

void MainWindow::on_comboBox_SleightOfHand_activated(const QString &arg1)
{
  setDexBonuses();
}

void MainWindow::on_comboBox_Stealth_activated(const QString &arg1)
{
  setDexBonuses();
}

void MainWindow::on_comboBox_Survival_activated(const QString &arg1)
{
  setWisBonuses();
}

// Level Changed
void MainWindow::on_lineEdit_CharLevel_textChanged(const QString &arg1)
{
  setLevelBasedBonuses(arg1);
}

void MainWindow::on_lineEdit_CurrentHP_textChanged(const QString &arg1)
{
//    if (arg1.toInt() > ui->lineEdit_MaximumHP->text().toInt()) {
//        ui->lineEdit_CurrentHP->setText(Braum.getCurrentHP());
//    }
//    else {
        Braum.setCurrentHP(arg1);
//    }
}

void MainWindow::on_lineEdit_MaximumHP_textChanged(const QString &arg1)
{
    Braum.setMaximumHP(arg1);
}

// Saving and loading

void MainWindow::on_pushButton_SaveCharacter_released()
{
    saveCharacterSheet(true);
}

void MainWindow::on_pushButton_LoadCharacter_released()
{
    loadCharacterSheet();
}

void MainWindow::on_pushButton_ResetCharacter_released()
{
    resetCharacterSheet();
}

// Attack comboBoxes

void MainWindow::on_comboBox_Attack1_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack2_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack3_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack4_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack5_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack6_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack7_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack8_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack9_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Attack10_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov1_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov2_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov3_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov4_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov5_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov6_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov7_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov8_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov9_activated(const QString &arg1)
{
    setAttackBonuses();
}

void MainWindow::on_comboBox_Gov10_activated(const QString &arg1)
{
    setAttackBonuses();
}
