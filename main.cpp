#include <iostream>
using namespace std;
#include "Queque.h"
#include "ArraySequence.h"
#include "Student.h"
#include "tests.h"

int dialog (const char *msgs[], int n)
{
    int choice;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        printf("> ");

        choice = getchar() - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

    } while (choice < 0 || choice >= n);

    return choice;
}

const char *MENU[] = {"0. Exit",
                      "1. tests",
                      "2. work"};
const int MENU_SIZE = sizeof(MENU) / sizeof(MENU[0]);

const char *MENU_TESTS[] = {"0. Exit",
                            "1. int",
                            "2. float",
                            "3. complex",
                            "4. char",
                            "5. functions",
                            "6. person"};
const int MENU_SIZE_TESTS = sizeof(MENU_TESTS) / sizeof(MENU_TESTS[0]);

int main() {
    int menu;
    do {
        menu = dialog(MENU, MENU_SIZE);
        switch (menu) {
            case 0:
                break;
            case 1: {
                int tmenu;
                do {
                    tmenu = dialog(MENU_TESTS, MENU_SIZE_TESTS);
                    switch (tmenu) {
                        case 0:
                            break;
                        case 1: {
                            testIntQueque();
                        }
                            break;
                        case 2: {
                            testRealQueque();
                        }
                            break;
                        case 3: {
                            testComplexQueque();
                        }
                            break;
                        case 4: {
                            testCharQueque();
                        }
                            break;
                        case 5: {
                            cout << "coming soon" << endl;
                        }
                            break;
                        case 6: {
                            cout << "not all work" << endl;
                            testPersonQueque();
                        }
                            break;
                    }
                } while (tmenu);
            }
                break;
            case 2:
                break;
        }
    } while (menu);
    return 0;
}
