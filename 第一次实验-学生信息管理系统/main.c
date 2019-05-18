#include "APIs.h"

int main()
{
    while(1) {
        char user_choice;
        printf("this is a student information control system created by satori\n");
        printf("it can provide the following functions--\n");
        printf("(1)load in information\t(2)add information\n");
        printf("(3)change information\t(4)delete information\n");
        printf("(5)search information\t(6)output information\n");
        printf("(7)exit the program\n");
        printf("please input number 1-7 to choose corresponding function\n");
        user_choice = getchar();
        getchar();
        switch (user_choice) {
            case '1':
            {
                printf("load in information :>\n");
                load_in_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                break;
            }

            case '2':
            {
                printf("add information :>\n");
                add_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                break;
            }

            case '3':
            {
                printf("change information :>\n");
                change_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                break;
            }

            case '4':
            {
                printf("delete information :>\n");
                delete_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                break;
            }

            case '5':
            {
                printf("search information :>\n");
                search_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                getchar();
                break;
            }

            case '6':
            {
                printf("output information :>\n");
                output_information();
                printf("done\n");
                printf("press any to continue\n");
                getchar();
                break;
            }

            case '7':
            {
                printf("press any key to exit the program :>");
                getchar();
                return 0;
            }

            default:
            {
                printf("input error,please input number 1-7 again :<\n");
            }
            break;
        }
        system("clear");
    }
}