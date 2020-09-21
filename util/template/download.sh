#!/bin/bash

set -e
if [[ $# -lt 1 ]] || [[ $# -gt 1 ]]; then
    echo "usage: $0 url(https://atcoder.jp/contests/abc172) [to](f)"
    exit 1
fi
from="a"
to="f"
url=$1
if [[ $# -eq 2 ]]; then
    to=$2
fi

contest=$(basename ${url})  # e.g., abc172
urlbase="$url/tasks/$contest"

set -x
for problem in $(eval echo {$from..$to})
do
    problem_dir="$contest/$problem"
    download_url="${urlbase}_$problem"
    mkdir -p $problem_dir
    oj download $download_url -d $problem_dir
done
