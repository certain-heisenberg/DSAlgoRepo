set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > int.txt
    ./code < int.txt > myAnswer.txt
    ./brute < int.txt > correctAnswer.txt
    diff -Z myAnswer.txt correctAnswer.txt > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat int.txt
echo "Your answer is:"
cat myAnswer.txt
echo "Correct answer is:"
cat correctAnswer.txt
