# verify-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A

import sys
import os
PWD = os.path.dirname(os.path.abspath(__file__))
sys.path.append(PWD + '/../../py/example')
from hello_world import * # path: py/example/

if __name__ == "__main__":
    print(hello_world())