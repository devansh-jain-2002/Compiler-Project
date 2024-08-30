./milestone3 --input=$1 --output=$1.s
gcc $1.s -o $1.o -no-pie
./$1.o
