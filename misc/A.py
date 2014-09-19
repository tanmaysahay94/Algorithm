#!/usr/bin/env python2

from random import randint, choice
import os

HEADER = '\033[95m'
OKBLUE = '\033[94m'
OKGREEN = '\033[92m'
WARNING = '\033[93m'
FAIL = '\033[91m'
ENDC = '\033[0m'

numberOfCol = 35
numberOfRow = 15
ghostNum = 10
coinNum = 20
wallNum = 20

class Person:
    validInputs = ['w', 'a', 's', 'd', 'q', 'W', 'A', 'S', 'D', 'Q']
    def __init__(self):
        self.x = 0
        self.y = 0

    def move(self, userInput):
        if userInput not in self.validInputs:
            return "invalid move"
        xNew, yNew = self.x, self.y
        if userInput == 'w' or userInput == 'W':
            xNew = max(self.x - 1, 0)
        elif userInput == 's' or userInput == 'S':
            xNew = min(self.x + 1, numberOfRow)
        elif userInput == 'a' or userInput == 'A':
            yNew = max(self.y - 1, 0)
        elif userInput == 'd' or userInput == 'D':
            yNew = min(self.y + 1, numberOfCol)
        else:
            return "game over"
        return (xNew, yNew)

class Pacman(Person):
    def __init__(self, pts):
        Person.__init__(self)
        self.look = WARNING + 'P'+ ENDC
        self.alive = True
        self.points = pts

class Ghost(Person):
    def __init__(self):
        Person.__init__(self)
        self.look = FAIL + 'G' + ENDC

class Game:
    def __init__(self):
        self.row = numberOfRow
        self.col = numberOfCol
        self.coins = coinNum
        self.walls = wallNum
        self.numberOfGhosts = ghostNum
        self.render(0, self.numberOfGhosts)

    def render(self, pts, gNum):
        self.map = [['.' for j in range (self.col)] for i in range(self.row)]
        self.placeWalls()
        self.pacman = Pacman(pts)
        self.pacman.x, self.pacman.y = self.ptGenerate()
        self.map[self.pacman.x][self.pacman.y] = self.pacman.look
        self.ghost = [Ghost() for x in range(self.numberOfGhosts)]
        self.placeGhost()
        self.placeCoins()

    def movePacman(self, mv):
        newLocation = self.pacman.move(mv)
        if newLocation == "game over":
            self.pacman.alive = False
        elif newLocation == "invalid move":
            print "Invalid Move!"
            return
        xNew, yNew = newLocation
        try:
            if self.map[xNew][yNew] == '.':
                self.map[xNew][yNew] = self.pacman.look
                self.map[self.pacman.x][self.pacman.y] = '.'
                self.pacman.x, self.pacman.y = xNew, yNew
            elif self.map[xNew][yNew] == OKBLUE + 'C' + ENDC:
                self.collectCoin(xNew, yNew)
                self.map[xNew][yNew] = self.pacman.look
                self.map[self.pacman.x][self.pacman.y] = '.'
                self.pacman.x, self.pacman.y = xNew, yNew
            elif self.map[xNew][yNew] == FAIL + 'G' + ENDC:
                self.pacman.alive = False
        except IndexError:
            pass

    def moveGhosts(self):
        ghostMoveList = ['w', 'a', 's', 'd']
        for ghost in self.ghost:
            newLocation = ghost.move(choice(ghostMoveList))
            xNew, yNew = newLocation
            try:
                if self.map[xNew][yNew] == '.':
                    self.map[xNew][yNew] = ghost.look
                    self.map[ghost.x][ghost.y] = '.'
                    ghost.x, ghost.y = xNew, yNew
                elif self.map[xNew][yNew] == self.pacman.look:
                    self.pacman.alive = False
            except IndexError:
                pass

    def collectCoin(self, x, y):
        self.pacman.points += 1
        self.coinLocations.remove((x, y))
    
    def checkGhost(self):
        for ghost in self.ghost:
            if self.map[ghost.x][ghost.y] == self.pacman.look:
                return True
        return False

    def ghostPosition(self):
        self.ghostLocations = []
        for ghost in self.ghost:
            self.ghostLocations.append((self.ghost.x, self.ghost.y))
        return self.ghostLocations

    def checkWall(self, x, y):
        return self.map[x][y] == OKGREEN + 'X' + ENDC

    def placeWalls(self):
        for i in range(self.walls/3):
            direction = randint(0, 1)
            xStart, yStart = self.ptGenerate()
            if direction == 0:
                yEnd = self.yGenerate()
                for yVal in range(min(yStart, yEnd), max(yStart, yEnd)):
                    self.map[xStart][yVal] = OKGREEN + 'X' + ENDC
            else:
                xEnd = self.xGenerate()
                for xVal in range(min(xStart, xEnd), max(xStart, xEnd)):
                    self.map[xVal][yStart] = OKGREEN + 'X' + ENDC

    def placeGhost(self):
        for ghost in self.ghost:
            xLoc, yLoc = self.ptGenerate()
            while self.map[xLoc][yLoc] != '.':
                xLoc, yLoc = self.ptGenerate()
            ghost.x, ghost.y = xLoc, yLoc
            self.map[xLoc][yLoc] = ghost.look

    def placeCoins(self):
        self.coinLocations = []
        for i in range(self.coins):
            xLoc, yLoc = self.ptGenerate()
            while self.map[xLoc][yLoc] != '.':
                xLoc, yLoc = self.ptGenerate()
            self.map[xLoc][yLoc] = OKBLUE + 'C' + ENDC
            self.coinLocations.append((xLoc, yLoc))

    def ptGenerate(self):
        return [self.xGenerate(), self.yGenerate()]

    def xGenerate(self):
        return randint(0, self.row - 1)

    def yGenerate(self):
        return randint(0, self.col - 1)

    def show(self):
        for i in range(self.row):
            for j in range(self.col):
                print self.map[i][j],
            print

    def play(self):
        while self.pacman.points < self.coins and self.pacman.alive:
            os.system('clear')
            self.show()
            print "Score: ", self.pacman.points
            print "Pacman at " + str(self.pacman.x + 1) + " down and " + str(self.pacman.y + 1) + " right."
            mov = raw_input("Enter Move: ")
            if mov == 'q' or mov == 'Q':
                print "Game quit by player."
                return
            self.movePacman(mov)
            if mov in self.pacman.validInputs:
                self.moveGhosts()
        if self.pacman.points == self.coins:
            print "Good Job! Keep playing! :)"
            self.numberOfGhosts += 2
            self.render(self.coins, self.numberOfGhosts)
            self.coins += self.coins
            self.play()
        elif not self.pacman.alive:
            print "Player loses at " + str(self.pacman.x + 1) + " down and " + str(self.pacman.y + 1) + " right :("

Game().play()
