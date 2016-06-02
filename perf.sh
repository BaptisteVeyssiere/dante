#!/bin/bash

rougefonce='\e[0;31m'
rougeclair='\e[1;4;31m'
vertclair='\e[1;32m'
bleuclair='\e[1;34m'
bleusouligne='\e[1;4;34m'
vertfonce='\e[0;32m'
neutre='\e[0;m'

if [ $# -gt 0 ]
then
    echo -e "${vertfonce}< Bienvenue dans l'interface de test >\n${neutre}"
    make re > /dev/null
    echo -e "${vertclair}--- Les programmes ont été recompilés ---\n${neutre}"
    let "a = 3"
    while [ $a -gt 0 ]
    do
	echo -e "${bleuclair}Lancement des tests dans ${neutre}${rougefonce}$a${neutre}${bleuclair} secondes${neutre}"
	`sleep 1`
	let "a -= 1"
    done
    echo -e "\n"
    let "a = 0"
    while [ $a -lt $# ]
    do
	let "time_first = 0"
	time_first_start=`date +%s%N | cut -b1-13`
	`timeout -k 0m 10s profondeur/solver $1 > /dev/null`
	if [ "$?" -eq 124 ]
	then
	    let "time_first = -1"
	fi
	time_first_end=`date +%s%N | cut -b1-13`
	let "time_second = 0"
	time_second_start=`date +%s%N | cut -b1-13`
	`timeout -k 0m 10s largeur/solver $1 > /dev/null`
	if [ "$?" -eq 124 ]
        then
            let "time_second = -1"
        fi
	time_second_end=`date +%s%N | cut -b1-13`
	let "time_third = 0"
	time_third_start=`date +%s%N | cut -b1-13`
        `timeout -k 0m 10s astar/solver $1 > /dev/null`
	if [ "$?" -eq 124 ]
        then
            let "time_third = -1"
        fi
        time_third_end=`date +%s%N | cut -b1-13`
	echo -e "${bleusouligne}Résultats pour la map $1:\n${neutre}"
	if [ $time_first -eq 0 ]
	then
	    let "time_first = time_first_end - time_first_start"
	    let "s_first = time_first / 1000"
	    let "ms_first = time_first - 1000 * s_first"
	    echo -e "Voici les résultats de l'algo profondeur:\n${vertclair}$s_first s et $ms_first ms${neutre}\n"
	else
	    echo -e "${rougeclair}L'algo profondeur a timeout après 10s\n${neutre}"
	fi
	if [ $time_second -eq 0 ]
	then
	    let "time_second = time_second_end - time_second_start"
	    let "s_second = time_second / 1000"
	    let "ms_second = time_second - 1000 * s_second"
	    echo -e "Voici les résultats de l'algo largeur:\n${vertclair}$s_second s et $ms_second ms${neutre}\n"
	else
            echo -e "${rougeclair}L'algo largeur a timeout après 10s\n${neutre}"
	fi
	if [ $time_third -eq 0 ]
	then
	    let "time_third = time_third_end - time_third_start"
	    let "s_third = time_third / 1000"
	    let "ms_third = time_third - 1000 * s_third"
	    echo -e "Voici les résultats du Astar:\n${vertclair}$s_third s et $ms_third ms${neutre}\n"
	else
            echo -e "${rougeclair}L'algo astar a timeout après 10s\n${neutre}"
	fi
	shift
    done
else
    echo -e "Veuillez entrez en paramètres les labyrinthes que vous souhaitez voir testés"
fi
