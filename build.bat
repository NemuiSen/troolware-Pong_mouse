@echo off
bash -c "echo -e '\033[32mCMake\033[33m'"
cmake -G"Ninja" -B"./build/cmake"
bash -c "echo -e '\033[32mNinja\033[36m'"
cd ./build/cmake && ninja
bash -c "echo -e '\033[32mTerminado\033[0m'"
cd ../../