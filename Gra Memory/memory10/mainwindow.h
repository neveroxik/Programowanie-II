#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void setPlayerName(const QString& name1, const QString& name2);

private:
    void handleCardClick(); //odkrywanie karty
    void createBoard(); //tworzenie planszy
    void checkGameEnd(); //sprawdzanie czy jest koniec gry
    void restartGame(); //restartowanie gry

    QString player1Name;  //nazwa 1 gracza
    QString player2Name;  //nazwa 2 gracza
    QGridLayout *boardLayout;   //układ planszy
    QVector<QPushButton*> cards;
    QVector<QString> cardValues;
    QVector<QPixmap> cardImages;
    QLabel *scoreLabel;
    bool isCardClickable; // blokada klikania więcej niż 2 kart
    bool currentPlayer; //gracz ktory wykonuje ruch
    int player1Score;   // wynik 1 gracza
    int player2Score;   // wynik 2 gracza
    QPushButton *flippedCard; //odwracanie karty
    void updateScore(); //aktualizowanie wyniku
    QIcon backIcon; // Deklaracja pola backIcon
};

#endif // MAINWINDOW_H
