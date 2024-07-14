#!/bin/bash

cd cat/
bash test_func_cat.sh &> result_cat.txt
result_cat=$(grep -c "FAILED" result_cat.txt)
if [ "$result_cat" -ne 0 ]; then
    exit 1
fi
rm -rf result_cat.txt
cd ../grep
bash test_run_grep.sh &> result_grep.txt
result_grep=$(grep -c "FAILED" result_grep.txt)
if [ "$result_grep" -ne 0 ]; then
    exit 1
fi
rm -rf result_grep.txt