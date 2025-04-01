This repository tries to contrast what code looks like in competitive programming and in software engineering.

I solve [this](https://codeforces.com/contest/1368/problem/E) from a CodeForces round from 2019 / 2020. In the cp/ directory there is the [solution][https://codeforces.com/contest/1368/submission/84244280] I used for this problem when I solved it during the contest many years ago. In the swe/ directory is how I would solve the problem after working as a software engineer for nearly two years.

Note, in particular:

1. The problem has been split into multiple files.
2. There are better data abstractions.
3. The use of the makefile to build the binaries.
4. Unit tests.
5. Code comments.
6. Descriptive variable names.

Of course, we can go much further, for example I am missing a .gitignore file, I'm using plain old make instead of something more advanced like CMake, the Makefile does not even have dependencies specified (facepalm) and I'm sure you can point out many more deficiencies in my swe code, but I think it's a decent example.
