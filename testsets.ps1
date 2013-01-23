clear
echo "-------grep plop ./test_files/test.txt-------"
./Debug/grep.exe plop ./test_files/test.txt

echo "-------grep -b -n ./test_files/test.txt-------"
./Debug/grep.exe -b -n plop ./test_files/test.txt

echo "-------grep -H -b -n l3 ./test_files/test.txt-------"
./Debug/grep.exe -H -b -n l3 ./test_files/test.txt

echo "-------grep l3 -A 3 ./test_files/test.txt-------"
./Debug/grep.exe l3 -A 3 ./test_files/test.txt

echo "-------grep l3 -B 3 ./test_files/test.txt-------"
./Debug/grep.exe l3 -B 3 ./test_files/test.txt

echo "-------grep -H -r test ./test_files-------"
./Debug/grep.exe -H -r test ./test_files