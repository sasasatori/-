#include "lib.h"

int main()
{
  while (1)
  {
    char user_choice;
    printf("welcome to the library system of satori !\n");
    printf("please input the fuction you need\n");
    printf("(1)creat books     (2)find a book\n");
    printf("(3)output book message in the order of \n");
    printf("(4)change the message of book\n");
    printf("(5)add a book       (6)delete a book\n");
    printf("enter 'q' to quit——\n");
    user_choice = getchar();
    getchar();
    switch (user_choice)
    {
    case '1':
      load_in_information();
      break;
    
    case '2':
      search_information();
    break;

    case '3':
      output_information();
    break;

    case '4':
      change_information();
    break;

    case '5':
      add_information();
    break;

    case '6':
      delete_information();
    break;

    case 'q':
      return 0;
    break;

    default:
      printf("wrong input\n");
      break;
    }
  }
}