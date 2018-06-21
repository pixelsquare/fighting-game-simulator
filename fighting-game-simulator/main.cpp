#include <iostream>
#include <cctype>
#include <cstdlib>

#if _WIN32
#include <Windows.h>
#endif

#define ATTACK_TIME_MS (80)

bool isKeysValid(char keys[], int size);
void deduceAttack(char keys[], int &atkValue, int &atkPow);
void showAttack(int atkValue, int atkPow);

int main(int argc, char *argv[])
{
    char comboMove[4] = { 0 };

    while (true)
    {
        system("clear");

        std::cout << "###############################" << std::endl;
        std::cout << "Welcome to Fighting Game Simulator!" << std::endl;
        std::cout << "###############################" << std::endl;
        std::cout << std::endl;

        std::cout << "[Controls]" << std::endl;
        std::cout << "   W, A, S, D, X" << std::endl;
        std::cout << std::endl;

        int comboLen = sizeof(comboMove) / sizeof(comboMove[0]);

        for (int i = 0; i < comboLen; i++)
        {
            std::cout << "Enter button " << i + 1 << std::endl;
            std::cin >> comboMove[i];
            comboMove[i] = std::tolower(comboMove[i]);
        }

        if (isKeysValid(comboMove, comboLen))
        {
            int attackValue = 0;
            int attackPow = 0;

            deduceAttack(comboMove, attackValue, attackPow);
            showAttack(attackValue, attackPow);
        }

        char willComboAgain = ' ';
        
        do
        {
            std::cout << std::endl;
            std::cout << "Do you want to combo attack again? (y/n)" << std::endl;
            std::cin >> willComboAgain;
        } 
        while (willComboAgain != 'y' && willComboAgain != 'n');

        if (willComboAgain == 'n')
        {
            break;
        }
    }

    std::cout << std::endl;
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

bool isKeysValid(char keys[], int size)
{
    for (int i = 0; i < size; i++)
    {
        char key = keys[i];

        if (key != 'w' && key != 'a' && key != 's' && key != 'd' && key != 'x')
        {
            return false;
        }
    }

    return true;
}

void deduceAttack(char keys[], int &atkValue, int &atkPow)
{
    if (keys[0] == 'a' && keys[1] == 'w' && keys[2] == 's' && (keys[3] == 'x' || keys[3] == 'd'))
    {
        atkValue = 1;
    }
    else if (keys[0] == 's' && (keys[1] == 'x' || keys[1] == 'q') && keys[2] == 'q' && (keys[4] >= 97 && keys[4] <= 122))
    {
        atkValue = 2;
    }
    else
    {
        atkValue = 3;
    }

    if (atkValue == 1 || atkValue == 2)
    {
        std::cout << "Enter attack power for selected attack (0 - 10)" << std::endl;
        std::cin >> atkPow;

        if (atkPow < 0 || atkPow > 10)
        {
            atkPow = 0;
        }
    }
    else
    {
        atkPow = 2;
    }
}

void showAttack(int atkValue, int atkPow)
{
    static const std::string attackTypeName[3] =
    {
        "Powerful FIREBALL",
        "Spinning WINDKICK",
        "Defensive Block"
    };

    std::cout << std::endl;
    std::cout << "Attack Type: " << attackTypeName[atkValue].c_str() << std::endl;

    for (int y = 0; y < atkPow + 1; y++)
    {
        for (int x = 0; x < y; x++)
        {
            std::cout << "+";
#if _WIN32
            Sleep(ATTACK_TIME_MS);
#endif
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Chosen Attack Value is " << atkValue << " and Attack Power is " << atkPow << std::endl;
}