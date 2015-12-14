cmake .
make
cd scheme
python3 compile.py problem.scm
cd ..
cp -f scheme/problem.bobc bin/
cp -f scheme/input.dat bin/
cd bin/
./Schemepp problem.bobc -i input.dat

