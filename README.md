## Advent Of Code 2022
###### My repo for solving advent of code in 2022 (https://adventofcode.com/2022)

---

### *`BUILD`ing*

I'm using bazel. http://bazel.build


Example:

```shell
bazel build //day02:main
```

---

### *Running*

Example:

```shell
bazel-bin/day02/main < day02/data/test_input.txt

\ Day02                                                                                                                                                     
 \  Part01 --- Total points: 15                                                                                                                             
  \ Part02 --- Total points: 12
```

---

### *Tests*

Example:

```shell
bazel test --test_output=all //day03:part01_test   

==================== Test output for //day03:part01_test:                           
Running main() from gmock_main.cc                                                   
[==========] Running 5 tests from 1 test suite.     
[----------] Global test environment set-up.                                        
[----------] 5 tests from Part01Test                                                                                                                                    
[ RUN      ] Part01Test.ScoreLetterWorksForUppercase       
[       OK ] Part01Test.ScoreLetterWorksForUppercase (0 ms)                         
[ RUN      ] Part01Test.ScoreLetterWorksForLowercase       
[       OK ] Part01Test.ScoreLetterWorksForLowercase (0 ms)                         
[ RUN      ] Part01Test.GetRucksacks                                                
[       OK ] Part01Test.GetRucksacks (0 ms)                                                                                                                             
[ RUN      ] Part01Test.FindCommonElements       
[       OK ] Part01Test.FindCommonElements (0 ms)                                   
[ RUN      ] Part01Test.ScoreRucksack                                               
[       OK ] Part01Test.ScoreRucksack (0 ms)               
[----------] 5 tests from Part01Test (0 ms total)                                   
                                                                                    
[----------] Global test environment tear-down                                  
[==========] 5 tests from 1 test suite ran. (0 ms total)                                                                                                                
[  PASSED  ] 5 tests.                                                               
================================================================================                                                                                        
//day03:part01_test                                             (cached) PASSED in 0.2s
                                                                                    
INFO: Build completed successfully, 1 total action
```
