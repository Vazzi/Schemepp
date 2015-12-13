cmake .
make
cd scheme
python3 compile.py program.scm
cd ..
cp -f scheme/program.bobc bin/
cp -f scheme/input.dat bin/
cd bin/
./Schemepp program.bobc -i input.dat

