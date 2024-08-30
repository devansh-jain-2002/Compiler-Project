#!/bin/bash

VERBOSE=0
flag_o=0
flag_i=0

help ()
{
echo "

### HELP MESSAGE ###

Usage:
 ./run.sh [options] <inputfile> <outputfile>

Options:
 -h,--help                     display help
 -v,--verbose                  enable verbose
 -i,--input <inputfile>        enter the input python file <inputfile>
 -o,--output <outputfile>      enter the output AST pdf as <outputfile>
 

Example:
 ./run.sh example1.py Tree.pdf
 ./run.sh -v --input example1.py -o Tree.pdf
"

}

TEMP=$(getopt -o 'hvi:o:' --long 'help,verbose,input:,output:' -n 'run.sh' -- "$@")

if [ $? -ne 0 ]; then
	help
	echo 'Terminating...' >&2
	exit 1
fi

eval set -- "$TEMP"
unset TEMP

while true; do
	case "$1" in
        '-h'|'--help')
            help
			shift
			exit 0
		;;
		'-i'|'--input')
			flag_i=1
			INPUT_FILE=$2
			shift 2
			continue
        ;;
		'-o'|'--output')
			flag_o=1
			OUTPUT_FILE=$2
			shift 2
			continue
		;;
		'--')
			shift
			break
		;;
		'-v'|'--verbose')
            VERBOSE=1
			shift
			continue
		;;
		*)
			echo 'error!!' >&2
			exit 1
		;;
	esac
done

remaining_files=0
if [ $flag_i -eq 0 ]; then
	let "remaining_files=remaining_files+1"
fi
if [ $flag_o -eq 0 ]; then
	let "remaining_files=remaining_files+1"
fi
if [ $# -ne $remaining_files ]; then
	help
	echo 'Terminating...' >&2
	exit 1
fi

if [ $remaining_files -eq 1 ]; then
	if [ $flag_o -eq 0 ]; then
		OUTPUT_FILE=$1
	fi
	if [ $flag_i -eq 0 ]; then
		INPUT_FILE=$1
	fi
fi
if [ $remaining_files -eq 2 ]; then
	INPUT_FILE=$1
	OUTPUT_FILE=$2
fi
cd src
make
cd ..
src/parser_exec $INPUT_FILE $VERBOSE
dot -Tpdf AST.dot -o $OUTPUT_FILE