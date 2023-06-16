#include "mainwindow.h"
#include "namepickerdialog.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <random>
#include <algorithm>
#include <QDebug>
#include <QTimer>
#include <QPointer>
#include <QFontDatabase>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentPlayer(true), player1Score(0), player2Score(0), flippedCard(nullptr), isCardClickable(true), backIcon(":/images/back.png") // określenie początkowych wartości
{
    // Przypisanie tytułu okna
    setWindowTitle("Gra Memory");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    backIcon = QIcon(":/images/back.png");

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    boardLayout = new QGridLayout();
    mainLayout->addLayout(boardLayout);

    scoreLabel = new QLabel(this);
    mainLayout->addWidget(scoreLabel);

    // Określenie marginesów i odstępów
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    boardLayout->setSpacing(5);

    // Dodanie przycisku nowa gra
    QPushButton *newGameButton = new QPushButton("Nowa gra", this);
    mainLayout->addWidget(newGameButton);
    connect(newGameButton, &QPushButton::clicked, this, &MainWindow::restartGame);

    // Wywołanie metod tworzących plansze i wynik
    createBoard();
    updateScore();

    // Dodanie fontu
    int id = QFontDatabase::addApplicationFont(":/fonts/Roboto-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont roboto(family);

    // Wykorzystanie dodanego fontu
    scoreLabel->setFont(roboto);
    newGameButton->setFont(roboto);

    // Określenie koloru tła
    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0, QColor(188, 247, 187));  // Pierwszy kolor (jasny zielony)
    gradient.setColorAt(1, QColor(123, 206, 123));  // Drugi kolor (ciemny zielony)

    QPalette pal = palette();
    pal.setBrush(QPalette::Window, gradient);
    setAutoFillBackground(true);
    setPalette(pal);

    // Określenie stylowania przycisku
    QString buttonStyle = "QPushButton {"
                          "  background-color: #ff6666;"
                          "  border: 1px solid #c0c0c0;"
                          "  border-radius: 5px;"
                          "  font: bold 18px;"
                          "}"
                          "QPushButton:pressed {"
                          "  background-color: #ffb3b3;"
                          "}";
    newGameButton->setStyleSheet(buttonStyle);
}

void MainWindow::setPlayerName(const QString& name1, const QString& name2)
{
    player1Name = name1;
    player2Name = name2;
    updateScore();
}

void MainWindow::createBoard()
{
    // Przypisanie do pary kart tej samej wartości
    for (int i = 0; i < 8; ++i)
    {
        QString cardValue = QString(QChar('A' + i));
        cardValues.append(cardValue);
        cardValues.append(cardValue);
    }

    // Przetasowanie wartości kart
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cardValues.begin(), cardValues.end(), rng);

    // Określenie ilości kolumn i rzędów
    const int numRows = 4;
    const int numCols = 4;

    // Wygenerowanie planszy i kart
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            QString imagePath = ":/images/" + cardValues[i * numCols + j] + ".png";  // Ścieżka do obrazu
            QPixmap image(imagePath);

            // Sprawdzenie czy obraz został poprawnie wczytany
            if (image.isNull()) {
                qDebug() << "Nie udało się wczytać obrazu:" << imagePath;
                    continue;
            }

            QPushButton *card = new QPushButton(this);
            card->setFixedSize(100, 100);
            card->setIcon(backIcon);
            card->setIconSize(QSize(100, 100));
            card->setProperty("cardValue", cardValues[i * numCols + j]);
            connect(card, &QPushButton::clicked, this, &MainWindow::handleCardClick);
            boardLayout->addWidget(card, i, j);
            cards.append(card);
        }
    }
}

void MainWindow::handleCardClick()
{
    QPushButton *clickedCard = qobject_cast<QPushButton*>(sender());
    QString cardValue = clickedCard->property("cardValue").toString();

    if (!flippedCard && isCardClickable) // Sprawdzenie, czy żadna karta nie jest odwrócona i czy można odkrywać karty
    {
        flippedCard = clickedCard;
        flippedCard->setIcon(QIcon(":/images/" + cardValue + ".png"));
        flippedCard->setIconSize(QSize(100, 100));
    }
    else if (flippedCard && flippedCard != clickedCard && isCardClickable) // Sprawdzenie, czy jedna karta jest już odwrócona i czy można odkrywać kolejną kartę
    {
        // Zablokowanie możliwości odkrywania kolejnych kart
        isCardClickable = false;

        // Odwrócenie obu kart
        clickedCard->setIcon(QIcon(":/images/" + cardValue + ".png"));
        clickedCard->setIconSize(QSize(100, 100));
        flippedCard->setIcon(QIcon(":/images/" + flippedCard->property("cardValue").toString() + ".png"));
        flippedCard->setIconSize(QSize(100, 100));

        QEventLoop eventLoop;
        QTimer::singleShot(1000, &eventLoop, &QEventLoop::quit); // Czekamy 1000 ms (1 sekunda)
        eventLoop.exec();

        if (cardValue == flippedCard->property("cardValue").toString())
        {
            // Odkrycie tych samych kart
            flippedCard->setEnabled(false);
            clickedCard->setEnabled(false);

            // Update player scores
            if (currentPlayer)
            {
                    player1Score++;
            }
            else
            {
                    player2Score++;
            }

            updateScore();
            checkGameEnd();
        }
        else
        {
            // Odkrycie różnych kart
            flippedCard->setIcon(backIcon);
            clickedCard->setIcon(backIcon);

            flippedCard->setEnabled(true);
            clickedCard->setEnabled(true);

            // Zmiana gracza
            currentPlayer = !currentPlayer;
        }

        flippedCard = nullptr;
        updateScore();

        // Odblokowanie możliwości odkrywania kolejnych kart
        isCardClickable = true;
    }
}



void MainWindow::updateScore()
{
    QString currentPlayerText = currentPlayer ? player1Name : player2Name;
    scoreLabel->setText(QString("<html><body style='text-align:center;'><b>Ruch gracza %1</b><br/>%2: %3 - %4: %5</body></html>").arg(currentPlayerText).arg(player1Name).arg(player1Score).arg(player2Name).arg(player2Score));
}


void MainWindow::checkGameEnd()
{
    bool allCardsMatched = true;

    for (QPushButton *card : cards)
    {
        if (card->isEnabled())
        {
            allCardsMatched = false;
            break;
        }
    }

    if (allCardsMatched)
    {
        QString winner;
        if (player1Score > player2Score)
        {
            winner = player1Name + " wygrywa!";
        }
        else if (player1Score < player2Score)
        {
            winner = player2Name + " wygrywa!";
        }
        else
        {
            winner = "Remis!";
        }

        QMessageBox::information(this, "Koniec gry!", QString("%1 \n\n%4: %2 punktow\n%5: %3 punktow").arg(winner).arg(player1Score).arg(player2Score).arg(player1Name).arg(player2Name));
    }
}


void MainWindow::restartGame()
{
    // Wyzerowanie wyniku
    player1Score = 0;
    player2Score = 0;
    currentPlayer = true;
    updateScore();

    // "Odwrócenie" kart, reset pozycji
    for (QPushButton *card : cards)
    {
        card->setEnabled(true);
        card->setIcon(backIcon);  // Ustawienie ikony zakrytej
        card->setIconSize(QSize(100, 100));
    }

    // Przemieszanie kart
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cardValues.begin(), cardValues.end(), rng);

    // Przypisanie wcześniej przemieszanych kart do pozycji
    for (int i = 0; i < cards.size(); ++i)
    {
        cards[i]->setProperty("cardValue", cardValues[i]);
    }
}
