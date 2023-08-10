#include <stdio.h>
#include <unistd.h>
#include <string.h>

int check_brackets(char *s);
int is_balanced(char *str);

int main(int argc, char ** argv)
{
    int i;

    i = 1;
    if (argc < 2)
        return (write(1, "\n", 1));
    while (argv[i])
    {
        if (is_balanced(argv[i]))
            write(1, "OK\n", 3);
        else
            write(1, "Error\n", 6);
        i++;
    }
}

int is_balanced(char *str) {
  // Create a stack to store the opening brackets.
  char stack[100];
  int top = -1;

  // Iterate over the string.
  for (int i = 0; i < strlen(str); i++) {
    // If the current character is an opening bracket, push it onto the stack.
    if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
      stack[++top] = str[i];
    } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
      // If the current character is a closing bracket, check if it matches the top of the stack.
      if (top == -1 || (str[i] == ')' && stack[top] != '(') ||
          (str[i] == '}' && stack[top] != '{') || (str[i] == ']' && stack[top] != '[')) {
        return 0;
      }

      // Pop the top of the stack.
      top--;
    }
  }

  // If the stack is empty, then the brackets are balanced.
  return top == -1;
}


// int find_cl_br(char *s, int i, int flag)
// {
//     while (s[i])
//     {
//         if (s[i] == '(')
//         {
//             if (find_cl_br(s, i, 1) == -1)
//                 return (-1);
//         }
//         else if(s[i] == '{')
//         {
//             if (find_cl_br(s, i, 2) == -1)
//                 return (-1);
//         }
//         else if (s[i] == '[')
//         {
//             if (find_cl_br(s, i, 3) == -1)
//                 return (-1);
//         }
//         else if (s[i] == '(' && flag == 1)
//             return (i);
//         else if (s[i] == '{' && flag == 2)
//             return (i);
//         else if (s[i] == '[' && flag == 3)
//             return (i);
//         i++;
//     }
//     return (-1);
// }