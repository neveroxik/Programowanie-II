#include "namepickerdialog.h"

NamePickerDialog::NamePickerDialog(QWidget *parent)
    : QDialog(parent), player1NameEdit(new QLineEdit(this)), player2NameEdit(new QLineEdit(this))
{
    setWindowTitle("Wprowadź nazwy graczy");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *player1Layout = new QHBoxLayout();
    QLabel *player1Label = new QLabel("Gracz 1:", this);
    player1Layout->addWidget(player1Label); // dodanie etykiety
    player1Layout->addWidget(player1NameEdit); // dodanie inputu

    QHBoxLayout *player2Layout = new QHBoxLayout();
    QLabel *player2Label = new QLabel("Gracz 2:", this);
    player2Layout->addWidget(player2Label); // dodanie etykiety
    player2Layout->addWidget(player2NameEdit); // dodanie inputu

    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &NamePickerDialog::handleOkButtonClick);

    mainLayout->addLayout(player1Layout); // wyświetlenie etykiet i inputów
    mainLayout->addLayout(player2Layout);
    mainLayout->addWidget(okButton); // wyświetlenie przycisku
}

QString NamePickerDialog::getPlayer1Name() const // pobranie wpisanej wartości
{
    return player1NameEdit->text();
}

QString NamePickerDialog::getPlayer2Name() const
{
    return player2NameEdit->text();
}

void NamePickerDialog::handleOkButtonClick() // walidacja czy wprowadzono wartość
{
    if (!player1NameEdit->text().trimmed().isEmpty() && !player2NameEdit->text().trimmed().isEmpty())
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Błąd", "Proszę wprowadzić nazwy dla obu graczy.");
    }
}
