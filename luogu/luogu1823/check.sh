
BOLD=`tput bold`
RED="\033[31m${BOLD}"
GREEN="\033[32m${BOLD}"
DGREEN="\033[0;32m"
RESET="\033[0m"
WA_CNT=1
TESTCASE=1

g++ std.cpp -o std
echo ${GREEN} ✔ Compile: Success${RESET}
g++ luogu1823.cpp -o luogu1823
echo ${GREEN} ✔ Compile: Success${RESET}
g++ gen.cpp -o gen
echo ${GREEN} ✔ Compile: Success${RESET}

while true; do
    if [ ${WA_CNT} -gt 100 ]; then
        echo ${RED} ✘ THE STD IS BULLSHIT!!!${RESET}
        exit 1
    fi

    if ./gen; then
        echo ${DGREEN} ✔ Generator: Success${RESET}
    else
        echo ${RED} ✘ Generator: Failure${RESET}
        exit 1
    fi

    if ./luogu1823; then
        echo ${DGREEN} ✔ Brute force: Success${RESET}
    else
        echo ${RED} ✘ Brute force: Failure${RESET}
    fi

    if ./std; then
        echo ${DGREEN} ✔ std: Success${RESET}
    else
        echo ${RED} ✘ std: Failure${RESET}
    fi

    if diff luogu1823.out std.out; then 
        echo "${GREEN}${BOLD} ✔ Accepted${RESET} on Test ${BOLD}#${TESTCASE}${RESET}"
    else
        echo "${RED}${BOLD} ✘ Wrong Answer${RESET} on Test ${BOLD}#${TESTCASE}${RESET} (${WA_CNT} time(s))"
        cp in.in wa${WA_CNT}.in
        WA_CNT=$((${WA_CNT}+1))
		exit
    fi

    TESTCASE=$((${TESTCASE}+1))
done
