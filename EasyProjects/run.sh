# To Run a .cpp in this repo:

# If you're in VScode - just install code runner and run the file


# If not, Do this:
# 1) Non-SFML one ( normal cpp file) - add this into run.sh file and run the file
g++ [filename].cpp -o [filename] && ./[filename]



# 2) SFML One - these two below lines belong to run.sh file - run that run.sh file in terminal
g++ -c [filename].cpp     # file with event loop
g++ [filename].o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

# after running - a new file named sfml-app will be created - run this file
# you'll see SFML in actionw
