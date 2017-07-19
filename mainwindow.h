#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QVariant>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
#include <QTcpServer>
#include <QtWebSockets/QWebSocket>

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
    void platformSetup();
    void editableBoxFormatting();
    void setLevelBasedBonuses(QString level);
    void setSkillBonuses();
    void setStrBonuses();
    void setDexBonuses();
    void setConBonuses();
    void setIntBonuses();
    void setWisBonuses();
    void setChaBonuses();
    void setAttackBonuses();

    void saveItem(QLineEdit *item);
    void saveItem(QPlainTextEdit *item);
    void saveItem(QComboBox *item);
    void saveCharacterSheet(bool initialSaveComplete);
    void resetCharacterSheet();
    void loadCharacterSheet();
    void writeToFile(QFile &outputFile, QByteArray writeBuffer);

    void hostSession();
    void joinSession();

private:
    std::map<int, int> mModifierTable;

    std::vector<QString> mAbilityScores;

private slots:
    void on_lineEdit_StrScore_editingFinished();
    void on_lineEdit_DexScore_editingFinished();
    void on_lineEdit_ConScore_editingFinished();
    void on_lineEdit_IntScore_editingFinished();
    void on_lineEdit_WisScore_editingFinished();
    void on_lineEdit_ChaScore_editingFinished();

    void on_lineEdit_StrMod_textChanged(const QString &arg1);
    void on_lineEdit_DexMod_textChanged(const QString &arg1);
    void on_lineEdit_ConMod_textChanged(const QString &arg1);
    void on_lineEdit_IntMod_textChanged(const QString &arg1);
    void on_lineEdit_WisMod_textChanged(const QString &arg1);
    void on_lineEdit_ChaMod_textChanged(const QString &arg1);

    void on_comboBox_StrSave_activated(const QString &arg1);
    void on_comboBox_DexSave_activated(const QString &arg1);
    void on_comboBox_ConSave_activated(const QString &arg1);
    void on_comboBox_IntSave_activated(const QString &arg1);
    void on_comboBox_WisSave_activated(const QString &arg1);
    void on_comboBox_ChaSave_activated(const QString &arg1);

    void on_lineEdit_CharLevel_textChanged(const QString &arg1);

    void on_comboBox_Acrobatics_activated(const QString &arg1);
    void on_comboBox_AnimalHandling_activated(const QString &arg1);
    void on_comboBox_Athletics_activated(const QString &arg1);
    void on_comboBox_Arcana_activated(const QString &arg1);
    void on_comboBox_Deception_activated(const QString &arg1);


    void on_comboBox_History_activated(const QString &arg1);
    void on_comboBox_Insight_activated(const QString &arg1);
    void on_comboBox_Intimidation_activated(const QString &arg1);
    void on_comboBox_Investigation_activated(const QString &arg1);    
    void on_comboBox_Medicine_activated(const QString &arg1);
    void on_comboBox_Nature_activated(const QString &arg1);
    void on_comboBox_Perception_activated(const QString &arg1);
    void on_comboBox_Performance_activated(const QString &arg1);
    void on_comboBox_Persuasion_activated(const QString &arg1);
    void on_comboBox_Religion_activated(const QString &arg1);
    void on_comboBox_SleightOfHand_activated(const QString &arg1);
    void on_comboBox_Stealth_activated(const QString &arg1);
    void on_comboBox_Survival_activated(const QString &arg1);

    void on_lineEdit_CurrentHP_textChanged(const QString &arg1);
    void on_lineEdit_MaximumHP_textChanged(const QString &arg1);

    void on_pushButton_SaveCharacter_released();
    void on_pushButton_LoadCharacter_released();
    void on_pushButton_ResetCharacter_released();

    void on_comboBox_Attack1_activated(const QString &arg1);
    void on_comboBox_Attack2_activated(const QString &arg1);
    void on_comboBox_Attack3_activated(const QString &arg1);
    void on_comboBox_Attack4_activated(const QString &arg1);
    void on_comboBox_Attack5_activated(const QString &arg1);
    void on_comboBox_Attack6_activated(const QString &arg1);
    void on_comboBox_Attack7_activated(const QString &arg1);
    void on_comboBox_Attack8_activated(const QString &arg1);
    void on_comboBox_Attack9_activated(const QString &arg1);
    void on_comboBox_Attack10_activated(const QString &arg1);

    void on_comboBox_Gov1_activated(const QString &arg1);
    void on_comboBox_Gov2_activated(const QString &arg1);
    void on_comboBox_Gov3_activated(const QString &arg1);
    void on_comboBox_Gov4_activated(const QString &arg1);
    void on_comboBox_Gov5_activated(const QString &arg1);
    void on_comboBox_Gov6_activated(const QString &arg1);
    void on_comboBox_Gov7_activated(const QString &arg1);
    void on_comboBox_Gov8_activated(const QString &arg1);
    void on_comboBox_Gov9_activated(const QString &arg1);
    void on_comboBox_Gov10_activated(const QString &arg1);


    void on_pushButton_HostSession_released();
};

#endif // MAINWINDOW_H
