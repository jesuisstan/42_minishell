# !/bin/bash
while true; do
	minishell_pid=$(pgrep minishell)
	if [ -n "$minishell_pid" ]
	then
		leaks_result=$( leaks -q --list minishell ) 
		lsof_result=$( lsof -p $minishell_pid )
		processes=$(ps)
		echo "                                 LEAKS CHECK"
		echo "$leaks_result"
		echo "                                 FD CHECK"
		echo "$lsof_result"
		echo "                                 PROCESSES"
		echo "$processes"
	fi
	sleep 3
	clear
done
