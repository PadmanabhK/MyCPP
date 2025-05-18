    if [ ! -f main ] || [ main.cpp -nt main ]; then
        g++ main.cpp -o main && ./main
    else
        ./main
    fi
