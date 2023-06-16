#include <QApplication>
#include "namepickerdialog.h"
#include "mainwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Wyświetlenie okna do podania nazw graczy
    NamePickerDialog namePickerDialog;
    if (namePickerDialog.exec() == QDialog::Accepted)
    {
        QString player1Name = namePickerDialog.getPlayer1Name();
        QString player2Name = namePickerDialog.getPlayer2Name();

        // Sprawdzenie, czy nazwy graczy są niepuste
        if (player1Name.isEmpty() || player2Name.isEmpty())
        {
            return 0; // Zakończ program, jeśli nazwy graczy są puste
        }

        // Utworzenie i pokazanie głównego okna
        MainWindow mainWindow;
        mainWindow.setPlayerName(player1Name, player2Name);
        mainWindow.show();

        return app.exec();
    }
    else
    {
        return 0; // Zakończ program, jeśli okno dialogowe zostało zamknięte
    }
}
