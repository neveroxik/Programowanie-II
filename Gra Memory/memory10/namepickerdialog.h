#ifndef NAMEPICKERDIALOG_H
#define NAMEPICKERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

class NamePickerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NamePickerDialog(QWidget *parent = nullptr);

    QString getPlayer1Name() const;
    QString getPlayer2Name() const;


private slots:
    void handleOkButtonClick();

private:
    QLineEdit *player1NameEdit; //zmiana nazwy gracza 1
    QLineEdit *player2NameEdit; //zmiana nazwy gracza 2
};

#endif // NAMEPICKERDIALOG_H
