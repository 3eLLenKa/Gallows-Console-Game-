#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80

#pragma comment(lib, "Winmm.lib")

using namespace std;

class Game
{
public:

    Game();
    ~Game() {
        this->word.clear();
    }

    void menu();
    void rules();
    void mainChoiceMenu();
    void playGame(string word);
    void drawGallows(int wrongCount);
    void fieldDraw(vector<char>& correct, vector<char>& incorrect);

    void difficultyChoice();
    void wordCategoryChoice();
    void settingsChoice();
    void randomPlayGame();
    
private:

    vector<string> animals{ "КОТ", "СОБАКА", "СЛОН", "ТИГР", "ЛЕВ", "БЕГЕМОТ" };
    vector<string> food{ "АПЕЛЬСИН", "ПИЦЦА", "СУП", "КАРТОШКА", "БУРГЕР" };
    vector<string> planets{ "ЗЕМЛЯ", "МАРС", "ЮПИТЕР", "САТУРН", "НЕПТУН", "МЕРКУРИЙ" };

    string word = "";

    int choice;
    int difficulty = 0;
    const int& maxWrongs = 12;

};

Game::Game()
{
    mainChoiceMenu();
}

void Game::mainChoiceMenu() {

    int tab = 0;
    int input;

    bool exit = false;

    while (!exit) {
        system("cls");

        menu();

        cout << "\n\t\t\t\t\t\t===== GAME MENU =====" << endl;
        cout << "\n\t\t\t\t\t\t[1] Играть" << (tab == 0 ? " <" : "") << endl;
        cout << "\n\t\t\t\t\t\t[2] Правила" << (tab == 1 ? " <" : "") << endl;
        cout << "\n\t\t\t\t\t\t[3] Настройки" << (tab == 2 ? " <" : "") << endl;
        cout << "\n\t\t\t\t\t\t[4] Выйти" << (tab == 3 ? " <" : "") << endl;

        input = _getch();
        if (input == UP && tab > 0) { 
            tab--;
        }
        else if (input == DOWN && tab < 5) { 
            tab++;
        }
        else if (input == ENTER) { 
            switch (tab) {
            case 0:
                difficultyChoice();
                break;
            case 1:
                rules();
                break;
            case 2:
                settingsChoice();
                break;
            case 3:
                exit = true;
                ExitProcess(0);
                break;
            }
        }
        else if (input == ESC)
        {
            exit = true;
        }
    }
}

void Game::randomPlayGame() 
{
    int temp;

    if (this->difficulty == 0 or this->word == "")
    {
        system("cls");
        cout << "Вы указали не все параметры!" << endl;
        Sleep(1000);
        this->difficulty = rand() % 4 + 1;

        temp = rand() % 2 + 1;

        switch (temp)
        {
        case 1:
            this->word = animals[rand() % animals.size()];
            system("cls");
            playGame(word);
            break;
        case 2:
            this->word = food[rand() % food.size()];
            system("cls");
            playGame(word);
            break;
        case 3:
            this->word = planets[rand() % planets.size()];
            system("cls");
            playGame(word);
            break;
        }
    }
    else {
        system("cls");
        cout << "Начало игры";
        Sleep(500);
        system("cls");
        playGame(word);
    }
}

void Game::difficultyChoice()
{
    int choice = 0;
    int input;
    bool exit = false;

    system("cls");
    while (!exit)
    {

        system("cls");
        cout << "Настройка сложности игры: ";
        cout << endl;
        cout << "[1] Легко (12 попыток)" << (choice == 0 ? " >" : "") << endl;
        cout << "[2] Средне (6 попыток)" << (choice == 1 ? " >" : "") << endl;
        cout << "[3] Сложно (4 попытки)" << (choice == 2 ? " >" : "") << endl;
        cout << "[4] Невозможно (3 попытки)" << (choice == 3 ? " >" : "") << endl;

        input = _getch();

        if (input == UP && choice > 0) {
            choice--;
        }
        else if (input == DOWN && choice < 3) {
            choice++;
        }
        else if (input == ENTER) {
            switch (choice)
            {
            case 0:
                system("cls");
                cout << "Выбран режим сложности \"Легко\"" << endl;
                this->difficulty = 1;
                Sleep(250);
                wordCategoryChoice();
                break;
            case 1:
                system("cls");
                cout << "Выбран режим сложности \"Средне\"" << endl;
                this->difficulty = 2;
                Sleep(250);
                wordCategoryChoice();
                break;
            case 2:
                system("cls");
                cout << "Выбран режим сложности \"Сложно\"" << endl;
                this->difficulty = 3;
                Sleep(250);
                wordCategoryChoice();
                break;
            case 3:
                system("cls");
                cout << "Выбран режим сложности \"Невозможно\"" << endl;
                this->difficulty = 4;
                Sleep(250);
                wordCategoryChoice();
                break;
            default:
                break;
            }
        }
        else if (input == ESC)
        {
            exit = true;
        }
    }
}

void Game::wordCategoryChoice()
{
    int choice = 0;
    int input;
    bool exit = false;

    system("cls");
    while (!exit)
    {

        system("cls");
        cout << "Выберите категорию слов: ";
        cout << endl;
        cout << "[1] Животные" << (choice == 0 ? " >" : "") << endl;
        cout << "[2] Еда" << (choice == 1 ? " >" : "") << endl;
        cout << "[3] Планеты" << (choice == 2 ? " >" : "") << endl;;

        input = _getch();

        if (input == UP && choice > 0) {
            choice--;
        }
        else if (input == DOWN && choice < 3) {
            choice++;
        }
        if (input == ENTER) {
            switch (choice)
            {
            case 0:
                system("cls");
                cout << "Выбрана категория \"Животные\"" << endl;
                this->word = animals[rand() % animals.size()];
                Sleep(250);
                playGame(word);
                exit = true;
                break;
            case 1:
                system("cls");
                cout << "Выбрана категория \"Еда\"" << endl;
                this->word = food[rand() % food.size()];
                Sleep(250);
                playGame(word);
                exit = true;
                break;
            case 2:
                system("cls");
                cout << "Выбрана категория \"Планеты\"" << endl;
                this->word = planets[rand() % planets.size()];
                Sleep(250);
                playGame(word);
                exit = true;
                break;
            default:
                break;
            }
        }
        else if (input == ESC)
        {
            exit = true;
        }
    }
}

void Game::settingsChoice()
{
    int choice = 0;
    int input;
    bool exit = false;

    system("cls");
    while (!exit)
    {
        system("cls");
        cout << "Настройка сложности цвета: ";
        cout << endl;
        cout << "\nЦвет фона: \n";
        cout << "[1] Черный" << (choice == 0 ? " >" : "") << endl;
        cout << "[2] Синий" << (choice == 1 ? " >" : "") << endl;
        cout << "[3] Зеленый" << (choice == 2 ? " >" : "") << endl;
        cout << "[4] Цвет морской волны" << (choice == 3 ? " >" : "") << endl;
        cout << "[5] Красный" << (choice == 4 ? " >" : "") << endl;
        cout << "[6] фиолетовый" << (choice == 5 ? " >" : "") << endl;
        cout << "[7] Желтый" << (choice == 6 ? " >" : "") << endl;
        cout << "[8] Белый" << (choice == 7 ? " >" : "") << endl;
        cout << "[9] Серый" << (choice == 8 ? " >" : "") << endl;
        cout << "[10] Голубой" << (choice == 9 ? " >" : "") << endl;
        cout << "[11] Светло-зеленый" << (choice == 10 ? " >" : "") << endl;
        cout << "[12] Светло-голубой" << (choice == 11 ? " >" : "") << endl;
        cout << "[13] Светло-красный" << (choice == 12 ? " >" : "") << endl;
        cout << "[14] Светлофиолетовый" << (choice == 13 ? " >" : "") << endl;
        cout << "[15] Светложелтый" << (choice == 14 ? " >" : "") << endl;

        cout << "\nЦвет текста: \n";
        cout << "[1] Черный" << (choice == 15 ? " >" : "") << endl;
        cout << "[2] Синий" << (choice == 16 ? " >" : "") << endl;
        cout << "[3] Зеленый" << (choice == 17 ? " >" : "") << endl;
        cout << "[4] Цвет морской волны" << (choice == 18 ? " >" : "") << endl;
        cout << "[5] Красный" << (choice == 19 ? " >" : "") << endl;
        cout << "[6] фиолетовый" << (choice == 20 ? " >" : "") << endl;
        cout << "[7] Желтый" << (choice == 21 ? " >" : "") << endl;
        cout << "[8] Белый" << (choice == 22 ? " >" : "") << endl;
        cout << "[9] Серый" << (choice == 23 ? " >" : "") << endl;
        cout << "[10] Голубой" << (choice == 24 ? " >" : "") << endl;
        cout << "[11] Светло-зеленый" << (choice == 25 ? " >" : "") << endl;
        cout << "[12] Светло-голубой" << (choice == 26 ? " >" : "") << endl;
        cout << "[13] Светло-красный" << (choice == 27 ? " >" : "") << endl;
        cout << "[14] Светлофиолетовый" << (choice == 28 ? " >" : "") << endl;
        cout << "[15] Светложелтый" << (choice == 29 ? " >" : "") << endl;
        cout << "\n\nСбросить" << (choice == 30 ? " >" : "") << endl;
        cout << "Сохранить" << (choice == 31 ? " >" : "") << endl;

        input = _getch();

        if (input == UP && choice > 0) {
            choice--;
        }
        else if (input == DOWN && choice < 32) {
            choice++;
        }
        else if (input == ENTER) {
            switch (choice)
            {
            case 0:
                system("color 0F");
                break;
            case 1:
                system("color 1F");
                break;
            case 2:
                system("color 2F");
                break;
            case 3:
                system("color 3F");
                break;
            case 4:
                system("color 4F");
                break;
            case 5:
                system("color 5F");
                break;
            case 6:
                system("color 6F");
                break;
            case 7:
                system("color 7F");
                break;
            case 8:
                system("color 8F");
                break;
            case 9:
                system("color 9F");
                break;
            case 10:
                system("color AF");
                break;
            case 11:
                system("color BF");
                break;
            case 12:
                system("color CF");
                break;
            case 13:
                system("color DF");
                break;
            case 14:
                system("color EF");
                break;
            case 15:
                system("color 0");
                break;
            case 16:
                system("color 1");
                break;
            case 17:
                system("color 2");
                break;
            case 18:
                system("color 3");
                break;
            case 19:
                system("color 4");
                break;
            case 20:
                system("color 5");
                break;
            case 21:
                system("color 6");
                break;
            case 22:
                system("color 7");
                break;
            case 23:
                system("color 8");
                break;
            case 24:
                system("color 9");
                break;
            case 25:
                system("color A");
                break;
            case 26:
                system("color B");
                break;
            case 27:
                system("color C");
                break;
            case 28:
                system("color D");
                break;
            case 29:
                system("color E");
                break;
            case 30:
                system("color F0");
                break;
            case 31:
                mainChoiceMenu();
                break;
            }
        }
        else if (input == ESC)
        {
            exit = true;
        }
    }
}

void Game::rules() {
    int tab = 0;
    int input;
    bool exit = false;

    system("cls");
    while (!exit)
    {

        system("cls");
        cout << "Правила игры: ";
        cout << "Цель игры \"Виселица\" заключается в том, чтобы отгадать скрытое слово,\nзагаданное компьютером, путем угадывания его букв по одной.\n";
        cout << "Игрок имеет ограниченное количество попыток на угадывание букв, которые обычно\n";
        cout << "представлены в виде изображения виселицы с петлей. Каждая неудачная попытка\n";
        cout << "приводит к добавлению новой части тела человека на изображении виселицы, до тех\n";
        cout << "пор, пока не будет нарисовано полное изображение виселицы. Как только\n";
        cout << "изображение виселицы полностью нарисовано, игрок проигрывает.\n\n";
        cout << "Если игрок угадывает все буквы слова до того, как изображение виселицы будет\n";
        cout << "полностью нарисовано, он побеждает.\n\n";
        cout << "При игре в \"Виселицу\" обычно используются различные тематические категории слов,\n";
        cout << "чтобы усложнить игру и добавить интереса. Игрок может выбрать категорию слов,\n";
        cout << "которую он хочет отгадывать, или компьютер может случайным образом выбирать\n";
        cout << "слова из разных категорий.\n\n";
        cout << "\nПрочитал" << (choice == 0 ? " >" : "") << endl;

        input = _getch();

        if (input == ENTER or input == ESC) {
            switch (choice)
            {
            case 0:
                exit = true;
                break;
            }
        }
    }
}

void Game::menu()
{
    system("color F0");
    cout << "\t\t\t\t  ________       .__  .__                       \n";
    cout << "\t\t\t\t /  _____/_____  |  | |  |   ______  _  ________ \n";
    cout << "\t\t\t\t/   \\  ___\\__  \\ |  | |  |  /  _ \\ \\/ \\/ /  ___/ \n";
    cout << "\t\t\t\t\\    \\_\\  \\/ __ \\|  |_|  |_(  <_> )     /\\___ \\  \n";
    cout << "\t\t\t\t \\______  (____  /____/____/\\____/ \\/\\_//____  > \n";
    cout << "\t\t\t\t        \\/     \\/                            \\/  \n";
}

void Game::fieldDraw(vector<char>& correct, vector<char>& incorrect) {
    cout << "\nЗагаданное слово: ";
    for (int i = 0; i < correct.size(); i++)
    {
        cout << correct[i] << " ";
    }

    cout << "\nНеправильные буквы: ";
    for (int i = 0; i < incorrect.size(); i++)
    {
        cout << incorrect[i] << " ";
    }
}
 
void Game::playGame(string word)
{
    setlocale(LC_ALL, "rus");

    int wrongCount = 0;
    int wrongCountDisplay = this->maxWrongs / this->difficulty;
    char pChoice;

    vector<char> correct;
    vector<char> incorrect;

    cout << "\nНачало игры" << endl;

    for (int i = 0; i < word.size(); i++)
    {
        correct.push_back('_');
    }
    cout << endl;
    while (wrongCount < this->maxWrongs)
    {
        mciSendString(TEXT("play play.mp3 repeat"), NULL, 0, NULL);
        fieldDraw(correct, incorrect);
        cout << "\nКол - во попыток: " << wrongCountDisplay << endl;
        cout << "\nВведите букву: ";
        cin >> pChoice;
        pChoice = toupper(pChoice);
        bool isFound = false;

        for (int i = 0; i <= word.size(); i++)
        {
            if (pChoice == word[i]) {
                mciSendString(TEXT("play correct.mp3"), NULL, 0, NULL);
                correct[i] = pChoice;
                isFound = true;
                system("cls");
                menu();
                drawGallows(wrongCount);
            }
        }

        if (!isFound) {
            mciSendString(TEXT("play incorrect.mp3"), NULL, 0, NULL);

            switch (this->difficulty)
            {
            case 1:
                wrongCount++;
                break;
            case 2:
                wrongCount += 2;
                break;
            case 3:
                wrongCount += 3;
                break;
            case 4:
                wrongCount += 4;
                break;
            }

            wrongCountDisplay--;

            if (find(incorrect.begin(), incorrect.end(), pChoice) == incorrect.end())
            {
                incorrect.push_back(pChoice);
            }
            system("cls");
            menu();
            drawGallows(wrongCount);
        }

        if (find(correct.begin(), correct.end(), '_') == end(correct))
        {
            fieldDraw(correct, incorrect);
            cout << "\n\nВы победили! Загаданное слово: " << word << endl;
            mciSendString(TEXT("pause play.mp3"), NULL, 0, NULL);
            mciSendString(TEXT("play win.mp3"), NULL, 0, NULL);
            Sleep(10000);
            ExitProcess(0);
            break;
        }

        if (wrongCount == this->maxWrongs)
        {
            fieldDraw(correct, incorrect);
            cout << "\nКол - во попыток: " << wrongCountDisplay << endl;
            cout << "\n\nВы проиграли(. Загаданное слово: " << word << endl;
            mciSendString(TEXT("pause play.mp3"), NULL, 0, NULL);
            mciSendString(TEXT("play lose.mp3"), NULL, 0, NULL);
            Sleep(3000);
            ExitProcess(0);
            break;
        }
    }
}

void Game::drawGallows(int wrongCount)
{
    if (wrongCount == 0)
    {
        cout << "         \n";
        cout << "         \n";
        cout << "         \n";
        cout << "         \n";
        cout << "         \n";
        cout << "         \n";
        cout << "         \n";
    }
    if (wrongCount == 1)
    {
        cout << "          \n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
    }
    else if (wrongCount == 2)
    {
        cout << "         \n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |________\n";
    }
    else if (wrongCount == 3)
    {
        cout << "         \n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 4)
    {
        cout << "   _______\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 5)
    {
        cout << "   _______\n";
        cout << "   |      |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 6)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 7)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "   |    |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 8)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "   |\\    |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 9)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "  /|\\    |\n";
        cout << "         |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 10)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "  /|\\     |\n";
        cout << "   |     |\n";
        cout << "         |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 11)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "  /|\\    |\n";
        cout << "   |     |\n";
        cout << "    \\     |\n";
        cout << " ________|________\n";
    }
    else if (wrongCount == 12)
    {
        cout << "   _______\n";
        cout << "   |     |\n";
        cout << "   O     |\n";
        cout << "  /|\\    |\n";
        cout << "   |     |\n";
        cout << "  / \\    |\n";
        cout << " ________|________\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitle(L"Gallows");

    srand(time(NULL));

    Game g;
}