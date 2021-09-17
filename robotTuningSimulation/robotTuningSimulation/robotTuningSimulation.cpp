// robotTuningSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

float M_PI = 3.1415926535;

float calcMag(float x, float y) {
	return sqrtf(x * x + y * y);
}

float angleDiff1(float tangle, float target)
{
	float angle1 = tangle;
	float angle2 = target;
	if (angle1 <= M_PI / 2) {
		angle1 = M_PI / 2 - angle1;
	}
	else {
		angle1 = 5 * M_PI / 2 - angle1;
	}
	if (angle2 <= M_PI / 2) {
		angle2 = M_PI / 2 - angle2;
	}
	else {
		angle2 = 5 * M_PI / 2 - angle2;
	}
	return angle2 - angle1 + M_PI / 2;
}

class Robot {
public:
	float currTime;

	vector<float> positionTrack;
	vector<float> velocityTrack;


	Robot(vector <float> startPos, vector <float> startVel, float motorErr, float frictionErr, float friction, float maximumVel) {
		positionTrack = startPos;
		velocityTrack = startVel;

		motorErrRange = motorErr;
		frictionErrRange = frictionErr;
		frictionConst = friction;

		maxVel = maximumVel;
		unitTime = 0.01;

		currTime = 0;
	}

	void updatePosition(float motor1, float motor2) {
		float accInstX;
		float accInstY;
		float magAcc;
		float fricMagAcc;

		float accTL = motor1 + genRandom(motorErrRange);
		float accBL = motor2 + genRandom(motorErrRange);
		float accTR = motor2 + genRandom(motorErrRange);
		float accBR = motor1 + genRandom(motorErrRange);

		accInstX = sqrtf(2) * (accTL + accBR - accBL - accTR);
		accInstY = sqrtf(2) * (accTL + accBR + accBL + accTR);
		magAcc = calcMag(accInstX, accInstY);

		velocityTrack[0] += accInstX;
		velocityTrack[1] += accInstY;
		if (calcMag(velocityTrack[0], velocityTrack[1]) > maxVel) {
			velocityTrack[0] *= maxVel / calcMag(velocityTrack[0], velocityTrack[1]);
			velocityTrack[1] *= maxVel / calcMag(velocityTrack[0], velocityTrack[1]);
		}

		fricMagAcc = frictionConst + genRandom(frictionErrRange);
		float coefficient = (calcMag(velocityTrack[0], velocityTrack[1]) - fricMagAcc) / calcMag(velocityTrack[0], velocityTrack[1]);
		if (coefficient < 0) {
			coefficient = 0;
		}
		velocityTrack[0] *= coefficient;
		velocityTrack[1] *= coefficient;

		positionTrack[0] += unitTime * velocityTrack[0];
		positionTrack[1] += unitTime * velocityTrack[1];

		currTime += unitTime;
	}

private:
	float motorErrRange;
	float frictionErrRange;
	float frictionConst;

	float maxVel;
	float unitTime;

	float genRandom(float errRange) {
		float a = rand();
		return 2 * (a / RAND_MAX) * errRange - errRange;
	}
};

int main()
{
	ofstream outFile;
	outFile.open("C:\\Users\\Yao\\source\\repos\\robotTuningSimulation\\robotTuningSimulation\\positionOut.csv", ios::trunc);
	outFile << "time,positionX,positionY\n";

	vector <float> targetPos = { 120, 24 };
	Robot robot({ 0, 0 }, { 0, 0 }, 0.1, 0.2, 2, 10);
	float scalar;
	float error;
	float angleHeading;

	while (calcMag(targetPos[0] - robot.positionTrack[0], targetPos[1] - robot.positionTrack[1]) > 1) {
		scalar = 1 - 1 / (exp(calcMag(targetPos[0] - robot.positionTrack[0], targetPos[1] - robot.positionTrack[1]) / 3 - 4) + 1);
		if (scalar > 5) {
			scalar = 5;
		}

		error = atan2(targetPos[1] - robot.positionTrack[1], targetPos[0] - robot.positionTrack[0]);
		if (error >= 0) {
			if (error <= M_PI) {
				error = M_PI / 2 - error;
			}
			else {
				error = 5 * M_PI / 2 - error;
			}
		}
		else {
			error = M_PI / 2 - error;
		}

		angleHeading = angleDiff1(0, error);

		robot.updatePosition(scalar * sin(angleHeading + M_PI / 4), scalar * sin(angleHeading - M_PI / 4));


		if (int(robot.currTime * 100) % 100 == 0) {
			outFile << robot.currTime << "," << robot.positionTrack[0] << "," << robot.positionTrack[1] << "\n";
			cout << robot.positionTrack[0] << "," << robot.positionTrack[1] << "\n";
		}
	}

	outFile.close();
	return 0;
}
