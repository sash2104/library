# ac-libraryは/usr/local/include以下にコピーしてある

if [[ $# -lt 1 ]] || [[ $# -gt 1 ]]; then
    echo "usage: $0 problem(a|b|c|d|...)"
    exit 1
fi

problem=$1
set -x

g++ -std=c++14 -O2 $problem.cpp -I /usr/local/include/ac-library -o $problem
