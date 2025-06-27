#include <stdio.h>
#include <string.h>

void newLine(FILE *fp, const char *str) {
    const char *p = str;
    int start_of_line = 1;  

    while (*p) {
        if (start_of_line) {
            fprintf(fp, "\t");  
            start_of_line = 0;
        }

        if (strncmp(p, "(empty)", 7) == 0) {
            fprintf(fp, "\n"); 
            p += 7;
            start_of_line = 1; 
        } else {
            fputc(*p, fp);
            p++;
        }
    }
    fprintf(fp, "\n");
}


int main(int argc, char *argv[]) {

  if (argc == 1) {

    printf("makefile is is a Makefile creator. type 'makefile help' to get started.\n");
  }

  if (argc == 2 && strcmp(argv[1], "help") == 0) {

    printf("this is the makefile help page.\n\n");
    printf("  'makefile'         - shows what this tool is.\n");
    printf("  'makefile help'    - prints this.\n");
    printf("  'makefile example' - it gives you a very basic Makefile example.\n");
    printf("  'makefile guide'   - it's just a very easy guide on how to create one.\n");
    printf("  'makefile create'  - guided creation of a Makefile.\n");
  }

  else if (argc == 2 && strcmp(argv[1], "example") == 0) {

    printf("install:\n"
           "  gcc try.c -o try\n\n"
           "uninstall:\n"
           "  rm try\n\n"
           "clean:\n"
           "  rm try"
           "  gcc try.c -o try\n"
          );
  }

  else if (argc == 2 && strcmp(argv[1], "guide") == 0) {

    printf("welcome in the guide, here we visit how to create a good and readable Makefile.\n"
           "first of all we can say the NAME of the file. to do that, simply type in your Makefile: 'NAME = try.c' .c because in this example the try file is written in C.\n"
           "then we can say the name of the output (executable). to do that, as before, we have to do: 'OUTPUT = try'.\n"
           "then we must specify the commands we'd like to do. for example, if you want to do in the shell 'make install' we should do:\n\n"
           "install:\n  gcc $(NAME) -o $(OUTPUT)'\n  sudo cp $(OUTPUT) /usr/bin/\n\nthe OUTPUT can now be runned as a command, so 'try'.\n"
           "now that you understood the basis, i guess you can do the 'make uninstall' and the 'make clean', if you want to understand better, type 'makefile example' to see an example \n"
           );
  }

  else if (argc == 2 && strcmp(argv[1], "create") == 0) {

    char install_command[256];
    char uninstall_command[256];
    char clean_command[256];

    printf("\nWelcome, this is an automated Makefile creation (for lazy people)\n\n(empty) will mean newline\n\n");
    printf("Choose the commands you wanna do when 'make install'\n > ");
    scanf(" %255[^\n]", install_command);
    printf("Choose the commands you wanna do when 'make uninstall'\n > ");
    scanf(" %255[^\n]", uninstall_command);
    printf("Choose the commands you wanna do when 'make clean'\n > ");
    scanf(" %255[^\n]", clean_command);

    FILE *fp = fopen("Makefile", "w");

    fprintf(fp, "install:\n");
    newLine(fp, install_command);

    fprintf(fp, "\nuninstall:\n");
    newLine(fp, uninstall_command);

    fprintf(fp, "\nclean:\n");
    newLine(fp, clean_command);

    fclose(fp);

    printf("\nMakefile created! Try to read it with 'cat Makefile'\n");
  }

  return 0;
}
