#!/bin/bash

# TUI for learning gtest

RED="\e[31m"
GREEN="\e[32m"
YELLOW="\e[33m"
BLUE="\e[34m"
CYAN="\e[36m"
RESET="\e[0m"

# alternate buffer and set position and disable flashing
printf "\e[?1049h\e[H\e[?25l"

# Set up a trap to restore the terminal state on exit
trap 'printf "\e[?1049l\e[?25h"; exit' INT TERM EXIT

# print the progress function:
progress() {
	local progress=$1
	local total=6

	local percent=$((progress * 100 / $total))
	local filled_length=$((percent * 30 / 100))
	local empty_length=$((30 - $filled_length))

	printf "\r${CYAN}Progress:${RESET} ["
	for ((i = 0; i < $filled_length; i++)); do
		printf "${GREEN}#${RESET}"
	done
	for ((i = 0; i < $empty_length; i++)); do
		printf "${RED}-${RESET}"
	done
	printf "] ${YELLOW}%d%%${RESET}" "$percent"
}

progress=0
while true; do
	clear
	if [ $progress -ge 6 ]; then
		printf "\n${GREEN}Congratulations! You have completed all exercises.${RESET}\n${BLUE}"

		read -p "Press enter to exit..." input

		printf "${RESET}\e[?1049l\e[?25h"

		exit 0
	fi

	progress $progress
	printf "\n\n${CYAN}Welcome to the gtest learning TUI!${RESET}\n"

	printf "${YELLOW}You are currently doing excercise %d.${RESET}\n${BLUE}" "$progress"

	read -p "Press enter to check your progress..." input

	printf "${RESET}\n"

	error="$(make "ex0$progress" 2>&1)"

	if [ $? -ne 0 ]; then
		printf "\n${RED}You have failed the exercise. Please try again.${RESET}\n${BLUE}"

		read -p "Press enter to see the error message (then press q to retry)..." input

		printf "${RESET}\n"

		echo "$error" | less -R

		continue
	fi

	./"ex0$progress"

	if [ $? -ne 0 ]; then
		printf "\n${RED}You have failed the exercise. Please try again.${RESET}\n${BLUE}"

		read -p "Press enter to see the error message (then press q to retry)..." input

		printf "${RESET}\n"

		echo "$error" | less -R

		continue
	fi

	printf "\n${GREEN}Congratulations! You have completed the exercise %d.${RESET}\n${BLUE}" "$progress"

	read -p "Press enter to continue to the next exercise..." input

	printf "${RESET}\n"

	progress=$((progress + 1))
done
