#include "BoardGame.h"
#include "Chip.h"
#include "Player.h"

const int PLAYER_MAX = 2;
int BoardGame::numOfCol[MAX_COLUMN] = {5, 5, 5, 5, 5, 5, 5};

int main() {
    int game = 1;

    while (true) {
        // Initialization of the class objects needed for the game

        Player p[PLAYER_MAX];

        p[0].setName("Nguoi choi 1");
        p[1].setName("Nguoi choi 2");

        Chip blankChip(BLANK);
        Chip redChip(RED);
        Chip goldChip(GOLD);

        cout << "WELCOME TO CONNECT FOUR!" << endl
             << endl;

        // Select the Colors

        int choice;
        cout << "Vui long chon color cho Nguoi choi 1 (1 - RED, 2 - GOLD): ";
        cin >> choice;

        while (choice < 1 || choice > 2) {
            cout << "Khong hop le. Nhap lai! Input: ";
            cin >> choice;
        }

        if (choice == 1) {
            p[0].setColor(redChip.getColor());
            p[1].setColor(goldChip.getColor());
        } else if (choice == 2) {
            p[0].setColor(goldChip.getColor());
            p[1].setColor(redChip.getColor());
        }

        BoardGame gameBoard;

        cout << p[0].getName() << " choi " << p[0].getColor() << " chip." << endl;
        cout << p[1].getName() << " choi " << p[1].getColor() << " chip." << endl
             << endl;

        cout << gameBoard.toString() << endl;
        int signal = 0;

        // Gameplay

        while (gameBoard.checkWin() != 0 && gameBoard.checkWin() != 1 && gameBoard.checkWin() != 2) {
            unsigned seed;

            // Random player selection to begin the game
            cout << "Luot choi cua Nguoi choi " << (signal % 2) + 1 << ":" << endl;

            seed = time(0);
            srand(seed);

            if ((signal % 2) == 0) {
                Chip gameChip(p[0].getColor());

                int slot;
                cout << "Nhap so thu tu COLUMN muon dat CHIP: ";
                cin >> slot;

                // Handle error
                if (gameBoard.putChipDown(gameChip, slot) == 0) {
                    while (gameBoard.putChipDown(gameChip, slot) == 0) {
                        cout << "Khong hop le. Thu lai: ";
                        cin >> slot;

                        gameBoard.putChipDown(gameChip, slot);
                    }
                } else {
                    cout << "Thanh cong!" << endl;
                }
            } else {
                Chip gameChip(p[1].getColor());

                int slot;
                cout << "Nhap so thu tu COLUMN muon dat CHIP: ";
                cin >> slot;

                // Handle error
                if (gameBoard.putChipDown(gameChip, slot) == 0) {
                    while (gameBoard.putChipDown(gameChip, slot) == 0) {
                        cout << "Khong hop le. Thu lai: ";
                        cin >> slot;

                        gameBoard.putChipDown(gameChip, slot);
                    }
                } else {
                    cout << "Thanh cong!" << endl;
                }
            }
            cout << gameBoard.toString() << endl;
            signal++;
        }

        // Check if there is a winner or draw

        if (gameBoard.checkWin() == 0) {
            cout << "VAN DAU HOA!" << endl;
        } else if (gameBoard.checkWin() == 1) {
            cout << p[0].getName() << " chien thang!" << endl;
        } else {
            cout << p[1].getName() << " chien thang!" << endl;
        }

        int playAgain;
        cout << "CHOI LAI, vui long nhan phim 1. Hoac nhan bat ky phim nao khac de KET THUC";
        cin >> playAgain;

        // choi lai;
        if (playAgain != 1) break;
    }

    system("pause");
    return 0;
}