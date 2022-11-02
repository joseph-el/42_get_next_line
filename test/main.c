/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:15:41 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/02 22:41:25 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GNL.h"

void    colors(int x)
{
    switch (x)
    {
    case 1 :
    printf("\033[1;31m");
        break;
    case 2 :
        printf("\033[1;33m");
        break;
    case 3 :
        printf("\033[0;32m");
    break;
    case 4 :
        printf("\033[0;34m");
    break;
    case 5 :
        printf("\033[0;35m");
    break;
    case 6 :
        printf("\033[0;36m");
    break;
    case 7 : 
        printf("\033[0;32m");
    break;
    default:
    printf("invalid color");
    };
}

void    list_tests()
{
 char    *line;
    int     fd;
    int     sp;

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 1\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    fd = open("./doc/test4.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    line = get_next_line(fd);
    colors(2);
    printf("%s",line);
    free(line);
    
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 2\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test1.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        colors(2);
        printf("%s",line);
        free(line);
    }

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 3\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test3.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        colors(2);
        printf("%s",line);
        if(!line)
            break;
        free(line);
    }
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 4\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test6.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        colors(4);
        printf("%s",line);
        free(line);
    }

        colors(7);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tALL TESTING DONE\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
}

void    bonus_tests()
{
    int fd;
    int fd1;
    int fd2;
    int fd3;
    int fd4;
    int fd5;
    char    *line;
    
    colors(5);
    puts("\n\t*******************************************");
    printf("\t\tStaritng dup files testing\n");
    puts("\t*******************************************");
    puts("\n\n");
    fd = open("./doc/test1.txt",O_RDONLY);
    fd1 = open("./doc/test2.txt",O_RDONLY);
    fd2 = open("./doc/test3.txt",O_RDONLY);
    fd3 = open("./doc/test4.txt",O_RDONLY);
    fd4 = open("./doc/test5.txt",O_RDONLY);
    fd5 = open("./doc/test6.txt",O_RDONLY);

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 1\n");
        puts("\t////////////////////////////////");
    puts("\n\n");

        line = get_next_line(fd1);
        colors(2);
        printf("line 1 in file : %s ",line);
        line = get_next_line(fd1);
        colors(2);
        printf("line 2 int file 1: %s ",line);
        
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 2\n");
        puts("\t////////////////////////////////");
    puts("\n\n");

        line = get_next_line(fd2);
        colors(2);
        printf("line 1 in file 2: %s",line);
        line = get_next_line(fd2);
        colors(2);
        printf("line 2 int file 2: %s",line);

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 3\n");
        puts("\t////////////////////////////////");
    puts("\n\n");

        line = get_next_line(fd3);
        colors(2);
        printf("line 1 in file 3: %s",line);
        line = get_next_line(fd3);
        colors(2);
        printf("line 2 int file 3: %s",line);

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 4\n");
        puts("\t////////////////////////////////");
    puts("\n\n");

        line = get_next_line(fd4);
        colors(2);
        printf("line 1 in file 4: %s",line);
        line = get_next_line(fd4);
        colors(2);
        printf("line 2 int file 4: %s",line);
        
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 5\n");
    puts("\t////////////////////////////////");
    puts("\n\n");
    
        line = get_next_line(fd5);
        colors(2);
        printf("line 1 in file 5: %s",line);
        puts("\n\n");
        line = get_next_line(fd5);
        colors(2);
        printf("line 2 int file 5: %s",line);
        free(line);
    colors(7);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tALL TESTING DONE\n");
    puts("\t////////////////////////////////");
    puts("\n\n");
}

void    sp_tests()
{
   char    *line;
    int     fd;
    int     sp;

    colors(5);
    puts("\n\t*******************************************");
    printf("\t\tStaritng dup files testing\n");
    puts("\t*******************************************");
    puts("\n\n");
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 1\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    fd = open("./doc/test6.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    line = get_next_line(fd);
    colors(2);
    printf("%s",line);
    free(line);
    
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 2\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test2.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        colors(2);
        printf("%s",line);
        free(line);
    }

    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 3\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test5.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        colors(2);
        printf("%s",line);
        free(line);
    }
    colors(1);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tTest 4\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
    
    fd = open("./doc/test1.txt",O_RDONLY);
    if (fd < 0)
    {
        colors(1);
        write(2, "open error",strlen("open error"));
        exit(-1);
    }
    while (1)
    {
        line = get_next_line(fd);
        if(!line)
            break;
        colors(4);
        printf("%s",line);
        free(line);
    }

        colors(7);
    puts("\n\n\t/////////////////////////////////");
    printf("\t\tALL TESTING DONE\n");
        puts("\t////////////////////////////////");
    puts("\n\n");
}


int main(int argn, char *args[])
{
    int     mode;
    char    *line;
    int     x = argn;
    
    mode = atoi(args[1]);
    if (mode == -1)
        {
            write(2, "prosses failed", strlen("prosses failed"));
            return (-1);
        }
    switch (mode)
    {
    case  1:
    sp_tests();
        break;
    
    case 2:
    bonus_tests();
        break;

    case 3:
    list_tests();
    break;
    default:
        colors(1);
        printf("sorry");
    break;
    }
    return (EXIT_SUCCESS);
}