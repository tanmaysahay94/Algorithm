#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
#define QUEEN 2
#define WHITE 0
#define BLACK 1
#define STRIKER 3

// Function Declarations
void drawScene();
void drawLine();
void update(int);
void scoreUpdate(int);
void drawCircle(double);
void drawCoin(double);
void drawPocket(double, double, double);
void drawRail(double, double, double, double);
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
vector<double> colorArg(string&);
void myColor3f(vector<double>&);
bool moveCompleted();
double distance(double, double, double, double);
void placement(int);
string toString(int);
void writeScore(double, double, string, void*, string);
bool turnComplete(bool);

// Global variables
double circle_rad = 0.5f;
double Board_len = 3.5f;
double vel = 0.0f;
double epsilon = 0.00001f;
double restitution = 0.9f;
int theta = 90;
bool play = false;
bool turn = false;
bool pocketed_in_current_turn = false;
bool striker_pocketed_in_current_turn = false;
bool canShoot = true;
bool gameOver = false;
bool flag[21][21];
double pocket_loc = 1.58f;
double pocket_rad = circle_rad/3.0f;

class Player {
	int score, type, noMoreMoves;
	public:
	Player(int score_, int type_): score(score_), type(type_) {
		noMoreMoves = 0;
	}
	int getScore() {
		return this->score;
	}
	void increment(int val) {
		score += val;
	}
	void update(int hit_type) {
		if (hit_type == this->type) {
			increment(10);
		}
		else if (hit_type == QUEEN) {
			increment(50);
		}
		else if (hit_type != STRIKER) {
			increment(-5);
		}
		else {
			return;
		}
	}
	void done() {
		noMoreMoves = 1;
	}
	bool gameComplete() {
		return noMoreMoves;
	}
};

vector<Player> players;

class Coin {
	public:
		double friction;
		double radius;
		double x, y;
		double velx, vely;
		double ax, ay;
		double mass;
		bool pocketed;
		int type;
		string coin_color;
		Coin(double X, double Y, double rad_, int type_, string coin_color_, double mass_) {
			x = X;
			y = Y;
			radius = rad_;
			type = type_;
			pocketed = false;
			coin_color = coin_color_;
			mass = mass_;
			velx = vely = 0.0f;
		}
		double getMass() {
			return this->mass;
		}
		void setx(double x) {
			this->x = x;
		}
		void sety(double y) {
			this->y = y;
		}
		void setxvel(double x) {
			this->velx = x;
		}
		void setyvel(double y) {
			this->vely = y;
		}
		double getxvel() {
			return this->velx;
		}
		double getyvel() {
			return this->vely;
		}
		pair<double, double> getLocation() {
			return make_pair(this->x, this->y);
		}
		pair<double, double> getVelocity() {
			return make_pair(this->velx, this->vely);
		}
		int getType() {
			return this->type;
		}
		double getRadius() {
			return this->radius;
		}
		bool isPocketed() {
			return this->pocketed;
		}
		string getCoinColor() {
			return this->coin_color;
		}
		void setCoinColor(string color) {
			this->coin_color = color;
		}
		void unpocket() {
			pocketed = false;
		}
		void checkWall() {
			if ((x + radius > Board_len/2 and velx > 0) or (x - radius + Board_len/2 <= epsilon and velx < 0)) {
				velx *= -restitution;
			}
			if ((y + radius > Board_len/2 and vely > 0) or (y - radius + Board_len/2 <= epsilon and vely < 0)) {
				vely *= -restitution;
			}
		}
		void move() {
			friction = -0.0006;
			if (type == 3) {
				friction *= 2;
			}
			ax = friction*velx;
			ay = friction*vely;
			double mod = sqrt(velx*velx + vely*vely);
			if (mod) {
				ax /= mod;
				ay /= mod;
			}
			x += velx, y += vely;
			velx += ax, vely += ay;
			if (velx*velx + vely*vely < epsilon) {
				velx = vely = 0.0f;
			}
			if (distance(x, y, pocket_loc, pocket_loc) < pocket_rad or distance(x, y, pocket_loc, -pocket_loc) < pocket_rad or distance(x, y, -pocket_loc, pocket_loc) < pocket_rad or distance(x, y, -pocket_loc, -pocket_loc) < pocket_rad) {
				if (velx*velx + vely*vely <= 0.05) {
					velx = vely = 0.0f;
					if (type != STRIKER) {
						pocketed = true;
						if (type == turn or type == QUEEN) {
							pocketed_in_current_turn = true;
						}
					}
					else {
						pocketed = true;
						striker_pocketed_in_current_turn = true;
					}
					players[turn].update(type);
				}
			}
		}
		void draw() {
			glPushMatrix();
			glTranslatef(getLocation().first, getLocation().second, 0.0f);
			string hexcode = getCoinColor();
			vector<double> colors = colorArg(hexcode);
			myColor3f(colors);
			drawCoin(getRadius());
			glPopMatrix();
		}
};

class Board {
	double len;
	public:
	pair<pair<double, double>, pair<double, double> > up, down, left, right;
	vector<Coin> coins;
	Board(double len_): len(len_) {
		// 4 striker positioning lines
		down = make_pair(make_pair(-1.17f, -1.25f), make_pair(1.17f, -1.25f));
		up = make_pair(make_pair(-1.17f, 1.25f), make_pair(1.17f, 1.25f));
		left = make_pair(make_pair(-1.25, -1.17f), make_pair(-1.25f, 1.17f));
		right = make_pair(make_pair(1.25f, -1.17f), make_pair(1.25f, 1.17f));

		// insert queen
		coins.push_back(Coin(0.0f, 0.0f, 0.07f, QUEEN, string("ff0000"), 1));

		// insert white coins
		for (int i = 1; i <= 10; i++)
			coins.push_back(Coin(0.25f * cos(DEG2RAD(36 * i)), 0.25f * sin(DEG2RAD(36 * i)), 0.07f, WHITE, string("ffffff"), 1));

		// insert black coins
		for (int i = 11; i <= 20; i++)
			coins.push_back(Coin(0.4f * cos(DEG2RAD(36 * i)), 0.4f * sin(DEG2RAD(36 * i)), 0.07f, BLACK, string("000000"), 1));

		// insert striker	
		coins.push_back(Coin((down.first.first + down.second.first)/2, (down.second.second + down.first.second)/2 + 0.1f, 0.1f, STRIKER, string("00ff00"), 2));
	}
	void setLen(double len_) {
		this->len = len_;
	}
	double getLen() {
		return this->len;
	}
};

// more func. declarations
void drawBoard(Board&);
void checkCollision(Coin&, Coin&, bool&);

// Global Variables
Board gameBoard = Board(Board_len);

string toString(int val, int p) {
	bool neg = false;
	if (val < 0)
		neg = true, val *= -1;
	string ret = "";
	string tmp = "Player ";
	tmp += p + '0';
	tmp += ": ";
	while (val) {
		ret += (val%10) + '0';
		val /= 10;
	}
	int len = ret.length();
	for (int i = 0; i < len/2; i++)
		swap(ret[i], ret[len - i - 1]);
	if (neg)
		ret = string("-") + ret;
	return tmp + ret;
}

string genericToString(int val) {
	bool neg = false;
	if (val < 0)
		neg = true, val *= -1;
	string ret = "";
	while (val) {
		ret += (val%10) + '0';
		val /= 10;
	}
	int len = ret.length();
	for (int i = 0; i < len/2; i++)
		swap(ret[i], ret[len - i - 1]);
	if (neg)
		ret = string("-") + ret;
	return ret;
}

double distance(double ax, double ay, double bx, double by) {
	return sqrt((bx - ax)*(bx - ax) + (by - ay)*(by - ay));
}

vector<double> colorArg(string& hexcode) {
	vector<double> ret(3);
	int hexval;
	for (int i = 0; i < 3; ++i) {
		hexval = 0;
		for (int j = 0; j < 2; ++j) {
			char val = hexcode[2*i + j];
			int num;
			if (val >= '0' and val <= '9')
				num = val - '0';
			else if (val >= 'A' and val <= 'F')
				num = val - 'A' + 10;
			else if (val >= 'a' and val <= 'f')
				num = val - 'a' + 10;
			if (not j)
				hexval = num << 4;
			else
				hexval += num;
		}
		ret[i] = ((double) hexval)/255.0f;
	}
	return ret;
}

void myColor3f(vector<double>& col) {
	glColor3f(col[0], col[1], col[2]);
}

int main(int argc, char **argv) {
	// Initialize player(s)
	players.push_back(Player(30, WHITE));
	players.push_back(Player(30, BLACK));

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	int windowWidth = w * 2 / 3;
	int windowHeight = h * 2 / 3;

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

	// Setup the window
	glutCreateWindow("Let's play a game. A game of Carrom! xD");
	initRendering();

	// Register callbacks
	if (gameBoard.coins[0].pocketed and players[WHITE].gameComplete() and players[BLACK].gameComplete()) {
		gameOver = true;
	}

	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress1);
	glutSpecialFunc(handleKeypress2);
	glutMouseFunc(handleMouseclick);
	glutReshapeFunc(handleResize);
	glutTimerFunc(10, update, 0);
	glutTimerFunc(1000, scoreUpdate, 0);
	glutMainLoop();
	return 0;
}

// Function to draw objects on the screen
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if (not gameOver) {
		string color1 = "ffcb30";
		string color2 = "b32e87";
		void* font = GLUT_BITMAP_HELVETICA_18;

		// Draw Board
		glTranslatef(0.0f, 0.0f, -5.0f);
		drawBoard(gameBoard);

		// Writing scores
		writeScore(2.1f, -1.5f, color1, font, toString(players[0].getScore(), 1));
		writeScore(2.1f, 1.5f, color2, font, toString(players[1].getScore(), 2));

		string hexcode;
		vector<double> colors;

		// Draw queen, white and black coins
		for (int i = 0; i < 21; ++i) {
			if (gameBoard.coins[i].pocketed)
				continue;
			gameBoard.coins[i].draw();
		}

		// Draw striker
		if (not play or (play and not gameBoard.coins[21].isPocketed()))
			gameBoard.coins[21].draw();

		// Draw line depicting shot direction and power
		drawLine();
	}
	else {
		void* font = GLUT_BITMAP_HELVETICA_18;
		string color, message = "Player ";
		if (players[0].getScore() > players[1].getScore()) {
			message += string("1 wins with ") + genericToString(players[0].getScore());
			if (abs(players[0].getScore()) == 1) {
				message += string(" point! :)");
			}
			else {
				message += string(" points! :)");
			}
			color = "ffcb30";
		}
		else if (players[0].getScore() < players[1].getScore()) {
			message += string("2 wins with ") + genericToString(players[1].getScore());
			if (abs(players[1].getScore()) == 1) {
				message += string(" point! :)");
			}
			else {
				message += string(" points! :)");
			}
			color = "b32e87";
		}
		else {
			message = "Tie! :O";
			color = "000000";
		}
		glTranslatef(0.0f, 0.0f, -2.0f);
		writeScore(0.0f, 0.0f, color, font, message);
	}

	glPopMatrix();
	glutSwapBuffers();
}

void writeScore(double x, double y, string color, void* font, string toPrint) {
	vector<double> lePrintColor = colorArg(color);
	myColor3f(lePrintColor);
	glRasterPos2f(x, y);
	for (int i = 0; toPrint[i]; i++) {
		glutBitmapCharacter(font, toPrint[i]);
	}
}

void drawLine() {
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(1.618f);
	glBegin(GL_LINES);
	double xPos = gameBoard.coins[21].getLocation().first;
	double yPos = gameBoard.coins[21].getLocation().second;
	glVertex2f(xPos, yPos);
	double xFinal = xPos + vel*15*cos(DEG2RAD(theta));
	double yFinal = yPos + vel*15*sin(DEG2RAD(theta));
	double len = gameBoard.getLen();
	double xLow = -len/2;
	double xHigh = -xLow;
	double yLow = xLow;
	double yHigh = xHigh;
	double xDest = min(max(xLow, xFinal), xHigh);
	double yDest = min(max(yLow, yFinal), yHigh);
	glVertex2f(xDest, yDest);
	glVertex2f(0.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void scoreUpdate(int value) {
	if (not gameOver) {
		players[turn].increment(-1);
		glutTimerFunc(1000, scoreUpdate, 0);
	}
}

// Function to handle all calculations in the scene
// updated every 10 milliseconds
void update(int value) {
	if (gameBoard.coins[0].pocketed and players[WHITE].gameComplete() and players[BLACK].gameComplete()) {
		gameOver = true;
	}
	if (not players[WHITE].gameComplete() and turnComplete(WHITE)) {
		players[WHITE].done();
	}
	if (not players[BLACK].gameComplete() and turnComplete(BLACK)) {
		players[BLACK].done();
	}
	if (moveCompleted() and play) {
		gameBoard.coins[21].unpocket();
		canShoot = true;
		gameBoard.coins[21].setCoinColor(string("00ff00"));
		gameBoard.coins[21].setx(0.0f);
		if (not players[WHITE].gameComplete() and turnComplete(WHITE)) {
			players[WHITE].done();
		}
		if (not players[BLACK].gameComplete() and turnComplete(BLACK)) {
			players[BLACK].done();
		}
		if (gameBoard.coins[0].pocketed and players[WHITE].gameComplete() and players[BLACK].gameComplete()) {
			gameOver = true;
			return;
		}
		bool stayTheSame = pocketed_in_current_turn and not striker_pocketed_in_current_turn;
		bool a = gameBoard.coins[0].pocketed;
		bool b = players[WHITE].gameComplete();
		bool c = players[BLACK].gameComplete();
		if (not stayTheSame) {
			if (!a&&!b&&!c) {
				turn = not turn;
			}
			else if (!a&&!b&&c) {
				turn = not turn;
			}
			else if (!a&&b&&!c) {
				turn = not turn;
			}
			else if (!a&&b&&c) {
				turn = not turn;
			}
			else if (a&&!b&&!c) {
				turn = not turn;
			}
			else if (a&&!b&&c) {
				turn = WHITE;
			}
			else if (a&&b&&!c) {
				turn = BLACK;
			}
			else {
				gameOver = true;
			}
		}
		else {
			if (a&&!b&&c) {
				turn = 0;
			}
			else if (a&&b&&!c) {
				turn = 1;
			}
			else if (a&&b&&c) {
				gameOver = true;
			}
		}
		striker_pocketed_in_current_turn = pocketed_in_current_turn = false;
		if (not turn)
			gameBoard.coins[21].sety((gameBoard.down.second.second + gameBoard.down.first.second)/2 + 0.1f);
		else
			gameBoard.coins[21].sety((gameBoard.up.second.second + gameBoard.up.first.second)/2 - 0.1f);
		gameBoard.coins[21].move();
		play = false;
		glutTimerFunc(10, update, 0);
		return;
	}
	if (gameBoard.coins[0].pocketed and players[1].gameComplete() and players[0].gameComplete()) {
		gameOver = true;
	}
	for (int i = 0; i < 22; i++) {
		if (not gameBoard.coins[i].pocketed) {
			if ((i == 21 and canShoot) or i != 21) {
				for (int j = i + 1; j < 22; j++) {
					if (not gameBoard.coins[j].pocketed) {
						if ((j == 21 and canShoot) or j != 21) {
							checkCollision(gameBoard.coins[i], gameBoard.coins[j], flag[i][j]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 22; i++)
		gameBoard.coins[i].checkWall();
	gameBoard.coins[21].move();
	for (int i = 0; i < 22; i++) {
		if (not gameBoard.coins[i].pocketed) {
			gameBoard.coins[i].move();
		}
	}
	glutTimerFunc(10, update, 0);
}

void checkCollision(Coin& a, Coin& b, bool& fl) {
	double ax = a.getLocation().first;
	double ay = a.getLocation().second;
	double bx = b.getLocation().first;
	double by = b.getLocation().second;
	double dx = bx - ax;
	double dy = by - ay;
	double l = sqrt(dx*dx + dy*dy);
	double cosine = dx/l;
	double sine = dy/l;
	double arad = a.getRadius();
	double brad = b.getRadius();
	double diff = (arad + brad) - l;
	if (diff > epsilon) {
		if (ax < bx) {
			ax -= (diff/2) * (fabs(cosine));
			bx += (diff/2) * (fabs(cosine));
		}
		else {
			bx -= (diff/2) * (fabs(cosine));
			ax += (diff/2) * (fabs(cosine));
		}
		if (ay < by) {
			ay -= (diff/2) * (fabs(sine));
			by += (diff/2) * (fabs(sine));
		}
		else {
			ay += (diff/2) * (fabs(sine));
			by -= (diff/2) * (fabs(sine));
		}
	}
	a.setx(ax), a.sety(ay);
	b.setx(bx), b.sety(by);
	if (l >= arad + brad - epsilon) {
		fl = false;
		return;
	}
	if (fl) {
		return;
	}

	double uax, ubx, vax, vbx, vay, vby;
	double avelX = a.getxvel();
	double avelY = a.getyvel();
	double bvelX = b.getxvel();
	double bvelY = b.getyvel();

	uax = avelX*cosine + avelY*sine;         // initial vel of coin 'a' along line of centers
	vay = avelX*(-sine) + avelY*cosine;      // initial vel of coin 'a' perpendicular to line of centers

	ubx = bvelX*cosine + bvelY*sine;         // initial vel of coin 'b' along line of centers
	vby = bvelX*(-sine) + bvelY*cosine;      // initial vel of coin 'b' perpendicular to line of centers

	double am = a.getMass();
	double bm = b.getMass();

	vax = (am*uax + bm*ubx + bm*(ubx-uax)*restitution) / (am + bm);
	vbx = (am*uax + bm*ubx + am*(uax-ubx)*restitution) / (am + bm);

	avelX = vax*(cosine) + vay*(-sine);       // the final velocities of 'a' are calculated
	avelY = vax*(sine) + vay*(cosine);

	bvelX = vbx*(cosine) + vby*(-sine);       // the final velocities of 'b' are calculated
	bvelY = vbx*(sine) + vby*(cosine);

	a.setxvel(avelX), b.setxvel(bvelX);
	a.setyvel(avelY), b.setyvel(bvelY);

	fl = true;
	if(fabs(avelX) <= -1) {
		a.setxvel(0.0f);
	}
	if(fabs(avelY) <= -1) {
		a.setyvel(0.0f);
	}
	if(fabs(bvelX) <= -1) {
		b.setxvel(0.0f);
	}
	if(fabs(bvelY) <= -1) {
		b.setyvel(0.0f);
	}
}

void drawBoard(Board& gameBoard) {
	// drawing outer rail
	string hexcode = "472000";
	vector<double> tmp = colorArg(hexcode);
	myColor3f(tmp);
	double len = gameBoard.getLen();
	double outer_boundary_len = len + 0.5f;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-outer_boundary_len / 2, -outer_boundary_len / 2);
	glVertex2f(outer_boundary_len / 2, -outer_boundary_len / 2);
	glVertex2f(outer_boundary_len / 2, outer_boundary_len / 2);
	glVertex2f(-outer_boundary_len / 2, outer_boundary_len / 2);
	glEnd();

	// drawing playing Board
	hexcode = "FFAB78";
	tmp = colorArg(hexcode);
	myColor3f(tmp);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(-len / 2, -len / 2);
	glVertex2f(len / 2, -len / 2);
	glVertex2f(len / 2, len / 2);
	glVertex2f(-len / 2, len / 2);
	glEnd();
	glLineWidth(1.618f);
	hexcode = "aa0000";
	tmp = colorArg(hexcode);
	myColor3f(tmp);
	glBegin(GL_LINES);
	glVertex2f(gameBoard.down.first.first, gameBoard.down.first.second);
	glVertex2f(gameBoard.down.second.first, gameBoard.down.second.second);
	glVertex2f(gameBoard.up.first.first, gameBoard.up.first.second);
	glVertex2f(gameBoard.up.second.first, gameBoard.up.second.second);
	glVertex2f(gameBoard.left.first.first, gameBoard.left.first.second);
	glVertex2f(gameBoard.left.second.first, gameBoard.left.second.second);
	glVertex2f(gameBoard.right.first.first, gameBoard.right.first.second);
	glVertex2f(gameBoard.right.second.first, gameBoard.right.second.second);
	glEnd();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	hexcode = "aa0000";
	tmp = colorArg(hexcode);
	myColor3f(tmp);
	drawCircle(circle_rad);
	glPopMatrix();

	// Drawing 4 carrom positioning areas
	double rail_len = 1.15f;
	drawRail(rail_len, rail_len, 0.0f, circle_rad/5);
	drawRail(rail_len, -rail_len, 0.0f, circle_rad/5);
	drawRail(-rail_len, rail_len, 0.0f, circle_rad/5);
	drawRail(-rail_len, -rail_len, 0.0f, circle_rad/5);
	
	// drawing 4 pockets
	hexcode = "c27538";
	tmp = colorArg(hexcode);
	myColor3f(tmp);
	double sz = 1.58f;
	drawPocket(sz, sz, 0.0f);
	drawPocket(sz, -sz, 0.0f);
	drawPocket(-sz, sz, 0.0f);
	drawPocket(-sz, -sz, 0.0f);
}

void drawRail(double x, double y, double z, double rad) {
	glPushMatrix();
	glTranslatef(x, y, z);
	drawCircle(rad);
	glPopMatrix();
}

void drawPocket(double x, double y, double z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	drawCoin(pocket_rad);
	glPopMatrix();
}

void drawCoin(double rad) {
	glBegin(GL_TRIANGLE_FAN);
	for(int i = 0 ; i < 360 ; i++) {
		glVertex2f(rad * cos(DEG2RAD(i)), rad * sin(DEG2RAD(i)));
	}
	glEnd();
}

void drawCircle(double rad) {
	glBegin(GL_LINE_LOOP);
	int sides = 180;
	for (int a = 0; a < 360; a += 360 / sides) {
		double heading = a * 3.1415926535897932384626433832795 / 180;
		glVertex2d(cos(heading) * rad, sin(heading) * rad);
	}
	glEnd();
}

// Initializing some openGL 3D rendering options
void initRendering() {
	glEnable(GL_DEPTH_TEST);        		// Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    		// Enable coloring
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   // Setting a background color
}

// Function called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (double)w / (double)h, 0.1f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) {
	int factor = turn ? -1 : 1;
	if (key == 27) {
		exit(0);     // escape key is pressed
	}
	else if (key == 'a' or key == 'A') {
		theta += factor * 1;
	}
	else if (key == 'c' or key == 'C') {
		theta -= factor * 1;
	}
	else if (key == ' ' and canShoot) {
		gameBoard.coins[21].setxvel(vel*cos(DEG2RAD(theta)));
		gameBoard.coins[21].setyvel(vel*sin(DEG2RAD(theta)));
		theta = 90;
		vel = 0;
		play = true;
	}
}

void handleKeypress2(int key, int x, int y) {
	if (play) {
		return;
	}
	if (key == GLUT_KEY_LEFT) {
		placement(0);
	}
	else if (key == GLUT_KEY_RIGHT) {
		placement(1);
	}
	else if (key == GLUT_KEY_UP) {
		if (turn == 0)
			if (vel < 0.2)
				vel += 0.004f;
		if (turn == 1)
			if (vel > -0.2)
				vel -= 0.004f;
	}
	else if (key == GLUT_KEY_DOWN) {
		if (turn == 0)
			if (vel > 0.0)
				vel -= 0.004f;
		if (turn == 1)
			if (vel < 0.0)
				vel += 0.004f;
	}
}

void handleMouseMotion(int x, int y) {
	double w = (double)glutGet(GLUT_WINDOW_WIDTH);
	double h = (double)glutGet(GLUT_WINDOW_HEIGHT);

	double r = w/h;
	double factor = 2.08f;
	double newx = (((double)x/w)*2.0 - 1.0 )*factor*r;
	double newy = (((double)y/h)*2.0 - 1.0 )*factor*-1.0;
	double striker_x = gameBoard.coins[21].getLocation().first;
	double striker_y = gameBoard.coins[21].getLocation().second;
	double striker_rad = gameBoard.coins[21].getRadius();

	if (newy > striker_y + striker_rad or newy < striker_y - striker_rad or newx > striker_x + striker_rad or newx < striker_x - striker_rad) {
		return;
	}
	if (newx >= -1.17f and newx <= 1.17f) {
		if (newx > striker_x) {
			placement(1);
		}
		else {
			placement(0);
		}
	}
}

void handleMouseclick(int button, int state, int x, int y) {
	// convert x, y to X, Y of my reference frame
	if(play)
		return;

	double w = (double)glutGet(GLUT_WINDOW_WIDTH);
	double h = (double)glutGet(GLUT_WINDOW_HEIGHT);

	double r = w/h;
	double factor = 2.08f;
	double newx = (((double)x/w)*2.0 - 1.0 )*factor*r;
	double newy = (((double)y/h)*2.0 - 1.0 )*factor*-1.0;
	double striker_x = gameBoard.coins[21].getLocation().first;
	double striker_y = gameBoard.coins[21].getLocation().second;

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		glutMotionFunc(handleMouseMotion);
	}
	if (button == GLUT_LEFT_BUTTON && state == 1) {
		if (newx > 1.7f or newx < -1.7f) {
			return;
		}
		if (newy > 1.7f or newy < -1.7f) {
			return;
		}
		double dist = distance(newx, newy, striker_x, striker_y);
		double v = dist/15.0f;
		if (v > 0.2f) {
			v = 0.2f;
		}
		double cosine = (newx - striker_x) / dist;
		double sine = (newy - striker_y) / dist;
		gameBoard.coins[21].setxvel(v * cosine);
		gameBoard.coins[21].setyvel(v * sine);
		vel = 0;
		theta = 90;
		play = 1;
	}
}

bool moveCompleted() {
	for (int i = 0; i < 22; i++) {
		double xvel = gameBoard.coins[i].getxvel();
		double yvel = gameBoard.coins[i].getyvel();
		if (xvel * xvel + yvel * yvel > epsilon)
			return false;
	}
	return true;
}

bool turnComplete(bool player) {
	for (int i = 10 * player + 1; i <= 10 * (player + 1); i++) {
		if (not gameBoard.coins[i].isPocketed()) {
			return false;
		}
	}
	return true;
}

void placement(int direction) {
	bool shoot = true;
	double delta = 0.02f;
	double striker_x = gameBoard.coins[21].getLocation().first;
	if (direction) {
		striker_x += delta;
	}
	else {
		striker_x -= delta;
	}
	striker_x = max(min((double)1.15, striker_x), (double)-1.15);
	double striker_y = gameBoard.coins[21].getLocation().second;
	double striker_rad = gameBoard.coins[21].getRadius();
	for (int i = 0; i < 21; i++) {
		double x = gameBoard.coins[i].getLocation().first;
		double y = gameBoard.coins[i].getLocation().second;
		double rad = gameBoard.coins[i].getRadius();
		if (distance(striker_x, striker_y, x, y) < striker_rad + rad) {
			shoot = false;
			break;
		}
	}
	gameBoard.coins[21].setx(striker_x);
	gameBoard.coins[21].sety(striker_y);
	canShoot = shoot;
	if (not canShoot) {
		gameBoard.coins[21].setCoinColor(string("ff8000"));
	}
	else {
		gameBoard.coins[21].setCoinColor(string("00ff00"));
	}	
}
