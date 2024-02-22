#!/bin/bash

#Code adapted from if statement used in week 2 testing https://github.com/uol-feps-soc-comp1921-2324-classroom/week-2-testing-MHRGA
echo -e "\n\n~~ Argument Tests ~~"

#Testing how the program runs when no files are passed in as CLAs
echo -n "Testing no arguments - "
./code > tmp
if grep -q "Usage: code <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing how the program runs when one file is passed in as a CLA
echo -n "Testing 1 argument - "
./code maze1.txt > tmp
if grep -q "File Opened" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing how the program runs when two files are passed in as CLAs
echo -n "Testing 2 arguments - "
./code maze1.txt maze2.txt > tmp
if grep -q "Usage: code <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing how the progam reacts to being given a maze that doesn't meet conditions for valid maze
echo -n "Testing bad maze file - "
./code maze1_bad.txt > tmp
if grep -q "Error: Bad maze file" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing how program reacts to when an empty input is given by user. Should prompt user to try again.
echo -n "Testing empty menu input - "
echo "" | ./code maze1.txt > tmp
if grep -q "Not a valid choice. Please try again." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing how program reacts to when an invalid input is given by user. Should prompt user to try again.
echo -n "Testing bad menu input - "
echo "B" | ./code maze1.txt > tmp
if grep -q "Not a valid choice. Please try again." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing if program has successfully responded and moved character up. Should be displayed after function to move character is complete
echo -n "Testing up input (W) - "
echo "W" | ./code maze1.txt > tmp
if grep -q "Moved up one space" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing if program has successfully responded and moved character down. Should be displayed after function to move character is complete
echo -n "Testing down input (S) - "
echo "S" | ./code maze1.txt > tmp
if grep -q "Moved down one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing if program has successfully responded and moved character left. Should be displayed after function to move character is complete
echo -n "Testing left input (A) - "
echo "A" | ./code maze1.txt > tmp
if grep -q "Moved left one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing if program has successfully responded and moved character right. Should be displayed after function to move character is complete
echo -n "Testing right input (D) - "
echo "D" | ./code maze1.txt > tmp
if grep -q "Moved right one place" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing if program has successfully responded and opened map. Should be displayed after function to open map is complete
echo -n "Testing open map input (M) - "
echo "M" | ./code maze1.txt > tmp
if grep -q "Map: " tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing user input which constantly hits walls and never reaches the 
echo -n "Testing bad user input - "
./code maze1.txt < test_data/maze1_input_bad.txt > tmp
if grep -q "You have hit a wall!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

#Testing successful maze path in valid maze which is how end user experience should look like
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