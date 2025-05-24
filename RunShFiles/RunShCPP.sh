if [ ! -f [file_name] ] || [ [file_name].cpp -nt [file_name] ]; then
        echo "Compiling..."
        start_time=$(date +%s.%N)
        if g++ [file_name].cpp -o [file_name]; then
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


# if there are multiple .cpp files to compile
g++ *.cpp -o main
# in first if statement
