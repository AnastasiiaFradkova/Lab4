#include <iostream>
#include "Character.h"

using namespace std;

int main()
{
    srand(time(0));

    while (true) {
        int character;
        string name;

        cout << "1. Knight\n2. Archer\n3. Light mage\n4. Dark mage\nChoose your fighter: ";
        cin >> character;
        
        cout << "Enter a name for your character: ";
        cin >> name;

        Character* player = createCharacter(character, name);
        
        if (player == nullptr) {
            cout << "Invalid input, please try again!" << endl;
            continue;
        }

        Character* computer = createCharacter(rand() % 4 + 1, "Computer");

        cout << endl;
        cout << "Your character: " << endl;
        player->showStats();

        cout << endl;
        cout << "Your enemy: " << endl;
        computer->showStats();

        bool playerStrongAttackUsed = false;
        bool computerStrongAttackUsed = false;

        while (player->getHealth() > 0 && computer->getHealth() > 0) {
            cout << endl;
            int action, computerAction;

            cout << "1. Attack\n2. Heal\n";
            if (!playerStrongAttackUsed) {
                cout << "3. Special attack\n";
            }
            cout << "Choose an action: ";
            cin >> action;

            bool invalid = false;

            cout << endl;
            chooseAction(action, playerStrongAttackUsed, player, computer, invalid);
            
            if (invalid) {
                cout << "Invalid choice, try again!" << endl;
                continue;
            }

            computerAction = computerStrongAttackUsed ? rand() % 2 + 1 : rand() % 3 + 1;
            cout << endl;
            chooseAction(computerAction, computerStrongAttackUsed, computer, player, invalid);
        }

        cout << endl;

        if (player->getHealth() <= 0) {
            cout << "You lost..." << endl;
        }
        else {
            cout << "You won!" << endl;
        }

        delete player;
        delete computer;

        string a;
        cout << "Would you like to continue? (y/n): ";
        cin >> a;

        if (a != "y" && a != "yes") break;

        cout << endl;
    }
}