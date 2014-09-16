#!/usr/bin/env python2

import os, commands, getpass, shutil

HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKGREEN = '\033[92m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'

red, blue, green, normal = "red", "blue", "green", "normal"

def pcolor(text, color):
    if color == "red":
        print FAIL + text + ENDC + "   ",
    elif color == "blue":
        print OKBLUE + text + ENDC + "   ",
    elif color == "green":
        print OKGREEN + text + ENDC  + "   ",
    elif color == "normal":
        print text  + "   ",

def getElementsForLS(path):
    contents = os.listdir(path)
    output = []
    for content in contents:
        if not content.startswith('.'):
            output.append(content)
    return sorted(output, key=lambda s: s.lower())

def ls(command):
    detailedList, toPrint = [], []
    cmdLen = len(command)
    if cmdLen == 1:
        toPrint = getElementsForLS('.')
        for element in toPrint:
            if os.path.isdir(element):
                pcolor(str(element), blue)
            elif 'x' in commands.getstatus(element)[0:10]:
                pcolor(str(element), green)
            else:
                pcolor(str(element), normal)
        print
    elif cmdLen == 2:
        if command[1] == "-l":
            elements = getElementsForLS('.')
            for element in elements:
                detailedList.append(commands.getstatus(element))
            for element in detailedList:
                if element.startswith('d'):
                    pcolor(str(element), blue)
                elif 'x' in element[0:10]:
                    pcolor(str(element), green)
                else:
                    pcolor(str(element), normal)
                print
        else:
            try:
                path = command[1]
                if not path.endswith('/'):
                    path += '/'
                toPrint = getElementsForLS(path)
                for element in toPrint:
                    if commands.getstatus(path + element).startswith('d'):
                        pcolor(str(element), blue)
                    elif 'x' in commands.getstatus(path + element)[0:10]:
                        pcolor(str(element), green)
                    else:
                        pcolor(str(element), normal)
                print
            except:
                pcolor("wrong directory", red)
                print
    elif cmdLen == 3:
        try:
            if command[1] == '-l':
                path = command[2]
            else:
                path = command[1]
            if not path.endswith('/'):
                path += '/'
            if os.path.isdir(path):
                elements = getElementsForLS(path)
                for element in elements:
                    detailedList.append(commands.getstatus(path + element))
                for element in detailedList:
                    if element.startswith('d'):
                        pcolor(str(element), blue)
                    elif 'x' in element[0:10]:
                        pcolor(str(element), green)
                    else:
                        pcolor(str(element), normal)
                    print
            elif os.path.isfile(path):
                output = commands.getstatus(path)
                if output.startswith('d'):
                    pcolor(str(element), blue)
                elif 'x' in output[0:10]:
                    pcolor(str(element), green)
                else:
                    pcolor(str(element), normal)
        except:
            pcolor("wrong syntax", red)
            print

def cd(command):
    cmdLen = len(command)
    if cmdLen == 1:
        homeDir = os.path.expanduser('~')
        os.chdir(homeDir)
    elif cmdLen == 2:
        try:
            location = command[1]
            if location == '~':
                location = os.path.expanduser(location)
            os.chdir(location)
        except:
            pcolor(location + " does not exist", red)
            print

def rm(command):
    cmdLen = len(command)
    if cmdLen not in [2, 3]:
        pcolor("wrong command", red)
        print
    elif cmdLen == 2:
        arg = command[1]
        try:
            os.remove(arg)
        except:
            pcolor("invalid file name or directory", red)
            print
    elif cmdLen == 3:
        flag, dirToDelete = command[1], command[2]
        if flag == '-r':
            if os.path.isdir(dirToDelete):
                shutil.rmtree(dirToDelete)
            else:
                try:
                    os.remove(dirToDelete)
                except:
                    pcolor("invalid file name", red)
                    print
        else:
            pcolor("wrong flag", red)
            print

def cp(command):
    cmdLen = len(command)
    if cmdLen not in [3, 4]:
        pcolor("wrong command", red)
        print
    elif cmdLen == 3:
        fileToCopy, destination = command[1], command[2]
        if os.path.isfile(fileToCopy):
            try:
                shutil.copy(fileToCopy, destination)
            except:
                pcolor("invalid destination", red)
                print
        else:
            pcolor("invalid file name", red)
            print
    elif cmdLen == 4:
        flag, fileOrDirToCopy, destination = command[1:4]
        if flag == '-r':
            if os.path.isfile(fileOrDirToCopy):
                try:
                    shutil.copytree(fileOrDirToCopy, destination)
                except:
                    pcolor("invalid destination", red)
                    print
            elif os.path.isdir(fileOrDirToCopy):
                try:
                    lastSrc = fileOrDirToCopy.split('/')[-1]
                    if destination.split('/')[-1] != lastSrc:
                        destination += ('/' + lastSrc)
                    shutil.copytree(fileOrDirToCopy, destination)
                except:
                    pcolor("invalid destination", red)
                    print
            else:
                pcolor("invalid source/destination", red)
                print
        else:
            pcolor("invalid flag", red)
            print

def mv(command):
    cmdLen = len(command)
    if cmdLen == 3:
        source, destination = command[1:3]
        try:
            shutil.move(source, destination)
        except:
            pcolor("wrong source or destination", red)
            print
    else:
        pcolor("wrong syntax", red)
        print

def dirstr(directory):
    for dirName, subDirectories, files in os.walk(directory):
        level = dirName.replace(directory, '').count(os.sep)
        print level * '  ',
        print '|'
        print level * '  ',
        print "#-------------------- Folder Name: " + dirName.split('/')[-1] + " --------------------#"
        if not len(os.listdir(dirName)):
            print (level + 1) * '  ',
            print "EMPTY FOLDER"
        for file in files:
            if not file.startswith('.'):
                print (level + 1) * '    ',
                print '|'
                print (level + 1) * '    ',
                print "#-" + file

def history(command, prevCmd):
    cmdLen = len(command)
    if cmdLen == 1:
        for index in range(len(prevCmd)):
            print index + 1, prevCmd[index]
        return prevCmd
    elif cmdLen == 2:
        arg = command[1]
        if arg == '-c':
            return []

def acceptCommand(prevCmd):
    CLItMsg = OKBLUE + '[' + ENDC + OKBLUE + getpass.getuser() + ENDC + OKGREEN + '@' + ENDC + WARNING + os.getcwd().split('/')[-1] + ENDC + WARNING + ']' + ENDC + ' $ '
    command = raw_input(CLItMsg)
    prevCmd.append(command)
    command = command.split()
    baseCommand = command[0]
    if baseCommand == "ls":
        ls(command)
    elif baseCommand == "cd":
        cd(command)
    elif baseCommand == "rm":
        rm(command)
    elif baseCommand == "cp":
        cp(command)
    elif baseCommand == "mv":
        mv(command)
    elif baseCommand == "dirstr":
        dirstr(os.getcwd())
    elif baseCommand == "history":
        prevCmd = history(command, prevCmd)
    elif baseCommand == "exit":
        quit()
    return prevCmd

if __name__ == "__main__":
    prevCmd = []
    while True:
        prevCmd = acceptCommand(prevCmd)
