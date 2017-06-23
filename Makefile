all:
		gcc -g main.c -o t_mtrace
		export MALLOC_TRACE=/home/2017/lamark/mnm/file.txt
		./t_mtrace
		mtrace ./t_mtrace $MALLOC_TRACE


