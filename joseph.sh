# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    joseph.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 22:16:58 by yoel-idr          #+#    #+#              #
#    Updated: 2022/11/02 22:16:59 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

read VAR

EMOJI="
+⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀ ⣀⣀⣤⣤⣤⣀⡀
+⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀
+⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆
+⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆
+⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
+⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠸⣼⡿
+⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉
"
#
#for i in $@
#do
#	if [ "$i" -eq 0]
#	then
#		make clean
#	fi
#	if [ "$i" = 1 ] || [ "$i" = 2 ] || [ "$i" = 3 ]
#	then
#		cd test && make sp#
#	fi
#done

if [[ $VAR -eq 1 ]]
then
	reset
	echo "\033[1;34mRuning get_next_line sp test......."
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m\n"
	cd test && make sp && ./run 1

elif [[	$VAR -eq 2	]]
	then
	reset
	echo "\033[1;34mRuning get_next_line bonus multiple files......."
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m\n"
	cd test && make bonus && ./run 2

elif [[	$VAR -eq 3	]]
	then
	reset
	echo "\033[1;34mRuning get_next_line with Linked list.............."
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m"
	echo "\033[1;31m\nWaiting\033[0;0m\n"
	cd test && make bonus && ./run 3
elif [[	$VAR -eq 0	]]
	then
	reset
	echo "\033[1;31m\nWaiting..\033[0;0m"
	echo "\033[1;31m\nWaiting..\033[0;0m"
	echo "\033[1;31m\nWaiting..\033[0;0m"
	echo "\033[1;31m\nWaiting..\033[0;0m"
	cd test && make clean
else
	echo "not task found !"
fi
	echo "\033[1;31m\nby Joseph.\033[0;0m"