//
// Created by Satori on 2019/5/26.
//

#include "stack.h"

int main()
{
    char user_input[MAX_LENGTH];
    while(TRUE)
    {
        printf("this the calculator created by satori\n");
        printf("please input your equation end with a '#'\n");
        printf("don't support float input\n");
        printf("input 'q' to quit the program\n");
        scanf("%s",user_input);

        if(user_input[0] == 'q')
            return 0;
        else
            printf("the result is %d\n",calculator(user_input)-'0');
        getchar();
    }
}