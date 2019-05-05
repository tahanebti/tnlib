
file=$1
command="clang++ -o prgm.run -I ./ --std=c++14 \"${file}\" && ./prgm.run"
printf "Running \"${command}\":\n"
eval $command

