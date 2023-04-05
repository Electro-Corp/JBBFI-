# compile jbbvm

#cd src
#cd jbbvm
#g++ *.cpp -o jbbvm

# compile dk


g++ src/jbbdk/*.cpp -o jbb
./jbb examples/demo.jbbfi
