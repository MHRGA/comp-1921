#!/bin/bash

echo -e "\n\n~~ Argument Tests ~~"

echo -n "Testing no arguments - "
./code > tmp
if grep -q "Usage: code <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 1 argument - "
./code maze1.txt > tmp
if grep -q "File Opened" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing 2 arguments - "
./code maze1.txt maze2.txt > tmp
if grep -q "Usage: code <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing bad maze file - "
./code maze1_bad.txt > tmp
if grep -q "Error: Bad maze file" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing empty menu input - "
echo "" | ./code maze1.txt > tmp
if grep -q "Not a valid choice. Please try again." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing bad menu input - "
echo "B" | ./code maze1.txt > tmp
if grep -q "Not a valid choice. Please try again." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing up input (W) - "
echo "W" | ./code maze1.txt > tmp
if grep -q "Moved up one space" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing down input (S) - "
echo "S" | ./code maze1.txt > tmp
if grep -q "Moved down one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing left input (A) - "
echo "A" | ./code maze1.txt > tmp
if grep -q "Moved left one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing right input (D) - "
echo "D" | ./code maze1.txt > tmp
if grep -q "Moved right one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing open map input (M) - "
echo "M" | ./code maze1.txt > tmp
if grep -q "Map: " tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing bad user input - "
./code maze1.txt < test_data/maze1_input_bad.txt > tmp
if grep -q "You have hit a wall!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing good user input - "
./code maze1.txt < test_data/maze1_input.txt > tmp
if grep -q "Congratulations! You win!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

./code maze1.txt < test_data/maze1_input.txt > tmp

echo "1" | ./code maze1.txt > tmp