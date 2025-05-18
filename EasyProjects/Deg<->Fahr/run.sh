    if [ ! -f main ] || [ main.cpp -nt main ]; then
        echo "Compiling..."
        start_time=$(date +%s.%N)
        if g++ main.cpp -o main; then
            end_time=$(date +%s.%N)
            compile_time=$(echo "$end_time - $start_time" | bc)
            echo "✅ Compilation successful in ${compile_time}s"
            ./main
        else
            echo "❌ Compilation failed"
        fi
    else
        ./main
    fi
