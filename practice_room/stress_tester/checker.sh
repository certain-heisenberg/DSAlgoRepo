set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
g++ checker.cpp -o checker
for((i = 1; ; ++i)); do
    ./gen $i > int.txt
    ./code < int.txt > myAnswer.txt
    ./brute < int.txt > correctAnswer.txt
    ./checker > checkerlog.txt
    echo "Passed test: "  $i
done
