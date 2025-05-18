    if [ ! -f [file_nmae] ] || [ [file_name].cpp -nt [file_name] ] || [ [c_file].c -nt [file_name] ]; then
        echo "Compiling..."
        start_time=$(date +%s.%N)
        if g++ [file_name].cpp [c_file].c -o [file_name]; then
            end_time=$(date +%s.%N)
            compile_time=$(echo "$end_time - $start_time" | bc)
            echo "✅ Compilation successful in ${compile_time}s"
            ./[file_name]
        else
            echo "❌ Compilation failed"
        fi
    else
        ./[file_name]
    fi
