#create a python script to remove the .exe files from the directory

import os
import shutil

def remove_exe():
    #get the current working directory
    cwd = os.getcwd()
    #get the list of files in the directory
    files = os.listdir(cwd)
    #iterate through the files
    for file in files:
        #check if the file is a .exe file
        if file.endswith('.exe'):
            #remove the file
            os.remove(file)
            print(f'{file} has been removed')



def main():

    remove_exe()

if __name__ == '__main__':

    main()




