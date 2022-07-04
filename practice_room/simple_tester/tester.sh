set -e
g++ gen.cpp -o gen
> int.txt
for((i = 1; i!=100 ; ++i)); do
    ./gen $i >> int.txt
    echo "Processed test: "  $i
done
