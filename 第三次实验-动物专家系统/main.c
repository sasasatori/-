#include "tree.h"

int main()
{
    char user_choice;
    printf("welcome to the animal specialist system by satori\n");
    printf("i will guess which animal you have thought by the features you described\n");
    printf("if you want to quit the system , input 'q'\n");
    while (TRUE)
    {
        printf("input 'q' to quit , other keys to enter the system\n");
        scanf("%c",&user_choice);
        getchar();
        if(user_choice == 'q')
            return 0;
        else
            animal_sys();
    }
}