cmake .
make
cd scheme
python3 compile.py problem.scm
cd ..
cp scheme/problem.bobc bin/
cp scheme/input.dat bin/
cd bin/
./Schemepp problem.bobc -i input.dat

