#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    void editableBoxFormatting();
    void setProficiencyBonus(QString level);
    void setSkillBonuses();
    void setStrBonuses();
    void setDexBonuses();
    void setConBonuses();
    void setIntBonuses();
    void setWisBonuses();
    void setChaBonuses();

private:
    std::map<int, int> mModifierTable;

    std::vector<QString> mAbilityScores;

private slots:
    void on_lineEdit_StrScore_textChanged(const QString &arg1);
//    void on_lineEdit_DexScore_textChanged(const QString &arg1);
//    void on_lineEdit_ConScore_textChanged(const QString &arg1);
//    void on_lineEdit_IntScore_textChanged(const QString &arg1);
//    void on_lineEdit_WisScore_textChanged(const QString &arg1);
//    void on_lineEdit_ChaScore_textChanged(const QString &arg1);
//    void on_lineEdit_CharLevel_textChanged(const QString &arg1);
    void on_comboBox_StrSave_activated(const QString &arg1);
    //void on_lineEdit_Proficiency_textChanged(const QString &arg1);
    void on_lineEdit_StrMod_textChanged(const QString &arg1);
    void on_lineEdit_DexScore_textChanged(const QString &arg1);
    void on_lineEdit_CharLevel_textChanged(const QString &arg1);
    void on_comboBox_Athletics_activated(const QString &arg1);
    void on_lineEdit_DexMod_textChanged(const QString &arg1);
    void on_comboBox_Acrobatics_activated(const QString &arg1);
    void on_comboBox_SleightOfHand_activated(const QString &arg1);
    void on_comboBox_DexSave_activated(const QString &arg1);
    void on_lineEdit_ConScore_textChanged(const QString &arg1);
    void on_comboBox_ConSave_activated(const QString &arg1);
    void on_lineEdit_ConMod_textChanged(const QString &arg1);
    void on_lineEdit_IntScore_textChanged(const QString &arg1);
    void on_lineEdit_IntMod_textChanged(const QString &arg1);
    void on_comboBox_IntSave_activated(const QString &arg1);
    void on_comboBox_Arcana_activated(const QString &arg1);
    void on_comboBox_History_activated(const QString &arg1);
    void on_comboBox_Investigation_activated(const QString &arg1);
    void on_comboBox_Nature_activated(const QString &arg1);
    void on_comboBox_Religion_activated(const QString &arg1);
    void on_comboBox_AnimalHandling_activated(const QString &arg1);
    void on_comboBox_Insight_activated(const QString &arg1);
    void on_comboBox_Medicine_activated(const QString &arg1);
    void on_comboBox_Survival_activated(const QString &arg1);
    void on_comboBox_Perception_activated(const QString &arg1);
    void on_comboBox_Stealth_activated(const QString &arg1);
    void on_lineEdit_WisScore_textChanged(const QString &arg1);
    void on_lineEdit_ChaScore_textChanged(const QString &arg1);
    void on_lineEdit_WisMod_textChanged(const QString &arg1);
    void on_lineEdit_ChaMod_textChanged(const QString &arg1);
    void on_comboBox_WisSave_activated(const QString &arg1);
    void on_comboBox_ChaSave_activated(const QString &arg1);
    void on_comboBox_Deception_activated(const QString &arg1);
    void on_comboBox_Performance_activated(const QString &arg1);
    void on_comboBox_Persuasion_activated(const QString &arg1);
    void on_comboBox_Intimidation_activated(const QString &arg1);
    void on_lineEdit_CurrentHP_textChanged(const QString &arg1);
    void on_lineEdit_MaximumHP_textChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
